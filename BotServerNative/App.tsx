import React, { useEffect } from 'react'; // Import useEffect
import { StyleSheet, View, Text } from 'react-native';
import { Row, Col } from 'react-native-responsive-grid-system';
import BleManager from 'react-native-ble-manager';
import { styles } from './App.styles';

const App = () => {
  useEffect(() => {
    // Initialize BleManager when the component mounts
    BleManager.start({ showAlert: false }).then(() => {
      console.log('BleManager initialized');
      // You can now use BleManager methods here or in other parts of your component
    }).catch((error) => {
      console.error('BleManager initialization error:', error);
    });

    // Clean up when the component unmounts (optional)
    return () => {
      BleManager.stopScan();
    };
  }, []);

  return (
    <Row>
      <Col xs={12} sm={4} md={4} lg={4}>
        <View><Text style={styles.header}>Column 1</Text></View>
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
