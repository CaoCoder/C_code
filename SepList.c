#include "SepList.h"
//增产查改等接口函数
void SepListInit(SL* ps)
{
	memset(ps->a, 0, sizeof(SQDataType) * N);
	ps->size = 0;
}