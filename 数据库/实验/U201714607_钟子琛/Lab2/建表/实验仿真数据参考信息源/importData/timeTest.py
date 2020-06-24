import datetime
import time
now_re = datetime.datetime.strptime('2019-12-01', '%Y-%m-%d')
print(now_re)
startDate = '2019-12-01'
startDate = datetime.datetime.strptime(startDate, '%Y-%m-%d')
endDate = '2020-3-1'
endDate = datetime.datetime.strptime(endDate, '%Y-%m-%d')
curDate = startDate
while curDate < endDate:
    print(curDate)
    curDate = curDate + datetime.timedelta(days=1)
    # (datetime.datetime.now() + datetime.timedelta(days=1)).strftime("%Y-%m-%d %H:%M:%S")
