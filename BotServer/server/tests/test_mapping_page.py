import unittest
from unittest.mock import patch, MagicMock
import json
import os

# Assuming you have your MappingPage component logic in a separate file, e.g., mapping_page.py
# You'll need to adjust the import path accordingly if your file is located differently.
# For this example, let's simulate the relevant parts of MappingPage in a helper module.

# Create a dummy mapping_page_helper.py to simulate the MappingPage functionality

class MappingPageHelper:
    def __init__(self):
        #Load data for test.
        self.campus = self.load_campus_data()
    def load_campus_data(self):
        file_path = os.path.join(os.path.dirname(__file__), "..", "src", "res", "campus.json")
        try:
            with open(file_path, 'r') as f:
                data = json.load(f)
                return data
        except (FileNotFoundError, json.JSONDecodeError):
                print(f"Error loading campus data from {file_path}.")
                return None
    def get_distance(self, lat1, lng1, lat2, lng2):
        # Simplified distance calculation for testing
        return ((lat1 - lat2) ** 2 + (lng1 - lng2) ** 2) ** 0.5

    def find_nearest_drop_off(self, lat, lng):
        drop_off_points = [
            {
                "geometry": {"coordinates": [-122.149, 47.586]},
                "properties": {"amenity": "drop_off"},
            },
            {
                "geometry": {"coordinates": [-122.147, 47.584]},
                "properties": {"amenity": "drop_off"},
            },
            # Add more dummy drop-off points if needed
        ]
        nearest = None
        min_dist = float("inf")
        for feature in drop_off_points:
            drop_lng, drop_lat = feature["geometry"]["coordinates"]
            dist = self.get_distance(lat, lng, drop_lat, drop_lng)
            if dist < min_dist:
                min_dist = dist
                nearest = {
                    "lat": drop_lat,
                    "lng": drop_lng,
                    "dist": dist,
                }
        return nearest

    def get_building_center(self, building):
        coords = building["geometry"]["coordinates"][0]
        lat_sum = sum(lat for lng, lat in coords)
        lng_sum = sum(lng for lng, lat in coords)
        count = len(coords)
        return {"lat": lat_sum / count, "lng": lng_sum / count}
    def filter_geoJson_data(self, geoJsonData):
        if geoJsonData:
            return {
                **geoJsonData,
                "features": [
                    feature
                    for feature in geoJsonData["features"]
                    if feature.get("properties", {}).get("name")
                    and feature["properties"]["name"] != "Bellevue College"
                ],
            }
        return None
    
    def get_drop_off_points(self,geoJsonData):
        if geoJsonData and geoJsonData["features"]:
            return [
                feature
                for feature in geoJsonData["features"]
                if feature.get("properties", {}).get("amenity") == "drop_off"
            ]
        return []
    def get_ada_points(self,geoJsonData):
        if geoJsonData and geoJsonData["features"]:
             return [
                feature
                for feature in geoJsonData["features"]
                if feature.get("properties", {}).get("accessibility") == "wheelchair"
                and feature.get("geometry", {}).get("type") == "Point"
            ]
        return []


class TestMappingPage(unittest.TestCase):
    def setUp(self):
        self.mapping_page_helper = MappingPageHelper()
        # set up dummy data.
        self.dummy_campus_data = {
             "features": [
                {
                    "geometry": {"coordinates": [[-122.148, 47.585],[ -122.149, 47.586]],"type": "MultiPolygon"},
                    "properties": {"name": "Building A", "amenity":"office"},
                },
                {
                    "geometry": {"coordinates": [-122.149, 47.586],"type": "Point"},
                    "properties": {"amenity": "drop_off", "name":"drop_off 1"},
                },
                {
                    "geometry": {"coordinates": [-122.147, 47.584],"type": "Point"},
                    "properties": {"amenity": "drop_off","name":"drop_off 2"},
                },
                 {
                    "geometry": {"coordinates": [-122.146, 47.587],"type": "Point"},
                    "properties": {"accessibility": "wheelchair","name":"access point 1"},
                },
                  {
                    "geometry": {"coordinates": [[-122.143, 47.587],[ -122.149, 47.586]],"type": "MultiPolygon"},
                    "properties": {"name": "Bellevue College", "amenity":"college"},
                },
            ]
        }

    def test_get_distance(self):
        dist = self.mapping_page_helper.get_distance(47.585, -122.148, 47.586, -122.149)
        self.assertAlmostEqual(dist, 0.00141421356, places=6)

    def test_find_nearest_drop_off(self):
        nearest = self.mapping_page_helper.find_nearest_drop_off(47.585, -122.148)
        self.assertEqual(nearest["lat"], 47.586)
        self.assertEqual(nearest["lng"], -122.149)
        self.assertAlmostEqual(nearest["dist"], 0.00141421356, places=6)

    def test_get_building_center(self):
        building = self.dummy_campus_data["features"][0]
        center = self.mapping_page_helper.get_building_center(building)
        self.assertAlmostEqual(center["lat"], 47.5855, places=6)
        self.assertAlmostEqual(center["lng"], -122.1485, places=6)
    def test_filter_geoJson_data(self):
        filtered = self.mapping_page_helper.filter_geoJson_data(self.dummy_campus_data)
        names = [feature["properties"]["name"] for feature in filtered["features"]]
        self.assertNotIn("Bellevue College", names)
    def test_get_drop_off_points(self):
        dropOffs = self.mapping_page_helper.get_drop_off_points(self.dummy_campus_data)
        amenities = [feature["properties"]["amenity"] for feature in dropOffs]
        self.assertTrue(all(amenity == "drop_off" for amenity in amenities))

    def test_get_ada_points(self):
        adaPoints = self.mapping_page_helper.get_ada_points(self.dummy_campus_data)
        accessibilities = [feature["properties"]["accessibility"] for feature in adaPoints]
        self.assertTrue(all(accessibility == "wheelchair" for accessibility in accessibilities))
        geometries = [feature["geometry"]["type"] for feature in adaPoints]
        self.assertTrue(all(geoType == "Point" for geoType in geometries))
    def test_load_campus_data(self):
        campus = self.mapping_page_helper.load_campus_data()
        self.assertIsNotNone(campus)
        self.assertTrue(isinstance(campus,dict))


if __name__ == "__main__":
    unittest.main()
