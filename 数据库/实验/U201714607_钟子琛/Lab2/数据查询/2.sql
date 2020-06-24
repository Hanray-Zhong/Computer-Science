SELECT DISTINCT station.CityName FROM station, TakeTrainRecord
	WHERE station.SID = TakeTrainRecord.AStationID 
		AND TakeTrainRecord.SStationID 
		IN(
			SELECT station.SID FROM station 
				WHERE station.CityName = '武汉'
			);