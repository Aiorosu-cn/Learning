#coding=utf-8
import unittest
def suite():
	suite = unittest.TestSuite()
	suite.addTest(BasicExample('test_isupper'))
	suite.addTest(BasicExample('test_split'))
	return suite

if __name__=='__main__':
	runner = unittest.TextTestRunner()
	runner.run(suite())
