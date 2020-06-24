CREATE TABLE WH_TakeTrainRecord AS
	(SELECT * FROM TakeTrainRecord 
		WHERE SStationID IN (SELECT SID FROM station WHERE CityName='武汉')
	);
SELECT * FROM WH_TakeTrainRecord;