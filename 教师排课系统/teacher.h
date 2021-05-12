#pragma once
#include<iostream>   //输入输出头文件
#include<cstdlib>
#include<fstream>
#include<ctime>
#define N 5          
#define M 3          
#define SIZE 40      
using namespace std;

typedef struct tcnode
{
	char name[20];
	int  expectation;
}tclist, * ptclist;
/*class tcnode
{
public:
	char name[20];		//课程名
	int  expectation;   //优先级
	tcnode* next;
};*/

class linklist		//链表
{
public:
	typedef struct node;
	typedef struct Node;
};

typedef struct node
{
	char name[20];
	char num[20];
	int  work_time;
	tcnode tc[M];
	char cbuf[SIZE];
	struct node* next;		//结构指针
}Tlist, * pTlist;

typedef struct Node
{
	char name[20];
	char num[20];
	int week_time;
	int total_time;
	int priority;
	bool kb;		//是否被选
	struct Node* next;		//指向下一节点的指针
}Clist, * pClist;

/*构建教师类*/
class Teacher
{
public:
	Teacher();
	~Teacher();
	void input();		//删除函数
	void preserve();		//保存函数
	friend void print(Teacher&);	//友元函数(类内声明，类外定义)
	Tlist* pt;

};

/*构建teacher函数*/
Teacher::Teacher()
{
	pt = NULL;
}

/*构建教师删除函数*/
Teacher::~Teacher()
{
	pTlist p;
	while (pt)
	{
		p = pt;
		pt = pt->next;
		delete p;
	}

}

/*构建教师信息的生成函数，用于输入教师信息*/
void Teacher::input()
{
	char tag;		//一个用来判断选择的符合标志
	pTlist p = pt;
	pTlist s;
	int t = 0;
	cout << "请输入教师信息:" << endl;
	cout << "姓名\t教师号\t工作量" << endl;
	do
	{
		if (t >= 1)
		{
			cout << "请输入教师信息:" << endl;
			cout << "姓名\t教师号\t工作量" << endl;
		}
		s = (pTlist)malloc(sizeof(Tlist));
		cin >> s->name >> s->num >> s->work_time;
		cout << "请输入相应课程名及期望值(从高到低,默认不超过3门):" << endl;
		for (int i = 0; i < M; i++)
			cin >> s->tc[i].name >> s->tc[i].expectation;
		fflush(stdin);
		s->next = NULL;
		if (!pt)
		{
			pt = s;
			p = pt;
		}
		else
		{
			p->next = s;
			p = p->next;
		}
		t++;
		cout << "是否继续输入信息:" << endl;
		fflush(stdin);
		cin >> tag;
		system("cls");
	} while (tag == 'y' || tag == 'n');

}

/*构建教师保存函数，用于保存输入的教师信息*/
void Teacher::preserve()
{
	pTlist p = pt;
	char path[20] = "E:\\teacher.txt";		//路径
	char str[50] = { '\0' };
	cout << "请选择保存教师信息文件的路径:" << endl;
	cin >> path;
	ofstream outfile(path);		//将路径信息从内存，写入硬盘保存
	if (!outfile)
	{
		cerr << "保存失败,请检查所选路径是否正确!" << endl;
		return;
	}
	sprintf_s(str, "姓名\t教师号\t工作量\n");
	outfile.write((char*)str, strlen(str));		//将字符串以字符的形式写入文件，
	while (p)
	{
		sprintf_s(str, "%s\t%s\t%d\n", p->name, p->num, p->work_time);
		outfile.write((char*)str, strlen(str));		
		sprintf_s(str, "对相应课程的期望值:\n");
		outfile.write((char*)str, strlen(str));
		for (int i = 0; i < M; i++)
		{
			sprintf_s(str, "%s\t%d\n", p->tc[i].name, p->tc[i].expectation);
			outfile.write((char*)str, strlen(str));
		}
		sprintf_s(str, "\n");
		outfile.write((char*)str, strlen(str));
		p = p->next;
	}
	outfile.close();
	cout << "保存成功!" << endl;

}

/*构建打印函数*/
void print(Teacher& t)
{
	pTlist p = t.pt;
	cout << "最终排课情况:" << endl;
	cout << "教师姓名\t工作量\t教授课程" << endl;
	while (p)
	{
		cout << p->name << "\t\t" << p->work_time << "\t" << p->cbuf << endl;
		p = p->next;
	}
}