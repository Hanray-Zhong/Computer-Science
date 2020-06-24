SELECT train.* FROM train, trainpass 
	WHERE train.SDate = '2020-01-22' 
		AND train.TID = trainpass.TID
		AND trainpass.SID IN 
		(
			SELECT DISTINCT SID FROM station 
				WHERE station.CityName = '武汉'
		);