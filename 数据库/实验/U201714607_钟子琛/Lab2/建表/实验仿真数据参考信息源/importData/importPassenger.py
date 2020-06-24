import xlrd
import pymssql

import xlrd
import pymssql

conn = pymssql.connect("192.168.0.105", "fdzhuang", "admin", "TrainRecord")

cursor = conn.cursor()

fileName = "旅客表仿真数据.xls"
book = xlrd.open_workbook(fileName)
sheet = book.sheets()[0]
rows = sheet.nrows
result = []
for i in range(1, rows):
    name = sheet.cell_value(i, 0).strip()
    gender = int(sheet.cell_value(i, 1))
    card = sheet.cell_value(i, 2).strip()
    age = int(sheet.cell_value(i, 3))
    result.append((card, name, gender, age))
print(result)
cursor.executemany('insert into passenger values(%s, %s, %d, %d)', result)
conn.commit()