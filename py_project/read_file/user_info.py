#coding=utf8
from selenium import webdriver
#关联文件
user_file = open('user_info.txt','r')
values = user_file.readlines()
user_file.close()
print values

for serch in values:
	username=serch.split(',')[0]
	print username
	password = serch.split(',')[1]
	print password
