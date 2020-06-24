drop table if exists t_test;
create table t_test 
(
    a int,
    b int,
);

insert into t_test(a, b) values (1, 1);
insert into t_test(a, b) values (1, 1);
delete from t_test where (a = 1);