SELECT DISTINCT passenger.* FROM passenger, train, trainpass, TakeTrainRecord
	WHERE passenger.PCardID=TakeTrainRecord.PCardID
		AND LEFT(passenger.PCardID, 3) != '420'
		AND trainpass.TID = train.TID
		AND trainpass.SID IN (SELECT DISTINCT SID FROM station WHERE station.CityName = '武汉')
		AND TakeTrainRecord.TID = train.TID
		AND train.SDate >= '2020-01-01' 
		AND train.SDate <= '2020-01-031';