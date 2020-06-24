import xlrd
import pymssql

conn = pymssql.connect("192.168.0.105", "fdzhuang", "admin", "TrainRecord")

cursor = conn.cursor()

fileName = "全国车站表.xls"
book = xlrd.open_workbook(fileName)
sheet = book.sheets()[0]
rows = sheet.nrows
result = []
for i in range(1, rows):
    result.append((int(sheet.cell_value(i, 0)), sheet.cell_value(i, 1).strip(), sheet.cell_value(i, 3).strip()))
cursor.executemany('insert into station values(%d, %s, %s)', result)
conn.commit()