#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
using namespace std;
const int N = 5;
class student
{
	char n_name[10];
	char n_numble[5];
	char n_sex[3];
	float score[4];//score[0]Ӣ��ɼ���score[1]��ѧ�ɼ�,score[2]���ĳɼ���score[3]ƽ����
public:
	student();
	student(char name[], char numble[], char sex[], float a, float b, float c);
	student(student& s);
	void input();//����ѧ����Ϣ��������ѧ�ţ��Ա�Ӣ���ѧ������
	float pj();//��ȡƽ����

	void stu_delete(student stu[]);//ɾ��
	void stu_find(student stu[]);
	void dispaly();//��ʾѧ����Ϣ��������ѧ�ţ��Ա�Ӣ���ѧ�����ģ�ƽ����
};
student::student()
{
	strcpy(n_numble, "000");
	strcpy(n_name, "noname");
	strcpy(n_sex, "male");
	score[0] = 88;
	score[1] = 99;
	score[2] = 95;
	score[3] = 94;
}
student::student(char name[], char numble[], char sex[], float a, float b, float c)
{
	strcpy(n_name, name);
	strcpy(n_numble, numble);
	strcpy(n_sex, sex);
	score[0] = a;
	score[1] = b;
	score[2] = c;
	score[3] = (score[0] + score[1] + score[2]) / 3.0;
}
student::student(student& s)
{
	strcpy(n_name, s.n_name);
	strcpy(n_numble, s.n_numble);
	strcpy(n_sex, s.n_sex);
	score[0] = s.score[0];
	score[1] = s.score[1];
	score[2] = s.score[2];
	score[3] = (score[0] + score[1] + score[2]) / 3.0;

}
void student::input()
{
	cout << "����ѧ����Ϣ��" << endl;
	cout << "����������������ѧ�ţ��Ա�Ӣ���ѧ������" << endl;
	cin >> n_name >> n_numble >> n_sex >> score[0] >> score[1] >> score[2];
	score[3] = (score[0] + score[1] + score[2]) / 3.0;
}

float student::pj()
{
	return score[3];
}

void student::stu_delete(student stu[])
{
	student t;
	int i, k, j;
	char d_numble[5];
	cout << "������Ҫɾ����ѧ��ѧ��:";
	cin >> d_numble;
	for (i = 0; i < N + 1; i++)
	{
		j = i;
		k = strcmp(stu[i].n_numble, d_numble);
		if (k == 0 && i != N)
		{
			for (; j < N; j++)
				stu[j] = stu[j + 1];
		}
		if (k == 0 && i == N)
		{
			strcpy(stu[N].n_numble, "0000");
			strcpy(stu[N].n_name, "noname");
			strcpy(stu[N].n_sex, "��");
			stu[N].score[0] = 0;
			stu[N].score[1] = 0;
			stu[N].score[2] = 0;
			stu[N].score[3] = 0;
		}
	}
}
void student::stu_find(student stu[])
{
	int i, k;
	char d_numble[5];
	cout << "������Ҫ��ѯѧ����ѧ��:";
	cin >> d_numble;
	for (i = 0; i < N + 1; i++)
	{
		k = strcmp(stu[i].n_numble, d_numble);
		if (k == 0)
		{
			stu[i].dispaly();

		}
	}
}
void student::dispaly()
{
	cout << "����:" << n_name << " " << "ѧ��:" << n_numble << " " << "�Ա�:" << n_sex << " " << "Ӣ��:" << score[0] << " " << "��ѧ:" << score[1] << " " << "����:" << score[2] << " " << "ƽ����:" << score[3] << endl;
}
class manage_stu
{
	//private:
	student stu[N + 1];//����N+1��ѧ���ռ�
public:
	void input_stu();//����N��ѧ����Ϣ

	void delete_stu();//ɾ��ָ��ѧ�ŵ�ѧ����Ϣ
	void find_stu();//����ָ��ѧ�ŵ�ѧ������ʾ
	void total_stu();//�ֱ���ÿ���˵��ܷ�
	void sort_stu();//���ָܷߵ����������Ľ����ʾ�������ļ�sortstu.txt
	void display_stu();//��ʾN��ѧ����Ϣ
};
void manage_stu::input_stu()//����N��ѧ����Ϣ
{
	int i;
	for (i = 0; i < N; i++)
		stu[i].input();
}
void manage_stu::delete_stu()//ɾ��ָ��ѧ�ŵ�ѧ����Ϣ
{
	student r;
	r.stu_delete(stu);
}
void manage_stu::find_stu()//����ָ��ѧ�ŵ�ѧ������ʾ
{
	student t;
	t.stu_find(stu);
}
void manage_stu::total_stu()//�ֱ���ÿ���˵��ܷ�
{
	int i;
	for (i = 0; i < N + 1; i++)
		stu[i].pj();
}
void manage_stu::sort_stu()
{
	int i, j;
	student a;
	for (i = 0; i < N - 1; i++)
	{
		for (j = i; j < N; j++)
		{
			if (stu[i].pj() < stu[j].pj())
			{
				a = stu[i];
				stu[i] = stu[j];
				stu[j] = a;
			}
		}
	}
}
void manage_stu::display_stu()//��ʾN��ѧ����Ϣ
{
	student t;
	int i;
	for (i = 0; i < N; i++)
		stu[i].dispaly();
}
void main()
{

	int i = 1, c;
	manage_stu s;
	while (i)
	{
		cout << "ѧ������ϵͳ��" << endl;
		cout << "1��¼��ѧ����Ϣ" << N << "��ѧ����Ϣ" << endl;
		cout << "2������" << endl;
		cout << "3������" << endl;
		cout << "4��ɾ��" << endl;
		cout << "5����ʾ����ѧ����Ϣ" << endl;
		cout << "6���˳�ϵͳ" << endl;
		cout << "��ѡ��(1--6):";
		cin >> c;
		switch (c)
		{
		case 1:s.input_stu(); break;
		case 2:s.find_stu(); break;
		case 3:s.sort_stu(); break;
		case 4:s.delete_stu(); break;
		case 5:s.display_stu(); break;
		case 6:i = 0;
		}
	}
}