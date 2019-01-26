[toc]
# 测试模块
unittest测试模块可以用命令行启动测试，可以从模块，类甚至单独的测试函数启动:
```bash
python -m unittest test_module1 test_module2
python -m unittest test_module.TestClass
python -m unittest test_module.TestCase.test_method
```
测试模块可以通过文件路径来指定
python -m unittest tests/test_something.py

测试模块的名字是将文件路径的py去掉，并将分隔符转换为‘.’号。
如果setUp()成功，那么无论test method 是否成功，都将执行tearDown()
如果setUp()失败，那么后面将无法执行

builde testsuits:
```python
def suite():
	suite = unittest.TestSuite()
	suite.addTest(BasicExample('test_isupper'))
	suite.addTest(BasicExample('test_split'))
	return suite

if __name__=='__main__'
	runner = unittest.TextTestRunner()
	runner.run(suite())
```

# 错误测试
使用skip(),可以跳过个别的测试模块或者整个classed。并且可以将执行失败的用例标记为‘预期中的错误’,这样就不会在TestResult中标记为失败

使用skip() 修饰或者conditional variants可以很轻松跳过测试
```python
class MyTestCase(unittest.TestCase):
	@unittest.skip("demonstrating skipping")
	def test_nothing(self):
		self.fail("shouldn't happen")
	
	@unittest.skipif(mylib.__version__ < (1, 3), "not supported in this lobrary version")
	
	def test_format(self):
        # Tests that work for only a certain version of the library.
        pass

    @unittest.skipUnless(sys.platform.startswith("win"), "requires Windows")
    def test_windows_support(self):
        # windows specific testing code
        pass
	
	


