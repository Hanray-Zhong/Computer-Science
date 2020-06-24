SELECT train.TID, passenger.PCardID FROM train,passenger, TakeTrainRecord
	WHERE passenger.PCardID = TakeTrainRecord.PCardID
		AND TakeTrainRecord.TID = train.TID
		AND train.TID IN(
			SELECT train.TID FROM train 
        WHERE train.SDate='2020-01-22' 
					AND train.SStationID IN (SELECT DISTINCT SID FROM station WHERE station.CityName= '武汉'))        
		ORDER BY train.TID DESC, PCardID;