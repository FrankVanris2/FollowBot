import React, { useEffect } from 'react'; // Import useEffect
import { View, Text, Button, ScrollView } from 'react-native';
import { Row, Col } from 'react-native-responsive-grid-system';
import Geolocation from '@react-native-community/geolocation';  
import BleManager from 'react-native-ble-manager';
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

  useEffect(() => {
    startBluetooth();

    return () => {
      BleManager.stopScan();
    };
  }, []);

  useEffect(() => {
    scanBluetooth(isScanning, setPeripherals);
  }, [isScanning]);

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

  return (
    <Row>
      <Col xs={12} sm={4} md={4} lg={4}>
        <Button title='Scan' onPress={() => setIsScanning(true)} />
        <View>
          <Text style={styles.header}>{isScanning ? 'Scanning' : ''}</Text>
        </View>
        <ScrollView>{renderPeripheralList()}</ScrollView>
        {connectedPeripheral && <Text>Connected to: {connectedPeripheral}</Text>}
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
