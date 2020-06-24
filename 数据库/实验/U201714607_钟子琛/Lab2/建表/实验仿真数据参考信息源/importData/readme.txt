如果自己运行的话需要改数据库连接信息，安装pymssql、xlrd这两个python库。
TrainPass中的时间允许为null，插入时插入null有点问题我没解决，设置成了一个特定值'2019-01-01 00:00:00'，
执行完脚本后需要手动将TranPass中时间为'2019-01-01 00:00:00'的更新为null。
数据文件夹中是我导入SQL server后导出的数据，可以根据PPT上的内容导入SQL server。