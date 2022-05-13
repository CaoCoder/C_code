//#include<iostream>
//using namespace std;
////int main()
////{
////	int array[] = { 1,2,3,4,5,6,7,8,9 };
//	/*for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
//		array[i] *= 2;*/
//		//范围for
//		//自动取数组中的数据，!!!赋值给e!!只是拷贝，自动判断结束。
//	//所以需要用引用。用同一块地址
//	//for (auto& e : array)
//	//{
//	//	e *= 2;
//	//	//cout << e << endl;
//	//}
//	//for (auto& e : array)
//	//{
//	//	cout << e << endl;
//	//}
//	//这样写也可以，不一定非要写为auto
////	for (int& e : array)
////	{
////		cout << e << endl;
////	}
////	return 0;
////}
////1.atuo不能做形式参数，因为推断不出来他的具体类型，必须函数调用的是才能推出来。
////2.atuo也不能用作函数返回值，必须指定类型。
////3.auto也不能用来声明数组。
//class Date
//{
//
//};
//int main()
//{
//	Date d1;
//	d1.Init(2022, 5, 11);
//	return 0;
//}