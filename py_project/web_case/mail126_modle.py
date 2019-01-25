#coding=utf8
from selenium import webdriver
import unittest,time,re




#登陆
#def login():
	#ff.switch_to_frame('login-form')
	#ff.find_element_by_id('auto-id-1538195062645').clear()
##auto-id-1538195514727
	#ff.find_element_by_id('auto-id-1538195062645').send_keys('testingwtb')
	#ff.find_element_by_id('auto-id-1538195062609').clear()
	#ff.find_element_by_id('auto-id-1538195062609').send_keys('a123456')
	#ff.find_element_by_id('auto-id-1538195062609').click()
#退出
#def logout():
	#ff.find_element_by_link_text(u'退出').click()
	#ff.quit()

ff = webdriver.Firefox()
ff.get('http://www.126.com')
ff.switch_to_frame('x-URS-iframe')
print 'ok'
ff.quit()
#login()
#ogout()

