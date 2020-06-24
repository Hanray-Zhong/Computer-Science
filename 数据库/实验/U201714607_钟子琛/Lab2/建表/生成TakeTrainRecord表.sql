create table TakeTrainRecord(
	RID int,
    PCardID char(18),
    TID int,
    SStationID int,
    AStationID int,
    CarriageID smallint,
    SeatRow smallint,
    SeatNo char(1),
    SStatus int,
    primary key(RID),
    foreign key(SStationID) references station(SID),
    foreign key(AStationID) references station(SID),
    check (SeatNo = 'A' or SeatNo = 'B' or SeatNo = 'C' or SeatNo = 'E' or SeatNo = 'F' or SeatNo = NULL),
    check (SStatus = '0' or SStatus = '1' or SStatus = '2')
);