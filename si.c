#define _CRT_SECURE_NO_WARNINGS
#include "si.h"

//����Ƿ�����
void check_capacity(Stu* ps)
{
	assert(ps);
	if (ps->sz == ps->capacity)
	{
		//��������
		StuInfo* tmp = (StuInfo*)realloc(ps->a, (ps->capacity + 2) * sizeof(StuInfo));
		assert(tmp);
		ps->a = tmp;
		ps->capacity += 2;
		printf("���ݳɹ�\n");
	}
}
//������Ч����
void LoadData(Stu* ps)
{
	//���ļ���������,��ֻ���ķ�ʽ���ļ���
	FILE* pf = fopen("ѧ����Ϣ.txt", "rb");
	if (pf == NULL)
	{
		printf("���ļ�����\n");
		return;
	}
	//��ȡ�ļ�
	StuInfo buf = { 0 };
	//�Զ����Ƶ���ʽ��ÿ�δ�pfָ����ļ���һ��StuInfo��С��ѧ����Ϣ ����ʱ����buf��
	while (fread(&buf, sizeof(StuInfo), 1, pf))
	{
		//�����Ϣ���Ƿ�����
		check_capacity(ps);
		//�ٽ�bufת�Ƶ���Ϣ���С�
		ps->a[ps->sz] = buf;
		ps->sz++;
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;

}
//��ʼ���ṹ�壬Ҳ����ʵ�ʿ����ڴ�ռ�
void InitStu(Stu* ps)
{
	assert(ps);
	ps->sz = 0;
	StuInfo* tmp = (StuInfo*)malloc(sizeof(StuInfo) * Init_SZ);
	assert(tmp);
	ps->a = tmp;
	ps->capacity = Init_SZ;
	//�������ݵ��ڴ棬Ҳ���ǽ��ļ������ݶ�����Ϣ��
	LoadData(ps);
}
//����ѧ����Ϣ��
void DestoryStu(Stu* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->sz = 0;
}

//����ѧ������Ϣ��
void AddStu(Stu* ps)
{
	assert(ps);
	//�����Ϣ���Ƿ��Ѿ����ˣ����˾���������
	check_capacity(ps);

	//������ϵ��
	printf("������ѧ��:");
	scanf("%d", &(ps->a[ps->sz].number));
	printf("����������:");
	scanf("%s", ps->a[ps->sz].name);
	printf("�������Ա�:");
	scanf("%s", ps->a[ps->sz].sex);
	printf("������ɼ�:");
	scanf("%d", &(ps->a[ps->sz].score));

	ps->sz++;
	printf("����ѧ����Ϣ�ɹ�\n");
}
//չʾ��Ϣ��
void ShowStu(Stu* ps)
{
	assert(ps);
	int i = 0;
	printf("%-5s\t%-5s\t%-5s\t%-5s\n", "ѧ��", "����", "�Ա�", "�ɼ�");
	for (i = 0; i < ps->sz; i++)
	{
		printf("%-5d\t%-5s\t%-5s\t%-5d\n", 
			ps->a[i].number, ps->a[i].name,ps->a[i].sex,ps->a[i].score);
	}
}
//����Ϣ�������д���ļ�
void SaveStu(Stu* ps)
{
	//���ļ�
	FILE* pf = fopen("ѧ����Ϣ.txt", "wb");
	if (pf == NULL)
	{
		printf("SaveContact:: %s\n", strerror(errno));
		return;
	}
	//д�ļ�
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		fwrite(ps->a + i, sizeof(StuInfo), 1, pf);
	}
	printf("������Ϣ�ɹ�\n");
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}
//��Ů�� �� �����ֿ�
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
//���� ��Ϣ��
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

	//1.��ȫ��ѧ�� �� ���Ա�����
	qsort(ps->a, ps->sz, sizeof(ps->a[0]), cmp_sex);

	//2.�ٶ�Ů�� �� �ɼ� ����
	qsort(ps->a, SeparateStu(ps), sizeof(ps->a[0]), cmp_girl);

	//3.�ٶ����� �� �ɼ� ����
	qsort(ps->a+SeparateStu(ps),(ps->sz) - SeparateStu(ps), sizeof(ps->a[0]), cmp_man);
	printf("�������\n");
}
//Ů���ϸ���
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
	printf("Ů��������Ϊ%%%.2f\n", pass * 100);
	////���ļ�
	//FILE* pf = fopen("ѧ����Ϣ.txt", "wb");
	//if (pf == NULL)
	//{
	//	printf("SaveContact:: %s\n", strerror(errno));
	//	return;
	//}
	////д�ļ�
	//fwrite(&pass, sizeof(pass), 1, pf);
	////�ر��ļ�
	//fclose(pf);
	//pf = NULL;
}
//�����ϸ���
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
	printf("����������Ϊ%%%.2f\n", pass * 100);
}
//�ܵ�ƽ����
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
	printf("ȫ��ƽ���ɼ�Ϊ%.2f\n", totalscore);
}