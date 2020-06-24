SELECT DISTINCT passenger.* FROM passenger, TakeTrainRecord, station, train
	WHERE passenger.PCardID = TakeTrainRecord.PCardID
	AND TakeTrainRecord.AStationID IN (SELECT DISTINCT SID FROM station WHERE station.CityName = '武汉')
	AND TakeTrainRecord.TID = train.TID
	AND train.SDate >= '2020-01-01' 
	AND train.SDate < '2020-02-01';