import React, { useEffect } from 'react'; // Import useEffect
import { View, Text, Button, ScrollView, Platform} from 'react-native';
import { Row, Col } from 'react-native-responsive-grid-system';
import Geolocation from '@react-native-community/geolocation';  
import BleManager from 'react-native-ble-manager';
import { PermissionsAndroid } from 'react-native';
import { styles } from './App.styles';

const startBluetooth = async () => {
  try {
    await BleManager.start({ showAlert: false });
    console.log('Bluetooth started');
  } catch (error) {
    console.error('Bluetooth start error:', error);
  }
}

const scanBluetooth = async (isScanning : boolean, setPeripherals: React.Dispatch<React.SetStateAction<Map<string, any>>>) => {
  try {
    if (isScanning) {
      await BleManager.scan([], 15, false);
      const peripherals = await BleManager.getDiscoveredPeripherals();
      const peripheralMap = new Map();
      peripherals.forEach(peripheral => {
        peripheralMap.set(peripheral.id, peripheral);
      });
      setPeripherals(peripheralMap);
      console.log('Discovered peripherals:', peripherals);
    } else {
      await BleManager.stopScan();
    } 
  } catch (error) {
    console.error('Scan error:', error);
  }
}

const App = () => {
  const [isScanning, setIsScanning] = React.useState(false);
  const [peripherals, setPeripherals] = React.useState(new Map());
  const [connectedPeripheral, setConnectedPeripheral] = React.useState<string | null>(null);
  const [location, setLocation] = React.useState<{ latitude: number; longitude: number} | null>(null);

  useEffect(() => {
    startBluetooth();
    requestPermissions();
    getLocation();

    return () => {
      BleManager.stopScan();
    };
  }, []);

  useEffect(() => {
    scanBluetooth(isScanning, setPeripherals);
  }, [isScanning]);


  const getLocation = async () => {
    if (Platform.OS === 'android') {
      try {
        const granted = await PermissionsAndroid.request(PermissionsAndroid.PERMISSIONS.ACCESS_FINE_LOCATION);
        if (granted === PermissionsAndroid.RESULTS.GRANTED) {
          getCurrentPosition();
        } else {
          console.log('Location permission denied');
        }
      } catch (error) {
        console.warn(error);
      }
    } else {
      getCurrentPosition();
    }
  };

  const getCurrentPosition = () => {
    Geolocation.getCurrentPosition(
      (position) => {
        const { latitude, longitude } = position.coords;
        setLocation({ latitude, longitude});
        console.log('Location:', latitude, longitude);
      },
      (error) => {
        console.log('Geolocation error:', error);
      },
      { enableHighAccuracy: true, timeout:15000, maximumAge:10000 }
    );
  };

  const connectToPeripheral = async (peripheralId: string) => {
    try {
      await BleManager.connect(peripheralId);
      console.log('Connected to', peripheralId);
      setConnectedPeripheral(peripheralId);
    } catch (error) {
      console.error('Connection error:', error);
    }
  };

  const renderPeripheralList = () => {
    const peripheralList = Array.from(peripherals.values());

    return peripheralList.map((peripheral) => (
      <Button
        key={peripheral.id}
        title={`Connect to ${peripheral.name || 'Unknown'}`}
        onPress={() => connectToPeripheral(peripheral.id)}
        />
    ));
  };

  const requestPermissions = async () => {
    if (Platform.OS === 'android') {
      try {
        const granted = await PermissionsAndroid.requestMultiple([
          PermissionsAndroid.PERMISSIONS.ACCESS_FINE_LOCATION,
          PermissionsAndroid.PERMISSIONS.BLUETOOTH,
          PermissionsAndroid.PERMISSIONS.BLUETOOTH_ADMIN,
        ]);
        if (
          granted['android.permission.ACCESS_FINE_LOCATION'] === PermissionsAndroid.RESULTS.GRANTED &&
          granted['android.permission.BLUETOOTH_SCAN'] === PermissionsAndroid.RESULTS.GRANTED &&
          granted['android.permission.BLUETOOTH_CONNECT'] === PermissionsAndroid.RESULTS.GRANTED
        ) {
          console.log('Permissions granted');
        } else {
          console.log('Permissions denied');
        }
      } catch (err) {
        console.warn(err);
      }
    }
    // On iOS, permissions are handled automatically
  };

  return (
    <Row>
      <Col xs={12} sm={4} md={4} lg={4}>
        <Button title='Scan' onPress={() => setIsScanning(true)} />
        <View>
          <Text style={styles.header}>{isScanning ? 'Scanning' : ''}</Text>
        </View>
        <ScrollView>{renderPeripheralList()}</ScrollView>
        {connectedPeripheral && <Text>Connected to: {connectedPeripheral}</Text>}
        {location && <Text>Location: {location.latitude}, {location.longitude}</Text>}
      </Col>
      <Col xs={12} sm={4} md={4} lg={4}>
        <View><Text style={styles.header}>Column 2</Text></View>
      </Col>
      <Col xs={12} sm={4} md={4} lg={4}>
        <View><Text style={styles.header}>Column 3</Text></View>
      </Col>
    </Row>
  );
};

export default App;
