# a=100000
# b=100000
# print(id(a))
# print(id(b))


from datetime import datetime


now = datetime.now() # current date and time

year = now.strftime("%Y")
print("year:", year)

month = now.strftime("%m")
print("month:", month)

day = now.strftime("%d")
print("day:", day)

time = now.strftime("%H:%M:%S")
print("time:", time)

date_time = now.strftime("%Y-%m-%d, %H:%M:%S:%f")
print("date and time:",date_time)

time_test=now.strftime("%H:%M:%S:%f")[:-3]
print("time and test:",time_test)