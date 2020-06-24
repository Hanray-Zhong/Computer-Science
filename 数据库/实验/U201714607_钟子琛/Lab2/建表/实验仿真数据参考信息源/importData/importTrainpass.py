import xlrd
import pymssql
from xlrd import xldate_as_tuple
import datetime

conn = pymssql.connect("192.168.0.105", "fdzhuang", "admin", "TrainRecord")

cursor = conn.cursor()

def getStationId(name):
    cursor.execute("select SID from Station where SName=%s", name)
    return cursor.fetchall()[0][0]

def getTids(name):
    cursor.execute("select TID from Train where TName=%s", name)
    tmp = cursor.fetchall()
    result = []
    for item in tmp:
        result.append(item[0])
    return result

def getDate(tid):
    cursor.execute("select SDate from Train where TID=%s", tid)
    return cursor.fetchall()[0][0]

fileName = "部分车次的运行时刻表.xls"
book = xlrd.open_workbook(fileName)
sheet = book.sheets()[0]
rows = sheet.nrows
result = []
id = 1
for i in range(1, rows):
    name = sheet.cell_value(i, 0).strip().split("/")[0]
    index = cost = int(sheet.cell_value(i, 1))
    station = sheet.cell_value(i, 2).strip()
    stationId = getStationId(station)
    beginTimeData = sheet.cell_value(i, 3)
    endTimeData = sheet.cell_value(i, 4)
    beginTime = None if(type(beginTimeData) == str) else xldate_as_tuple(beginTimeData, 0)
    endTime = None if(type(endTimeData) == str) else xldate_as_tuple(endTimeData, 0)
    cost = int(sheet.cell_value(i, 6))
    tids = getTids(name)
    for tid in tids:
        sdate = getDate(tid)
        curDate = datetime.datetime.strptime(sdate, '%Y-%m-%d')
        arriveTime = None if(beginTime == None) else (curDate + datetime.timedelta(days=(cost-1)) + datetime.timedelta(hours=beginTime[3]) + datetime.timedelta(minutes=beginTime[4])).strftime("%Y-%m-%d %H:%M:%S")
        leaveTime = None if(endTime == None) else (curDate + datetime.timedelta(days=(cost-1)) + datetime.timedelta(hours=endTime[3]) + datetime.timedelta(minutes=endTime[4])).strftime("%Y-%m-%d %H:%M:%S")
        t = (tid, index, stationId, '2019-01-01 00:00:00' if(arriveTime == None) else arriveTime, '2019-01-01 00:00:00' if(leaveTime == None) else leaveTime)
        result.append(t)
    print(i)

cursor.executemany('insert into TrainPass values(%d, %d, %d, %s, %s)', result)
conn.commit()