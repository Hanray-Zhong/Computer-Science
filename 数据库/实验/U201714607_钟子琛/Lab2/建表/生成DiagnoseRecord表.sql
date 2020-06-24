create table DiagnoseRecord(
	DID int primary key,
    PCardID char(18),
    DDay date,
    DStatus smallint,
    FDay date
) ;