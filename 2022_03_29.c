
typedef char STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//初始化结构体
void StackInit(ST* ps);
//销毁结构体
void StackDestroy(ST* ps);
//压栈
void StackPush(ST* ps, STDataType x);
//出栈
void StackPop(ST* ps);
//得到栈顶的值
STDataType StackTop(ST* ps);
//判断栈是否为空
bool StackEmpty(ST* ps);
//得到栈的长度
int StackSize(ST* ps);


//初始化结构体
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
//销毁结构体
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;


}
//压栈
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
//得到栈的长度
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