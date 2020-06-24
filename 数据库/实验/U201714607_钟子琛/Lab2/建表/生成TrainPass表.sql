create table TrainPass(
	TID int,
    SNo smallint,
    SID int,
    STime datetime,
    ATime datetime,
    primary key(TID, SNo),
    foreign key(SID) references station(SID)
);