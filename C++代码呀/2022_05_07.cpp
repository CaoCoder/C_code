#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string.h>
////一定要加分号。
//using namespace std;

//struct Student
//{
//	void SetStudentInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//class Person
//{
//	public:
//		void showInfo()
//		{
//			cout << _name << "_" << _sex << "_" << _age << endl;
//		}
//	public:
//		char* _name;
//		char* _sex;
//		int _age;
//};
//#include <iostream>
//using namespace std;
//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//	
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	return 0;
//}
//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	*a = 20;
//	*b = 30;
//	 c = 40;
//
//	return 0;
//}
#include <iostream>
using namespace std;
//void TestFor()
//{
//	int array[] = { 1,2,3,4,5 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//	{
//		array[i] *= 2;
//	}
//	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
//	{
//		cout << *p << endl;
//	}
//}
//void TestFor()
//{
//	int array[] = { 1,2,3,4,5 };
//	//for (auto& e : array)
//	//	e *= 2;
//	//for (auto e : array)
//	//	cout << e << " ";
//	for (auto& e : array)
//		cout << e << endl;
//}
//int main()
//{
//	TestFor();
//	return 0;
//}
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(NULL);
	f((int*)NULL);
	return 0;
}