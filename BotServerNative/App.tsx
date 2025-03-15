import React, { useEffect } from 'react'; // Import useEffect
import { View, Text, Button } from 'react-native';
import { Row, Col } from 'react-native-responsive-grid-system';
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

const scanBluetooth = async (isScanning : boolean) => {
  try {
    if (isScanning) {
      await BleManager.scan([], 15, false);
      const peripherals = await BleManager.getDiscoveredPeripherals();
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

  useEffect(() => {
    startBluetooth();

    return () => {
      BleManager.stopScan();
    };
  }, []);

  useEffect(() => {
    scanBluetooth(isScanning);
  }, [isScanning]);

  return (
    <Row>
      <Col xs={12} sm={4} md={4} lg={4}>
        <Button title='Scan' onPress={() => setIsScanning(!isScanning)} />
        <View><Text style={styles.header}>{isScanning ? 'Scanning' : ''}</Text></View>
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
