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
//	//1.�޲ι��캯��
//	Date()
//	{}
//	//2.�вι��캯��
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
//	// ����û���ʽ�����˹��캯��������������������
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
//	//��������ʱ�������޲ι��캯��,�������Զ����á�
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
//ʱ����
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
////������
//class Date
//{
//private:
//	//��������
//	int _year;
//	int _month;
//	int _day;
//	//�Զ�������
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}
//�����������
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

/*��������*/

//typedef int DataType;
//class Seqlist
//{
//public:
//	//���캯��
//	Seqlist(int capacity = 10)
//	{
//		_a = (DataType*)malloc(capacity * sizeof(DataType));
//		assert(_a);
//		_size = 0;
//		_capacity = capacity;
//	}
//	//��������
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
//	//Ĭ�Ϲ��캯��
//	String(const char* str = "Hello")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	//��������
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
////���� �˵� ��
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
/*��������*/
//class Date
//{
//public:
//	//Ĭ�Ϲ��캯��
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
////Ĭ�ϵĿ������캯����
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
//	////����Ŀ�������//
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
// ȫ�ֵ�operator==
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
//// ����ᷢ����������س�ȫ�ֵľ���Ҫ��Ա�����ǹ��еģ���ô�������ˣ���װ����α�֤��
//// ������ʵ���������Ǻ���ѧϰ����Ԫ��������߸ɴ����سɳ�Ա������
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