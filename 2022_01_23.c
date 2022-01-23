#define _CRT_SECURE_NO_WARNINGS
/*memmoveÄ£ÄâÊµÏÖ*/
//#include<stdio.h>
//#include<assert.h>
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	void* s = dest;
//	assert(dest && src);
//	if (src < dest)
//	{
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//	else
//	{
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	return s;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6};
//	my_memmove(arr1, arr1+1, 3 * sizeof(arr1[0]));
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}
