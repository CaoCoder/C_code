#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void replacespace(char* str, int length)
{
	int spacecnt = 0;
	char* cur = str;
	while (*cur)
	{
		if (*cur == ' ')
		{
			spacecnt++;
		}
		cur++;
	}
	int newlen = length + spacecnt * 2;
	int end1 = length - 1;
	int end2 = newlen - 1;
	while (end1 != end2)
	{
		if (str[end1] != ' ')
		{
			str[end2--] = str[end1--];
		}
		else
		{
			str[end2--] = '0';
			str[end2--] = '2';
			str[end2--] = '%';
			end1--;
		}
	}
}
int main()
{
	char arr[] = "we are ha";
	int len = strlen(arr);
	replacespace(arr, len);
	printf("%s", arr);
	return 0;
}
/*memmove函数模拟实现*/

void* memmove(void* dst, const void* src, size_t count)

{

	void* ret = dst;

	​

		if (dst <= src || (char*)dst >= ((char*)src + count)) {

			/*

			* Non-Overlapping Buffers

			* copy from lower addresses to higher addresses

			*/

			while (count--) {

				*(char*)dst = *(char*)src;

				dst = (char*)dst + 1;

				src = (char*)src + 1;

			}

		}

		else {

			/*

			* Overlapping Buffers

			* copy from higher addresses to lower addresses

			*/

			dst = (char*)dst + count - 1;

			src = (char*)src + count - 1;

			​

				while (count--) {

					*(char*)dst = *(char*)src;

					dst = (char*)dst - 1;

					src = (char*)src - 1;

				}

		}

	​

		return(ret);

}