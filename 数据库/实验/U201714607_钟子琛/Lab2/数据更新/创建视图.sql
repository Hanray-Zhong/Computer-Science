CREATE VIEW CovidPatient AS
	SELECT passenger.PCardID, Pname, Age, train.TID, train.SDate, CarriageID, SeatRow, SeatNo 
	FROM passenger, diagnoserecord, taketrainrecord, train
	WHERE diagnoserecord.PCardID = passenger.PCardID AND DiagnoseRecord.Dstatus = 1
	AND taketrainrecord.PCardID = diagnoserecord.PCardID
	AND train.TID = taketrainrecord.TID
	AND SStatus = 1
	ORDER BY PCardID, train.SDate DESC;

SELECT * FROM CovidPatient WHERE PCardID IN(SELECT PCardID FROM CovidPatient GROUP BY PCardID HAVING COUNT(*)>=1);