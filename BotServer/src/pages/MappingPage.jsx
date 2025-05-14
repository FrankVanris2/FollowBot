import React, { useEffect, useState, useCallback, useRef } from 'react';
import { GeoJSON, MapContainer, Marker, Popup, TileLayer, useMap } from 'react-leaflet';
import L from 'leaflet';
import 'leaflet/dist/leaflet.css';
import campus from '../res/campus.json';
import dropOffIconImg from '../res/logo.png';
import adaAccessIconImg from '../res/accessible-icon.jpg';
import '../styles/MappingPage.style.css';
import api from '../services/api';

const MappingPage = () => {
  // State to store map interactions
  const [selectedPosition, setSelectedPosition] = useState(null);
  const [confirmedPosition, setConfirmedPosition] = useState(null);
  const [showConfirmation, setShowConfirmation] = useState(false);
  const [geoJsonData, setGeoJsonData] = useState(null);
  const [showTileLayer, setShowTileLayer] = useState(true);
  const [isSending, setIsSending] = useState(false);
  const [sendStatus, setSendStatus] = useState(null);
  const [currentMode, setCurrentMode] = useState('mapping'); // 'mapping' or 'following'
  const [nearestDropOffPoint, setNearestDropOffPoint] = useState(null);

  const notificationRef = useRef(null);
  const [notificationVisible, setNotificationVisible] = useState(false);

  // Load campus data on component mount
  useEffect(() => {
    if (campus) {
      setGeoJsonData(campus);
    }
  }, []);

  // Filter out unwanted features
  const filteredGeoJsonData = geoJsonData && {
    ...geoJsonData,
    features: geoJsonData.features.filter(
      feature => feature.properties?.name && feature.properties?.name !== "Bellevue College"
    )
  };

  // Extract points of interest
  const dropOffPoints = geoJsonData?.features.filter(feature => feature.properties?.amenity === "drop_off") || [];
  const adaAccessPoints = geoJsonData?.features.filter(
    feature => feature.properties?.accessibility === "wheelchair" && feature.geometry.type === "Point"
  ) || [];

  // Calculate distance between two points (Haversine formula)
  const getDistance = (lat1, lng1, lat2, lng2) => {
    const toRad = deg => (deg * Math.PI) / 180;
    const R = 6371e3;
    const dLat = toRad(lat2 - lat1);
    const dLng = toRad(lng2 - lng1);
    const a = Math.sin(dLat / 2) ** 2 + Math.cos(toRad(lat1)) * Math.cos(toRad(lat2)) * Math.sin(dLng / 2) ** 2;
    const c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));
    return R * c;
  };

  // Find nearest drop-off point
  const findNearestDropOff = useCallback((lat, lng) => {
    return dropOffPoints.reduce((nearest, feature) => {
      const [dropLng, dropLat] = feature.geometry.coordinates;
      const dist = getDistance(lat, lng, dropLat, dropLng);
      return dist < (nearest?.dist || Infinity)
        ? { lat: dropLat, lng: dropLng, dist }
        : nearest;
    }, null);
  }, [dropOffPoints]);

  // Handle map click events
  const MapClickHandler = () => {
    const map = useMap();

    useEffect(() => {
      const handleClick = (event) => {
        const { lat, lng } = event.latlng;
        
        // Find the nearest drop-off point automatically
        const nearestDropOff = findNearestDropOff(lat, lng);
        
        // Set selected position with nearest drop-off
        setSelectedPosition({
          clicked: { lat, lng },
          nearestDropOff: nearestDropOff
        });
        
        // Also set the nearest drop-off point for highlighting
        setNearestDropOffPoint(nearestDropOff);
        
        // Show confirmation dialog
        setShowConfirmation(true);
      };

      map.on("click", handleClick);
      return () => map.off("click", handleClick);
    }, [map, findNearestDropOff]);

    return null;
  };

  // Handle window resize
  const ResizeHandler = () => {
    const map = useMap();

    useEffect(() => {
      const handleResize = () => {
        map.invalidateSize();
      };

      window.addEventListener('resize', handleResize);
      return () => window.removeEventListener('resize', handleResize);
    }, [map]);

    return null;
  };

  // Calculate center of building polygons
  const getBuildingCenter = (building) => {
    const coords = building.geometry.coordinates[0];
    const { latSum, lngSum, count } = coords.reduce(
      (accumulator, [lng, lat]) => ({
        latSum: accumulator.latSum + lat,
        lngSum: accumulator.lngSum + lng,
        count: accumulator.count + 1
      }),
      { latSum: 0, lngSum: 0, count: 0 });

    return { lat: latSum / count, lng: lngSum / count };
  };

  // Add interactivity to GeoJSON features
  const handleEachFeature = (feature, layer) => {
    if (feature.properties?.name) {
      layer.bindPopup(`<strong>${feature.properties.name}</strong>`);
    }
    layer.on('click', (event) => {
      event.originalEvent.stopPropagation();
      const buildingCenter = getBuildingCenter(feature);
      
      // Find nearest drop-off automatically
      const nearestDropOff = findNearestDropOff(buildingCenter.lat, buildingCenter.lng);
      
      // Set selected position
      setSelectedPosition({
        clicked: buildingCenter,
        nearestDropOff: nearestDropOff
      });
      
      // Also set the nearest drop-off point for highlighting
      setNearestDropOffPoint(nearestDropOff);
      
      // Show confirmation dialog
      setShowConfirmation(true);
    });
  };

  // Handle confirmation response
  const handleConfirmation = async (confirmed) => {
    if (confirmed) {
      setIsSending(true);
      setSendStatus(null);
      try {
        // Send coordinates to API
        const response = await api.postCoordinates(
          selectedPosition.clicked.lat,
          selectedPosition.clicked.lng
        );
        
        if (response.success) {
          console.log('Coordinates sent successfully:', response);
          setConfirmedPosition(selectedPosition);
          setSendStatus('success');
        } else {
          console.error('Failed to send coordinates:', response.error);
          setSendStatus('error');
        }
      } catch (error) {
        console.error('Error sending coordinates:', error);
        setSendStatus('error');
      } finally {
        setIsSending(false);
      }
    } else {
      setShowConfirmation(false);
    }
  };

  // Create custom icons
  const dropOffIcon = new L.Icon({ 
    iconUrl: dropOffIconImg, 
    iconSize: [32, 32], 
    iconAnchor: [16, 32] 
  });
  
  const adaAccessIcon = new L.Icon({ 
    iconUrl: adaAccessIconImg, 
    iconSize: [16, 16], 
    iconAnchor: [8, 8] 
  });

  // Add this new function to handle finding the nearest drop-off point
  const handleFindNearestDropOff = () => {
    if (selectedPosition) {
      const nearestDropOff = findNearestDropOff(
        selectedPosition.clicked.lat, 
        selectedPosition.clicked.lng
      );
      
      setNearestDropOffPoint(nearestDropOff);
    } else if (confirmedPosition) {
      const nearestDropOff = findNearestDropOff(
        confirmedPosition.clicked.lat, 
        confirmedPosition.clicked.lng
      );
      
      setNearestDropOffPoint(nearestDropOff);
    }
  };

  // Add this hook to get the map instance
  const MapWithContext = () => {
    const map = useMap();
    
    // Store map reference in a context or ref that can be accessed by the component
    useEffect(() => {
      if (map) {
        window.mapInstance = map; // Store in window for simplicity
      }
    }, [map]);
    
    return null;
  };

  // Replace your positioning useEffect with this simpler version
  useEffect(() => {
    // Just handle visibility timing
    if (showConfirmation) {
      setTimeout(() => setNotificationVisible(true), 50);
    } else {
      setNotificationVisible(false);
    }
  }, [showConfirmation]);

  return (
    <div className="container">
      <h1 className="header">My Campus Map</h1>

      <div className="top-controls">
        {/* Floating notification */}
        {showConfirmation && (
          <div 
            className="map-notification near-dropoff"
            style={{
              opacity: notificationVisible ? 1 : 0
            }}
            ref={notificationRef}
          >
            <div className="notification-content">
              <div className="distance-info">
                Nearest drop-off: {selectedPosition?.nearestDropOff?.dist.toFixed(2)}m
              </div>
              <div className="notification-buttons">
                <button 
                  className="map-button confirm-button"
                  onClick={() => handleConfirmation(true)}
                  disabled={isSending}
                >
                  Confirm
                </button>
                <button 
                  className="map-button cancel-button"
                  onClick={() => handleConfirmation(false)}
                  disabled={isSending}
                >
                  Cancel
                </button>
              </div>
            </div>
            
            {isSending && (
              <div className="sending-indicator">Sending...</div>
            )}
            
            {sendStatus && (
              <div className={`status-message ${sendStatus}`}>
                {sendStatus === 'success' ? 'Sent!' : 'Failed!'}
              </div>
            )}
          </div>
        )}
        
        <button className="toggle-button" onClick={() => setShowTileLayer(prev => !prev)}>
          {showTileLayer ? "Hide Map Layer" : "Show Map Layer"}
        </button>
      </div>

      <div className="controls-wrapper">
        {/* Display confirmed position */}
        {confirmedPosition && (
          <div className="confirmed-position">
            <h2>Confirmed Location</h2>
            <div className="info-wrapper">
              <h3>Position</h3>
              <p>Latitude: {confirmedPosition.clicked.lat.toFixed(6)}</p>
              <p>Longitude: {confirmedPosition.clicked.lng.toFixed(6)}</p>
            </div>
            {confirmedPosition.nearestDropOff && (
              <div className="info-wrapper">
                <h3>Nearest Drop-off</h3>
                <p>Latitude: {confirmedPosition.nearestDropOff.lat.toFixed(6)}</p>
                <p>Longitude: {confirmedPosition.nearestDropOff.lng.toFixed(6)}</p>
                <p>Distance: {confirmedPosition.nearestDropOff.dist.toFixed(2)} meters</p>
              </div>
            )}
          </div>
        )}
        
        {/* Add this button */}
        <button 
          className="find-nearest-button"
          onClick={handleFindNearestDropOff}
          disabled={!selectedPosition && !confirmedPosition}
        >
          Find Nearest Drop-off Point
        </button>
        
        {/* Display nearest drop-off information when found */}
        {nearestDropOffPoint && (
          <div className="nearest-dropoff">
            <h3>Nearest Drop-off Point</h3>
            <p>Latitude: {nearestDropOffPoint.lat.toFixed(6)}</p>
            <p>Longitude: {nearestDropOffPoint.lng.toFixed(6)}</p>
            <p>Distance: {nearestDropOffPoint.dist.toFixed(2)} meters</p>
          </div>
        )}
      </div>

      <div className="map-container-wrapper">
        <MapContainer
          className="map-container"
          zoom={15}  
          center={[47.585, -122.148]}
          style={{ height: '100%', width: '100%' }}
        >
          {showTileLayer && (
            <TileLayer
              url="https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png"
              attribution="&copy; OpenStreetMap contributors"
            />
          )}

          {filteredGeoJsonData && (
            <GeoJSON
              data={filteredGeoJsonData}
              style={{ color: 'blue', weight: 2 }}
              pointToLayer={(feature, latlng) => {
                if (feature.geometry.type === "Point") {
                  return L.circleMarker(latlng, { radius: 5, color: 'blue' });
                }
              }}
              onEachFeature={handleEachFeature}
            />
          )}

          {adaAccessPoints.map((feature, index) => (
            <Marker
              key={index}
              position={[feature.geometry.coordinates[1], feature.geometry.coordinates[0]]}
              icon={adaAccessIcon}
            >
              <Popup>
                <strong>{feature.properties.name}</strong>
              </Popup>
            </Marker>
          ))}

          {dropOffPoints.map((feature, index) => (
            <Marker
              key={`dropoff-${index}`}
              position={[feature.geometry.coordinates[1], feature.geometry.coordinates[0]]}
              icon={dropOffIcon}
            >
              <Popup>
                <strong>{feature.properties.name || 'Drop-off Point'}</strong>
              </Popup>
            </Marker>
          ))}

          <MapClickHandler />
          <ResizeHandler />
          <MapWithContext />

          {/* Click position marker */}
          {selectedPosition?.clicked && (
            <Marker position={[selectedPosition.clicked.lat, selectedPosition.clicked.lng]}>
              <Popup>
                <div>
                  <p>Selected Position:</p>
                  <p>Lat: {selectedPosition.clicked.lat.toFixed(6)}</p>
                  <p>Lng: {selectedPosition.clicked.lng.toFixed(6)}</p>
                </div>
              </Popup>
            </Marker>
          )}

          {/* Confirmed position marker */}
          {confirmedPosition?.clicked && (
            <Marker 
              position={[confirmedPosition.clicked.lat, confirmedPosition.clicked.lng]} 
              icon={new L.Icon({ 
                iconUrl: 'https://raw.githubusercontent.com/pointhi/leaflet-color-markers/master/img/marker-icon-green.png',
                iconSize: [25, 41],
                iconAnchor: [12, 41]
              })}
            >
              <Popup>
                <div>
                  <p>Confirmed Position:</p>
                  <p>Lat: {confirmedPosition.clicked.lat.toFixed(6)}</p>
                  <p>Lng: {confirmedPosition.clicked.lng.toFixed(6)}</p>
                </div>
              </Popup>
            </Marker>
          )}

          {/* Nearest drop-off point marker */}
          {nearestDropOffPoint && (
            <Marker 
              position={[nearestDropOffPoint.lat, nearestDropOffPoint.lng]} 
              icon={new L.Icon({ 
                iconUrl: 'https://raw.githubusercontent.com/pointhi/leaflet-color-markers/master/img/marker-icon-red.png',
                iconSize: [25, 41],
                iconAnchor: [12, 41]
              })}
            >
              <Popup>
                <div>
                  <p>Nearest Drop-off Point</p>
                  <p>Distance: {nearestDropOffPoint.dist.toFixed(2)} meters</p>
                </div>
              </Popup>
            </Marker>
          )}
        </MapContainer>
      </div>

      <div className="bottom-space" /> {/* To ensure the map container is not covered */}
    </div>
  );
};

export default MappingPage;