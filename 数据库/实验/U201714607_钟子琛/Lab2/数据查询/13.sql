SELECT DISTINCT train.TName FROM train
	WHERE train.AStationID IN (
		SELECT station.SID FROM station 
			WHERE station.CityName IN('北京', '上海', '广州')
	);