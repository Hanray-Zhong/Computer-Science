SELECT train.* FROM train 
	WHERE train.SDate = '2020-01-22' 
		AND train.SStationID IN 
		(
			SELECT DISTINCT SID FROM station 
				WHERE station.CityName = '武汉');