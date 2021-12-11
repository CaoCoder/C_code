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
	float score[4];//score[0]英语成绩，score[1]数学成绩,score[2]语文成绩，score[3]平均分
public:
	student();
	student(char name[], char numble[], char sex[], float a, float b, float c);
	student(student& s);
	void input();//输入学生信息：姓名，学号，性别，英语，数学，语文
	float pj();//获取平均分

	void stu_delete(student stu[]);//删除
	void stu_find(student stu[]);
	void dispaly();//显示学生信息：姓名，学号，性别，英语，数学，语文，平均分
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
	cout << "输入学生信息：" << endl;
	cout << "请依次输入姓名，学号，性别，英语，数学，语文" << endl;
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
	cout << "请输入要删除的学生学号:";
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
			strcpy(stu[N].n_sex, "男");
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
	cout << "请输入要查询学生的学号:";
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
	cout << "姓名:" << n_name << " " << "学号:" << n_numble << " " << "性别:" << n_sex << " " << "英语:" << score[0] << " " << "数学:" << score[1] << " " << "语文:" << score[2] << " " << "平均分:" << score[3] << endl;
}
class manage_stu
{
	//private:
	student stu[N + 1];//定义N+1名学生空间
public:
	void input_stu();//输入N名学生信息

	void delete_stu();//删除指定学号的学生信息
	void find_stu();//查找指定学号的学生并显示
	void total_stu();//分别求每个人的总分
	void sort_stu();//按总分高低排序，排序后的结果显示并生成文件sortstu.txt
	void display_stu();//显示N名学生信息
};
void manage_stu::input_stu()//输入N名学生信息
{
	int i;
	for (i = 0; i < N; i++)
		stu[i].input();
}
void manage_stu::delete_stu()//删除指定学号的学生信息
{
	student r;
	r.stu_delete(stu);
}
void manage_stu::find_stu()//查找指定学号的学生并显示
{
	student t;
	t.stu_find(stu);
}
void manage_stu::total_stu()//分别求每个人的总分
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
void manage_stu::display_stu()//显示N名学生信息
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
		cout << "学生管理系统：" << endl;
		cout << "1、录入学生信息" << N << "名学生信息" << endl;
		cout << "2、查找" << endl;
		cout << "3、排序" << endl;
		cout << "4、删除" << endl;
		cout << "5、显示几名学生信息" << endl;
		cout << "6、退出系统" << endl;
		cout << "请选择(1--6):";
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