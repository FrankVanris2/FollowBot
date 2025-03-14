import React, { useEffect, useState, useCallback } from 'react';
import { GeoJSON, MapContainer, Marker, Popup, TileLayer, useMap } from 'react-leaflet';
import 'leaflet/dist/leaflet.css';
import campus from '../res/campus.json';
import dropOffIconImg from '../res/logo.png';
import adaAccessIconImg from '../res/accessible-icon.jpg';
import '../styles/MappingPage.style.css'; 
const MappingPage = () => {
    const [selectedPosition, setSelectedPosition] = useState(null);
    const [geoJsonData, setGeoJsonData] = useState(null);
    const [showTileLayer, setShowTileLayer] = useState(false);

    useEffect(() => {
        if (campus) {
            console.log("GeoJSON Loaded:", campus);
            setGeoJsonData(campus);
        }
    }, []);

    const filteredGeoJsonData = geoJsonData && {
        ...geoJsonData,
        features: geoJsonData.features.filter(
            feature => feature.properties?.name && feature.properties?.name !== "Bellevue College"
        )
    };

    const dropOffPoints = geoJsonData?.features.filter(feature => feature.properties?.amenity === "drop_off") || [];
    const adaAccessPoints = geoJsonData?.features.filter(
        feature => feature.properties?.accessibility === "wheelchair" && feature.geometry.type === "Point"
    ) || [];

    const getDistance = (lat1, lng1, lat2, lng2) => {
        const toRad = deg => (deg * Math.PI) / 180;
        const R = 6371e3;
        const dLat = toRad(lat2 - lat1);
        const dLng = toRad(lng2 - lng1);
        const a = Math.sin(dLat / 2) ** 2
            + Math.cos(toRad(lat1)) * Math.cos(toRad(lat2)) * Math.sin(dLng / 2) ** 2;
        const c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));
        return R * c;
    };

    const findNearestDropOff = useCallback((lat, lng) => {
        return dropOffPoints.reduce((nearest, feature) => {
            const [dropLng, dropLat] = feature.geometry.coordinates;
            const dist = getDistance(lat, lng, dropLat, dropLng);

            return dist < (nearest?.dist || Infinity)
                ? { lat: dropLat, lng: dropLng, dist }
                : nearest;
        }, null);
    }, [dropOffPoints]);

    const MapClickHandler = () => {
        const map = useMap();

        useEffect(() => {
            const handleClick = (event) => {
                const { lat, lng } = event.latlng;
                const nearestDropOff = findNearestDropOff(lat, lng);

                setSelectedPosition(nearestDropOff?.dist < 20 ? { lat, lng } : nearestDropOff);
            };

            map.on("click", handleClick);
            return () => map.off("click", handleClick);
        }, [map, findNearestDropOff]);

        return null;
    };

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

    const handleEachFeature = (feature, layer) => {
        if (feature.properties?.name) {
            layer.bindPopup(`<strong>${feature.properties.name}</strong>`);
        }
        layer.on('click', (event) => {
            event.originalEvent.stopPropagation();

            const buildingCenter = getBuildingCenter(feature);
            const nearestDropOff = findNearestDropOff(buildingCenter.lat, buildingCenter.lng);
            setSelectedPosition(nearestDropOff);
        });
    };

    const dropOffIcon = new L.Icon({ iconUrl: dropOffIconImg, iconSize: [32, 32], iconAnchor: [16, 32] });
    const adaAccessIcon = new L.Icon({ iconUrl: adaAccessIconImg, iconSize: [16, 16], iconAnchor: [8, 8] });

    return (
        <div className="mapping-container">
            <h1>My Campus Map</h1>

            <button className="toggle-button" onClick={() => setShowTileLayer(prev => !prev)}>
                {showTileLayer ? "Hide Map Layer" : "Show Map Layer"}
            </button>

            <MapContainer className="map-container" zoom={16} center={[47.585, -122.148]}>
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
                        position={[
                            feature.geometry.coordinates[1],
                            feature.geometry.coordinates[0]
                        ]}
                        icon={adaAccessIcon}
                    >
                        <Popup>
                            <strong>{feature.properties.name}</strong>
                        </Popup>
                    </Marker>
                ))}

                <MapClickHandler />

                {selectedPosition && (
                    <Marker position={[selectedPosition.lat, selectedPosition.lng]} icon={dropOffIcon}>
                        <Popup>
                            <div>
                                <p>Drop-Off Position:</p>
                                <p>Lat: {selectedPosition.lat.toFixed(6)}</p>
                                <p>Lng: {selectedPosition.lng.toFixed(6)}</p>
                            </div>
                        </Popup>
                    </Marker>
                )}
            </MapContainer>

            {selectedPosition && (
                <div className="selected-position">
                    <p className="text-lg">Nearest Drop-off Position:</p>
                    <p>Latitude: {selectedPosition.lat.toFixed(6)}</p>
                    <p>Longitude: {selectedPosition.lng.toFixed(6)}</p>
                </div>
            )}
        </div>
    );
}

export default MappingPage;