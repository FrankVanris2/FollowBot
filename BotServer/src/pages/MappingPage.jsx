import React, { useEffect, useState, useCallback } from 'react';
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
        const nearestDropOff = findNearestDropOff(lat, lng);
        
        setSelectedPosition({
          clicked: { lat, lng },
          nearestDropOff: nearestDropOff
        });
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
      const nearestDropOff = findNearestDropOff(buildingCenter.lat, buildingCenter.lng);
      setSelectedPosition({
        clicked: buildingCenter,
        nearestDropOff: nearestDropOff
      });
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
        const response = await api.sendCoordinates(
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

  return (
    <div className="container">
      <h1 className="header">My Campus Map</h1>

      <button className="toggle-button" onClick={() => setShowTileLayer(prev => !prev)}>
        {showTileLayer ? "Hide Map Layer" : "Show Map Layer"}
      </button>

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

          <MapClickHandler />
          <ResizeHandler />

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

          {/* Nearest drop-off marker */}
          {selectedPosition?.nearestDropOff && (
            <Marker 
              position={[selectedPosition.nearestDropOff.lat, selectedPosition.nearestDropOff.lng]} 
              icon={dropOffIcon}
            >
              <Popup>
                <div>
                  <p>Nearest Drop-off:</p>
                  <p>Lat: {selectedPosition.nearestDropOff.lat.toFixed(6)}</p>
                  <p>Lng: {selectedPosition.nearestDropOff.lng.toFixed(6)}</p>
                  <p>Distance: {selectedPosition.nearestDropOff.dist.toFixed(2)} meters</p>
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
        </MapContainer>
      </div>

      {showConfirmation && (
        <div className="confirmation-dialog">
          <div className="confirmation-content">
            <h3>Confirm this location?</h3>
            <div className="position-section">
              <p>Latitude: {selectedPosition?.clicked.lat.toFixed(6)}</p>
              <p>Longitude: {selectedPosition?.clicked.lng.toFixed(6)}</p>
            </div>
            {isSending ? (
              <div className="loading-spinner">Sending...</div>
            ) : (
              <div className="button-wrapper">
                <button 
                  className="confirm-button yes-button"
                  onClick={() => handleConfirmation(true)}
                  disabled={isSending}
                >
                  Yes
                </button>
                <button 
                  className="confirm-button no-button"
                  onClick={() => handleConfirmation(false)}
                  disabled={isSending}
                >
                  No
                </button>
              </div>
            )}
            {sendStatus === 'success' && (
              <div className="status-message success">Location sent successfully!</div>
            )}
            {sendStatus === 'error' && (
              <div className="status-message error">Failed to send location</div>
            )}
          </div>
        </div>
      )}
    </div>
  );
};

export default MappingPage;