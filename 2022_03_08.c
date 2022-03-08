#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
///*Ä£Äâmemmoveº¯Êý*/
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	assert(dest && src);
//	
//	if (dest > src)
//	{
//		char* p = src;
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//		return p;
//	}
//	else
//	{
//		char* p = dest;
//
//		while (count)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//			count--;
//		}
//		return p;
//	}
//	
//}
//int main()
//{
//	char arr[] = "helloworld";
//	char* p = my_memmove(arr, arr+3, 5);
//	printf("%s",p);
//	return 0;
//}
/**/