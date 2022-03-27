#define _CRT_SECURE_NO_WARNINGS
typedef int STDataType;

typedef struct Stack
{
    STDataType* a;//����ṹ
    int top;//ջ��λ��
    int capacity;//ջ���������
}ST;
//��ʼ���ṹ��
void StackInit(ST* ps);
//ѹջ
void StackPush(ST* ps, STDataType x);
//��ջ
void StackPop(ST* ps);
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps);
//����ջ��λ�õ�ֵ
STDataType StackTop(ST* ps);
//�õ�ջ�Ĵ�С
int StackSize(ST* ps);
//����ջ
void StackDestory(ST* ps);

//��ʼ���ṹ��
void StackInit(ST* ps)
{
    assert(ps);
    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}
//����ջ
void StackDestory(ST* ps)
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
    //��������
    if (ps->top == ps->capacity)
    {
        int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        STDataType* new = (STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);
        if (new == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        ps->a = new;
        ps->capacity = newCapacity;
    }
    ps->a[ps->top] = x;
    ps->top++;
}
//��ջ
void StackPop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    --ps->top;
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps)
{
    assert(ps);
    return ps->top == 0;
}
//����ջ��λ�õ�ֵ
STDataType StackTop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    return ps->a[ps->top - 1];
}
//�õ�ջ�Ĵ�С
int StackSize(ST* ps)
{
    assert(ps);
    return ps->top;
}


typedef struct
{
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
    StackPush(&obj->st1, x);

}

int myQueuePop(MyQueue* obj)
{
    assert(obj);
    if (StackEmpty(&obj->st2))
    {
        while (!StackEmpty(&obj->st1))
        {
            StackPush(&obj->st2, StackTop(&obj->st1));
            StackPop(&obj->st1);
        }
    }
 
    int ttop = 0;
    if (!StackEmpty(&obj->st2))
    {
        ttop = StackTop(&obj->st2);
        StackPop(&obj->st2);
    }
    return ttop;
}

int myQueuePeek(MyQueue* obj)
{
    assert(obj);
    if (StackEmpty(&obj->st2))
    {
        while (!StackEmpty(&obj->st1))
        {
            StackPush(&obj->st2, StackTop(&obj->st1));
            StackPop(&obj->st1);
        }
    }
    int ttop = 0;
    if (!StackEmpty(&obj->st2))
    {
        ttop = StackTop(&obj->st2);
    }
    return ttop;

}

bool myQueueEmpty(MyQueue* obj)
{
    assert(obj);
    return StackEmpty(&obj->st1) && StackEmpty(&obj->st2);


}

void myQueueFree(MyQueue* obj)
{
    assert(obj);
    StackDestory(&obj->st1);
    StackDestory(&obj->st2);
    free(obj);
}
