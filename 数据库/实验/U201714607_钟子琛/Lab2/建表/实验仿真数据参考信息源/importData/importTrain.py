import xlrd
import pymssql
from xlrd import xldate_as_tuple
import datetime

conn = pymssql.connect("192.168.0.105", "fdzhuang", "admin", "TrainRecord")

cursor = conn.cursor()

def getStationId(name):
    cursor.execute("select SID from Station where SName=%s", name)
    return cursor.fetchall()[0][0]

fileName = "部分车次.xls"
book = xlrd.open_workbook(fileName)
sheet = book.sheets()[0]
rows = sheet.nrows
result = []
id = 1
for i in range(1, rows):
    name = sheet.cell_value(i, 0).strip().split("/")[0]
    beginStation = sheet.cell_value(i, 1).strip()
    beginStationId = getStationId(beginStation)
    endStation = sheet.cell_value(i, 2).strip()
    endStationId = getStationId(endStation)
    beginTime = xldate_as_tuple(sheet.cell_value(i, 3), 0)
    endTime = xldate_as_tuple(sheet.cell_value(i, 4), 0)
    cost = int(sheet.cell_value(i, 5))
    startDate = '2019-12-01'
    startDate = datetime.datetime.strptime(startDate, '%Y-%m-%d')
    endDate = '2020-3-1'
    endDate = datetime.datetime.strptime(endDate, '%Y-%m-%d')
    curDate = startDate
    while curDate < endDate:
        curDate = curDate + datetime.timedelta(days=1)
        beginDatetime = curDate + datetime.timedelta(hours=beginTime[3]) + datetime.timedelta(minutes=beginTime[4])
        endDatetime = curDate + datetime.timedelta(days=(cost-1)) + datetime.timedelta(hours=endTime[3]) + datetime.timedelta(minutes=endTime[4])
        t = (id, curDate.strftime('%Y-%m-%d'), name, beginStationId, endStationId, beginDatetime.strftime("%Y-%m-%d %H:%M:%S"), endDatetime.strftime("%Y-%m-%d %H:%M:%S"))
        id = id + 1
        # print(t)
        result.append(t)
# print(result)
cursor.executemany('insert into Train values(%d, %s, %s, %d, %d, %s, %s)', result)
conn.commit()