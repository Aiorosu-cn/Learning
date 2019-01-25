#coding=utf8
import csv
#读取本地CSV文件
#可以指定相对路径和绝对路径
file_name='info.csv'
#使用csv.read(file())方法来读取信息
date=csv.reader(file(file_name,'rb'))
print date

#循环输出每一行
for user in date:
	#读取指定列
	print user
	# for u in user:
	# 	print u

