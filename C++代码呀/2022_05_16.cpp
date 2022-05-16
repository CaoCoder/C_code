#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//class Date
//{
//public:
//	//1.无参构造函数
//	Date()
//	{}
//	//2.有参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//class Date
//{
//public:
//
//	// 如果用户显式定义了构造函数，编译器将不再生成
//	//Date(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	//创建对象时。调用无参构造函数,编译器自动调用。
//	Date d1;
//
//	return 0;
//}
//class Date
//{
//public:
//	/*Date()
//	{
//		int _year = 1;
//		int _month = 1;
//		int _day = 1;
//	}*/
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d(4);
//	Date d1(4,5);
//	Date d2(4,5,6);
//	return 0;
//}
//时间类
//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hout;
//	int _minute;
//	int _second;
//};
////日期类
//class Date
//{
//private:
//	//内置类型
//	int _year;
//	int _month;
//	int _day;
//	//自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}
//命名风格问题
//class Date
//{
//public:
//	Date(int year)
//	{
//		year = year;
//	}
//private:
//	int year;
//};
//class Date
//{
//public:
//	Date(int year)
//	{
//		_year = year;
//	}
//private:
//	int _year;
//};

/*析构函数*/

//typedef int DataType;
//class Seqlist
//{
//public:
//	//构造函数
//	Seqlist(int capacity = 10)
//	{
//		_a = (DataType*)malloc(capacity * sizeof(DataType));
//		assert(_a);
//		_size = 0;
//		_capacity = capacity;
//	}
//	//析构函数
//	~Seqlist()
//	{
//		if (_a)
//		{
//			free(_a);
//			_a = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	int* _a;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Seqlist L;
//	return 0;
//}
//class String
//{
//public:
//	//默认构造函数
//	String(const char* str = "Hello")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	//析构函数
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
////定义 人的 类
//class Person
//{
//private:
//	String _name;
//	int _age;
//};
//int main()
//{
//	Person p;
//	return 0;
//}
/*拷贝构造*/
//class Date
//{
//public:
//	//默认构造函数
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	Date d2(d1);
//	return 0;
//}
////默认的拷贝构造函数。
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	Date d2(d1);
//	return 0;
//}
//class String
//{
//public:
//	String(const char* str = "Hello")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		assert(_str);
//		strcpy(_str, str);
//	}
//	////错误的拷贝构造//
//	//String(String& s)
//	//{
//	//	_str = s._str;
//	//}
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//	
//private:
//	char* _str;
//};
//int main()
//{
//	String s1("hello");
//	String s2(s1);
//	return 0;
//}
// 全局的operator==
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 这里会发现运算符重载成全局的就需要成员变量是共有的，那么问题来了，封装性如何保证？
//// 这里其实可以用我们后面学习的友元解决，或者干脆重载成成员函数。
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//	&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//int main()
//{
//	Date d1(2018, 9, 26);
//	Date d2(2018, 9, 27);
//	cout << (d1 == d2) << endl;
//}