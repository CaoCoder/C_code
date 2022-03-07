#define _CRT_SECURE_NO_WARNINGS
/*模拟strstr函数*/
//#include<stdio.h>
//#include<assert.h>
//char* my_strstr(const char* str1, const char* str2)
//{
//    char* cp = (char*)str1;
//    char* s1, * s2;
//    if (!*str2)
//        return((char*)str1);
//    while (*cp)
//    {
//        s1 = cp;
//        s2 = (char*)str2;
//        while (*s1 && *s2 && !(*s1 - *s2))
//        {
//            s1++, s2++;
//        }
//        if (!*s2)
//            return(cp);
//        cp++;
//    }
//    return(NULL);
//}
//int main()
//{
//	char arr[] = "bbcd";
//	char arr1[] = "bcd";
//	printf("%s", my_strstr(arr, arr1));
//	return 0;
//}
/*模拟memmove函数*/
//#include<stdio.h>
//#include<string.h>
//void* memmove(void* dest, const void* src, size_t count)
//{
//
//}
//int main()
//{
//	int arr[] = { 1,2,3,4 };
//	int arr1[] = { 4,5,6,7 };
//	memmove(arr, arr1, 2*sizeof(int));
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	return 0;
//}
#include<stdio.h>
#include<string.h>
int  main()
{
    char a[5][11] = { '\0' };
    char m[11] = { '\0' };
    int i = 0, c = 0;
    while (1)
    {
        scanf("%s", a[i]);
        if (a[i][0] == '#')
            break;
        c++;
        i++;
    }
    for (i = 0; i < c - 1; i++)
    {
        for (int j = 0; j < c - i - 1; j++)
        {
            if (strlen(a[j]) > strlen(a[j + 1]))
                //*(a+1)
            {
                strcpy(m, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], m);
            }
        }
    }
    for (i = 0; i < c; i++)
        printf("%s ", a[i]);
    return 0;
}

