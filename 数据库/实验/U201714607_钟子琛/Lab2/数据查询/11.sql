SELECT train.TName, train.SDate, TakeTrainRecord.CarriageID FROM train, TakeTrainRecord, DiagnoseRecord
	WHERE train.TID = TakeTrainRecord.TID
		AND TakeTrainRecord.PCardID = DiagnoseRecord.PCardID
		AND DiagnoseRecord.DStatus = 1
		GROUP BY TName, train.SDate, TakeTrainRecord.CarriageID
		HAVING count(*) >= 3; 