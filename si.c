#define _CRT_SECURE_NO_WARNINGS
#include "si.h"

//检查是否扩容
void check_capacity(Stu* ps)
{
	assert(ps);
	if (ps->sz == ps->capacity)
	{
		//增加容量
		StuInfo* tmp = (StuInfo*)realloc(ps->a, (ps->capacity + 2) * sizeof(StuInfo));
		assert(tmp);
		ps->a = tmp;
		ps->capacity += 2;
		printf("扩容成功\n");
	}
}
//加载有效数据
void LoadData(Stu* ps)
{
	//从文件加载数据,以只读的方式打开文件。
	FILE* pf = fopen("学生信息.txt", "rb");
	if (pf == NULL)
	{
		printf("打开文件错误\n");
		return;
	}
	//读取文件
	StuInfo buf = { 0 };
	//以二进制的形式。每次从pf指向的文件读一个StuInfo大小的学生信息 到临时变量buf中
	while (fread(&buf, sizeof(StuInfo), 1, pf))
	{
		//检查信息表是否满了
		check_capacity(ps);
		//再将buf转移到信息表中。
		ps->a[ps->sz] = buf;
		ps->sz++;
	}
	//关闭文件
	fclose(pf);
	pf = NULL;

}
//初始化结构体，也就是实际开辟内存空间
void InitStu(Stu* ps)
{
	assert(ps);
	ps->sz = 0;
	StuInfo* tmp = (StuInfo*)malloc(sizeof(StuInfo) * Init_SZ);
	assert(tmp);
	ps->a = tmp;
	ps->capacity = Init_SZ;
	//加载数据到内存，也就是将文件的数据读到信息表。
	LoadData(ps);
}
//销毁学生信息表
void DestoryStu(Stu* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->sz = 0;
}

//增加学生到信息表
void AddStu(Stu* ps)
{
	assert(ps);
	//检查信息表是否已经满了，满了就增加容量
	check_capacity(ps);

	//输入联系人
	printf("请输入学号:");
	scanf("%d", &(ps->a[ps->sz].number));
	printf("请输入名字:");
	scanf("%s", ps->a[ps->sz].name);
	printf("请输入性别:");
	scanf("%s", ps->a[ps->sz].sex);
	printf("请输入成绩:");
	scanf("%d", &(ps->a[ps->sz].score));

	ps->sz++;
	printf("增加学生信息成功\n");
}
//展示信息表
void ShowStu(Stu* ps)
{
	assert(ps);
	int i = 0;
	printf("%-5s\t%-5s\t%-5s\t%-5s\n", "学号", "名字", "性别", "成绩");
	for (i = 0; i < ps->sz; i++)
	{
		printf("%-5d\t%-5s\t%-5s\t%-5d\n", 
			ps->a[i].number, ps->a[i].name,ps->a[i].sex,ps->a[i].score);
	}
}
//将信息表的数据写入文件
void SaveStu(Stu* ps)
{
	//打开文件
	FILE* pf = fopen("学生信息.txt", "wb");
	if (pf == NULL)
	{
		printf("SaveContact:: %s\n", strerror(errno));
		return;
	}
	//写文件
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		fwrite(ps->a + i, sizeof(StuInfo), 1, pf);
	}
	printf("保存信息成功\n");
	//关闭文件
	fclose(pf);
	pf = NULL;
}
//将女生 和 男生分开
int SeparateStu(Stu* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		if (strcmp(ps->a[i].sex, ps->a[0].sex))
		{
			return i;
		}
	}
	return ps->sz;
}
//排序 信息表
int cmp_sex(const void* e1, const void* e2)
{
	return strcmp(((StuInfo*)e2)->sex, ((StuInfo*)e1)->sex);
}

int cmp_girl(const void* e1, const void* e2)
{
	return ((StuInfo*)e2)->score-((StuInfo*)e1)->score;
}

int cmp_man(const void* e1, const void* e2)
{
	return ((StuInfo*)e2)->score - ((StuInfo*)e1)->score;
}

void SortStu(Stu* ps)
{
	assert(ps);

	//1.对全体学生 先 按性别排序
	qsort(ps->a, ps->sz, sizeof(ps->a[0]), cmp_sex);

	//2.再对女生 按 成绩 排序
	qsort(ps->a, SeparateStu(ps), sizeof(ps->a[0]), cmp_girl);

	//3.再对男生 按 成绩 排序
	qsort(ps->a+SeparateStu(ps),(ps->sz) - SeparateStu(ps), sizeof(ps->a[0]), cmp_man);
	printf("排序完成\n");
}
//女生合格率
void GirlPass(Stu* ps)
{
	assert(ps);
	int lenth = SeparateStu(ps);
	int i = 0;
	int count = 0;
	for (i = 0; i < lenth; i++)
	{
		if (ps->a[i].score >= 6)
		{
			count++;
		}
	}
	double pass = (count*1.0 / lenth);
	printf("女生及格率为%%%.2f\n", pass * 100);
	////打开文件
	//FILE* pf = fopen("学生信息.txt", "wb");
	//if (pf == NULL)
	//{
	//	printf("SaveContact:: %s\n", strerror(errno));
	//	return;
	//}
	////写文件
	//fwrite(&pass, sizeof(pass), 1, pf);
	////关闭文件
	//fclose(pf);
	//pf = NULL;
}
//男生合格率
void ManPass(Stu* ps)
{
	assert(ps);
	int lenth = SeparateStu(ps);
	int i = 0;
	int count = 0;
	for (i = lenth; i < ps->sz; i++)
	{
		if (ps->a[i].score >= 6)
		{
			count++;
		}
	}
	double pass = (count * 1.0 / (ps->sz - lenth));
	printf("男生及格率为%%%.2f\n", pass * 100);
}
//总的平均分
void TotalScore(Stu* ps)
{
	assert(ps);
	int i = 0;
	int sum = 0;
	for (i = 0; i < ps->sz; i++)
	{
		sum += ps->a[i].score;
	}
	double totalscore = sum * 1.0 / ps->sz;
	printf("全班平均成绩为%.2f\n", totalscore);
}