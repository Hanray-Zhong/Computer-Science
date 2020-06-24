create table TrainContactor(
	CDate date,
    CCardID char(18),
    DStatus smallint,
    PCardID char(18),
    primary key(CDate, CCardID, DStatus, PCardID)
);