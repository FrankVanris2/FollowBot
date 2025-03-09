import json

#defining a schema
FollowBotData_Schema = {
    "type": "object",
    "properties": {
        "temperature": {"type": "number"},
        #"Battery": {"type": "number"},
        "time": {"type": "string", "format": "date-time"},
        "coordinates": 
            {
                "long": {"type": "number"},
            "lat": {"type": "number"},
            },
    },
    "required": ["temperature", "battery", "time", "coordinates"]
}

#defining a example object
FollowBotData_Example = {
    "temperature": 25.5,
    #"battery": 75,
    "Time": "2023-10-01T12:00:00Z",
    "coordinates": {
        "long": 12.34,
        "lat": 56.78
    }
}

