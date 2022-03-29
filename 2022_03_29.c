
typedef char STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//��ʼ���ṹ��
void StackInit(ST* ps);
//���ٽṹ��
void StackDestroy(ST* ps);
//ѹջ
void StackPush(ST* ps, STDataType x);
//��ջ
void StackPop(ST* ps);
//�õ�ջ����ֵ
STDataType StackTop(ST* ps);
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps);
//�õ�ջ�ĳ���
int StackSize(ST* ps);


//��ʼ���ṹ��
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
//���ٽṹ��
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;


}
//ѹջ
void StackPush(ST* ps, STDataType x)
{

	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* new = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (new == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = new;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
//�õ�ջ�ĳ���
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}


bool isValid(char* s)
{
	ST st;
	StackInit(&st);
	while (*s)
	{

		if (*s == '(' || *s == '{' || *s == '[')
		{
			StackPush(&st, *s);
			s++;
		}
		else
		{
			if (StackEmpty(&st))
			{
				return false;
			}
			char top = StackTop(&st);
			if (*s == ')' && top == '(' || *s == '}' && top == '{' || *s == ']' && top == '[')
			{
				StackPop(&st);
				s++;
			}
			else
			{
				return false;
			}
		}
	}
	if (!StackEmpty(&st))
	{
		return false;
	}
	return true;
	StackDestroy(&st);
}