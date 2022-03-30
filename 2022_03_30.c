//用栈实现队列

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




typedef struct {
    ST st1;
    ST st2;

} MyQueue;


MyQueue* myQueueCreate()
{
    MyQueue* newQueue = (MyQueue*)malloc(sizeof(MyQueue));
    assert(newQueue);
    StackInit(&newQueue->st1);
    StackInit(&newQueue->st2);

    return newQueue;

}

void myQueuePush(MyQueue* obj, int x)
{
    assert(obj);
    StackPush(&obj->st2, x);

}

int myQueuePop(MyQueue* obj)
{
    assert(obj);
    if (StackEmpty(&obj->st1))
    {
        while (!StackEmpty(&obj->st2))
        {
            StackPush(&obj->st1, StackTop(&obj->st2));
            StackPop(&obj->st2);
        }
    }
    int top = 0;
    if (!StackEmpty(&obj->st1))
    {
        top = StackTop(&obj->st1);
        StackPop(&obj->st1);
    }
    return top;
}

int myQueuePeek(MyQueue* obj)
{
    assert(obj);
    if (StackEmpty(&obj->st1))
    {
        while (!StackEmpty(&obj->st2))
        {
            StackPush(&obj->st1, StackTop(&obj->st2));
            StackPop(&obj->st2);
        }
    }

    if (!StackEmpty(&obj->st1))
    {
        return StackTop(&obj->st1);
    }
    return 0;
}

bool myQueueEmpty(MyQueue* obj)
{
    return StackEmpty(&obj->st1) && StackEmpty(&obj->st2);
}

void myQueueFree(MyQueue* obj)
{
    StackDestroy(&obj->st1);
    StackDestroy(&obj->st2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/