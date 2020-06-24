create table Train(
	TID int primary key,
    SDate date,
    TName char(20),
    SStationID int,
    AStationID int,
    STime datetime,
    ATime datetime,
    foreign key(SStationID) references station(SID),
    foreign key(AStationID) references station(SID)
);