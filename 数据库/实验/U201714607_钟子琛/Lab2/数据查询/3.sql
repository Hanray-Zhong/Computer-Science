SELECT DATEDIFF(DiagnoseRecord.DDay, DiagnoseRecord.FDay), passenger.* FROM passenger, DiagnoseRecord
	WHERE passenger.PCardID = DiagnoseRecord.PCardID
	ORDER BY (DiagnoseRecord.FDay - DiagnoseRecord.DDay) DESC;