SELECT passenger.PCardID, PName, Tname, Train.SDate FROM passenger, TakeTrainRecord, train, DiagnoseRecord
	WHERE passenger.PCardID = TakeTrainRecord.PCardID
		AND TakeTrainRecord.TID = train.TID
		AND DiagnoseRecord.PCardID = passenger.PCardID
		AND DiagnoseRecord.DStatus = 1
		AND Train.SDate > '2020-01-01';