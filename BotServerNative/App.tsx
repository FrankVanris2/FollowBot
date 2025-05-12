import React, { useCallback, useEffect } from 'react'; // Import useEffect
import { View, Text, Button, Platform, PermissionsAndroid} from 'react-native';
import Geolocation from '@react-native-community/geolocation'; 
import BleManager from 'react-native-ble-manager';
import { styles } from './App.styles';

const FOLLOWBOT_GPS_CHARACTERISTIC = '87654321-4321-8765-4321-0fedcba98765';

type CharacteristicData = {
  peripheral: string;
  serviceUUID: string;
  characteristicUUID: string;
};



type Location = {
  latitude: number;
  longitude: number;
};


const initialize = async (
  setCharacteristicData: (characteristicData: CharacteristicData) => void,
    setLocation: (loc: Location) => void) => {
  await requestPermissions();
  await startBluetooth(setCharacteristicData);
  getCurrentPosition(setLocation);
}

const requestPermissions = async () => {
  if (Platform.OS === 'android') {
    try {
      const granted = await PermissionsAndroid.requestMultiple([
        PermissionsAndroid.PERMISSIONS.ACCESS_COARSE_LOCATION,
        PermissionsAndroid.PERMISSIONS.ACCESS_FINE_LOCATION,
        PermissionsAndroid.PERMISSIONS.BLUETOOTH_SCAN,
        PermissionsAndroid.PERMISSIONS.BLUETOOTH_CONNECT,
      ]);
      if (
        granted['android.permission.ACCESS_COARSE_LOCATION'] === PermissionsAndroid.RESULTS.GRANTED &&
        granted['android.permission.ACCESS_FINE_LOCATION'] === PermissionsAndroid.RESULTS.GRANTED &&
        granted['android.permission.BLUETOOTH_SCAN'] === PermissionsAndroid.RESULTS.GRANTED &&
        granted['android.permission.BLUETOOTH_CONNECT'] === PermissionsAndroid.RESULTS.GRANTED
      ) {
        console.log('Permissions granted');
      } else {
        console.log('Permissions denied');
      }
    } catch (err) {
      console.warn('requestPermissions(), error:', err);
    }
  }
  // On iOS, permissions are handled automatically
};

const startBluetooth = async (setCharacteristicData: (characteristicData: CharacteristicData) => void) => {
  try {
    await BleManager.start();
    const state = await BleManager.checkState();
    console.log('Bluetooth state:', state);

    getFollowBotCharacteristic(setCharacteristicData);

  } catch (error) {  
    console.log('Error starting Bluetooth:', error);
  } 
};

const getFollowBotCharacteristic = async (setCharacteristicData: (characteristicData: CharacteristicData) => void) => {
  const peripherals = await BleManager.getBondedPeripherals();
  console.log('Bonded peripherals:', peripherals);
  const followBotPeripheral = peripherals.find((per) => per.name === 'FollowBot_Proto1');
  if (!followBotPeripheral) {
    console.log('FollowBot Peripheral not found');
    return;
  }
  console.log('FollowBot Peripheral:', followBotPeripheral);
  await BleManager.connect(followBotPeripheral.id);
  console.log('Connected to FollowBot Peripheral');

  const services = await BleManager.retrieveServices(followBotPeripheral.id);
  if (!services) {
    console.log('No services found');
    return;
  }
  console.log('Services:', JSON.stringify(services, null, 2));

  const characteristic = services.characteristics?.find((char: any) => char.characteristic === FOLLOWBOT_GPS_CHARACTERISTIC);
  if (!characteristic) {
    console.log('Characteristic not found');
    return;
  }
  console.log('Characteristic:', characteristic);
  const characteristicData: CharacteristicData = {
    peripheral: followBotPeripheral.id,
    serviceUUID: characteristic.service,
    characteristicUUID: characteristic.characteristic,
  };
  console.log('Characteristic Data:', characteristicData);
  setCharacteristicData(characteristicData);
};

const getCurrentPosition = (setLocation: (loc: Location) => void) => {
  Geolocation.getCurrentPosition(
    (position) => {
      const { latitude, longitude } = position.coords;
      setLocation({ latitude, longitude});
      console.log('Location:', latitude, longitude);
    },
    (error) => {
      console.log('Geolocation error:', error);
    },
    { enableHighAccuracy: false,  // previously true for old gps protocols
      timeout:15000
      //maximumAge:10000  // needed for old gps protocols
    }
  );
};

const sendLocationToFollowBot = async (characteristicData: CharacteristicData, location: Location) => {
  try {
    const byteArray = new Uint8Array(8);
    const dataView = new DataView(byteArray.buffer);
    dataView.setFloat32(0, location.latitude, true);
    dataView.setFloat32(4, location.longitude, true);
  
    await BleManager.write(
      characteristicData.peripheral,
      characteristicData.serviceUUID,
      characteristicData.characteristicUUID,
      Array.from(byteArray),
      byteArray.length);
    console.log('Location sent to FollowBot:', location);
    } catch (error) {
      console.log('Error sending location to FollowBot:', error);
    }
};

const App = () => {
  const [characteristicData, setCharacteristicData] = React.useState<CharacteristicData>();
  const [location, setLocation] = React.useState<Location | null>(null);

  useEffect(() => {
    initialize(setCharacteristicData, setLocation);

    return () => {
      BleManager.stopScan();
    };
  }, []);

  useEffect(() => {
    if (!characteristicData) return;

    setInterval(() => {
      getCurrentPosition(setLocation);

    }, 300);

  }, [characteristicData]);

  useEffect(() => {
    if (!characteristicData || !location) return;

    sendLocationToFollowBot(characteristicData, location);
}, [location]);

  return (
    <View>
      <Button title="Retry connect" onPress={() => getFollowBotCharacteristic(setCharacteristicData)} />

      {/* connectedPeripheral && <Text>Connected to: {connectedPeripheral}</Text> */}
      {location && <Text>Location: {location.latitude}, {location.longitude}</Text>}
    </View>
  );
};

export default App;
