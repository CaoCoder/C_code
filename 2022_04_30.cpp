
//namespace N1
//{
//	int a;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//}
//namespace N2
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	namespace N3
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//namespace N1
//{
//	int Mul(int left, int right)
//	{
//		return left * right;
//	}
//}

//namespace N
//{
//	int a = 10;
//	int b = 20;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	int Sub(int left, int right)
//	{
//		return left - right;
//	}
//}
//using N::b;
//using namespace N;
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d", b);
//	printf("%d", Add(10, 20));
//	return 0;
//}
//int main()
//{
//	cout << "Hello World!!" << endl;
//	return 0;
//}
#include <iostream>
using namespace std;

//int main()
//{
//	int a;
//	double b;
//	char c;
//	std::cin >> a;
//	std::cin >> b >> c;
//
//	std::cout << b << " " << c << std::endl;
//	return 0;
//}
//void TestFunc(int a , int b = 20, int c = 30)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//int main()
//{
//	TestFunc(1);
//}
//КЏЪ§жиди
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
//long Add(long left, long right)
//{
//	return left + right;
//}
//void TestFunc(int a = 10) 
//{
//	cout << "void TestFunc(int)" << endl;
//}
//void TestFunc(int a) 
//{
//	cout << "void TestFunc(int)" << endl;
//}
//int main()
//{
//	/*cout << Add(10, 20) << endl;
//	cout << Add(10.0, 20.0) << endl;
//	cout << Add(10L, 20L) << endl;*/
//	TestFunc();
//	TestFunc(1);
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	int& b = a;
//	printf("%p\n", a);
//	printf("%p\n", ra);
//	printf("%p\n", b);
//}
//int main()
//{
//	const int a = 10;
//	const int& ra = a;
//	const int& b = 10;
//	double d = 12.34;
//	/*int& rd = d;*/
//	const int& rd = d;
//}
//void swap(int& ra, int& rb)
//{
//	int t = 0;
//	t = ra;
//	ra = rb;
//	rb = t;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	swap(a, b);
//	printf("%d %d", a, b);
//}
//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1,2) is :" << ret << endl;
//	return 0;
//}
#include <iostream>
using namespace std;

//int& Add(int a, int b) {
//	static int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	/*Add(3, 4);*/
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}
//int& Count()
//{
//	 int n = 0;
//		n++;
//	// ...
//	return n;
//}
//int main()
//{
//	int a = Count();
//	cout << a << endl;
//	return 0;
//}