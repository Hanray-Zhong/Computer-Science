SELECT DISTINCT taketrainrecord.*, passenger.PName FROM taketrainrecord, train, DiagnoseRecord, passenger
		WHERE TakeTrainRecord.TID = train.TID
			AND DiagnoseRecord.PCardID = TakeTrainRecord.PCardID
			AND passenger.PCardID = DiagnoseRecord.PCardID
			AND DiagnoseRecord.DStatus = 1
      AND taketrainrecord.SStatus = 1
			AND train.SDate <= DiagnoseRecord.FDay 
			AND train.SDate >= DATE_SUB(DiagnoseRecord.FDay, INTERVAL 14 DAY);