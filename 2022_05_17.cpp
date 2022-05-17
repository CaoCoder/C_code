#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	默认构造函数
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	bool operator==(const Date& d2)
//	{
//		return _year == d2._year
//			&& _month == d2._month
//			&& _day == d2._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//这里为什么要传引用？
//bool operator== (const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//
//int main()
//{
//
//	Date d1(1,1,1);
//	Date d2(2,2,2);
//	int a = (d1 == d2);
//	cout << a << endl;
//	return 0;
//}
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
	///*bool operator < (const Date& d)
	//{
	//	if ((_year < d._year)
	//		|| (_year == d._year && _month < d._month)
	//		|| (_year == d._year && _month == d._month && d._day < d._day))
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}
	//Date& operator=(const Date& d)
	//{
	//	if (this != &d)
	//	{
	//		_year = d._year;
	//		_month = d._month;
	//		_day = d._day;
	//	}
	//	return *this;
	//}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(1, 1, 1);
//	Date d2(2, 2, 2);
//	d1 = d2;
//
//	return 0;
//}
//class Date
//{
//public:
//	//获取某年某月的天数
//	int GetMonthDay(int year, int month)
//	{
//		static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		int day = days[month];
//		if (month == 2 
//			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//		{
//			day += 1;
//		}
//		return day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
