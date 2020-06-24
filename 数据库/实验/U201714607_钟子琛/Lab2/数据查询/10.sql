SELECT count(*) FROM TakeTrainRecord
	WHERE (TakeTrainRecord.TID, TakeTrainRecord.CarriageID) IN (
		SELECT TakeTrainRecord.TID, TakeTrainRecord.CarriageID FROM passenger, TakeTrainRecord, train, DiagnoseRecord
			WHERE TakeTrainRecord.TID = train.TID
				AND train.SDate = '2020-01-22'
				AND train.TName = 'G007'
				AND passenger.PCardID = TakeTrainRecord.PCardID
				AND DiagnoseRecord.PCardID = passenger.PCardID
				AND DiagnoseRecord.DStatus = 1
	);