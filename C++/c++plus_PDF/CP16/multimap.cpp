#include<iostream>
#include<string>
#include<map>
#include<algorithm>

typedef int KeyType;
//使用Pair生成一个 键为int ,数据为string的值对象;
typedef std::pair<const KeyType, std::string> Pair;
//使用MapCode生成一个 键为int ,数据为string的multimap对象;
typedef std::multimap<KeyType, std::string> MapCode;

int main()
{
	using namespace std;
	MapCode codes;

	//多MAP容器,插入一个值对象,键为415,数据为San Francisc;
	codes.insert(Pair(415, "San Francisco"));
	codes.insert(Pair(510, "Oakland"));
	codes.insert(Pair(718, "Brooklyn"));
	codes.insert(Pair(718, "Staten Island"));
	codes.insert(Pair(415, "San Rafael"));
	codes.insert(Pair(510, "Berkeley"));
 
	cout << "Number of cities with area code 415: " << codes.count(415) << endl;
	cout << "Number of cities with area code 718: " << codes.count(718) << endl;
	cout << "Number of cities with area code 510: " << codes.count(510) << endl;
	cout << "Area Code  City\n";
	//创建一个多map的
	MapCode::iterator it;
	//按顺序输出 int 编号和 string 城市名字
	for(it = codes.begin(); it != codes.end(); ++it)
		cout << "	" << (*it).first << "	" << (*it).second << endl;

	//创建一个pair对象,方便调用equal_range()方法,
	pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718);
	cout << "Cities with area code 718:\n";
	for(it = range.first; it != range.second; ++it)
		cout << (*it).second << endl;

	return 0;

}