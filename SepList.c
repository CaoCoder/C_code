#include "SepList.h"
//������ĵȽӿں���
void SepListInit(SL* ps)
{
	memset(ps->a, 0, sizeof(SQDataType) * N);
	ps->size = 0;
}