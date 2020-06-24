BEGIN
	DECLARE _CCardID char(18);
	DECLARE _DStatus smallint;
	DECLARE _PCardID char(18);
	
	DECLARE _TID INT;
	DECLARE _CarriageID SMALLINT;
	DECLARE _SeatRow SMALLINT;
	DECLARE _STime date;
	
	SET _PCardID = new.PCardID;

	SELECT taketrainrecord.TID INTO _TID FROM taketrainrecord
		WHERE taketrainrecord.TID IN
		(
			SELECT train.TID FROM taketrainrecord, train
				WHERE taketrainrecord.TID = train.TID
					AND new.PCardID = taketrainrecord.PCardID
					AND new.DStatus = 1
					AND train.SDate <= new.FDay 
					AND train.SDate >= DATE_SUB(new.FDay, INTERVAL 14 DAY)
		);
	-- 确认有患者被搜索到，并且满足条件
	IF(_TID != NULL) THEN
		-- 找到车厢号
		SELECT taketrainrecord.CarrigeID INTO _CarriageID FROM taketrainrecord
			WHERE taketrainrecord.PCardID = _PCardID;
		-- 找到行数
		SELECT taketrainrecord.SeatRow INTO _SeatRow FROM taketrainrecord
			WHERE taketrainrecord.PCardID = _PCardID;
		-- 找到对应列车的发车日期
		SELECT train.STime INTO _STime FROM train
			WHERE train.TID = _TID;
		-- 找该行前后的人，将他们加入到traincontactor
		INSERT INTO traincontactor(CCardID) SELECT taketrainrecord.PCardID FROM taketrainrecord
			WHERE taketrainrecord.TID = _TID
				AND taketrainrecord.CarrigeID = _CarriageID
				AND (taketrainrecord.SeatRow = _SeatRow OR taketrainrecord.SeatRow = _SeatRow + 1 OR taketrainrecord.SeatRow = _SeatRow - 1);
		UPDATE traincontactor SET PCardID = _PCardID 
			WHERE traincontactor.PCardID = NULL;
	END IF;
END