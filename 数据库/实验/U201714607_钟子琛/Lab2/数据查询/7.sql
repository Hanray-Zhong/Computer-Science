SELECT station.CityName, count(CityName) FROM passenger, TakeTrainRecord, station, train
	WHERE passenger.PCardID = TakeTrainRecord.PCardID 
		AND station.SID = TakeTrainRecord.AStationID
		AND train.TID = TakeTrainRecord.TID
		AND TakeTrainRecord.TID 
		IN (
			SELECT DISTINCT train.TID FROM train 
				WHERE train.SDate = '2020-01-22' 
					AND train.SStationID IN (
						SELECT DISTINCT SID FROM station 
							WHERE station.CityName= '武汉')
				)
		GROUP BY(CityName);