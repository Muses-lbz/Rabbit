#pragma once
#include"teacher.h"

/*构建课程类*/
class Course
{
public:
	Course();
	~Course();
	void input();
	void preserve();
	friend pClist transform(Course&, char* s);
private:
	Clist* pc;		//具有排课节点结构的指针
};

/*构建course函数*/
Course::Course()
{
	pc = NULL;
}

/*构建课程删除函数*/
Course::~Course()
{
	pClist p;
	while (pc)
	{
		p = pc;
		pc = pc->next;
		delete p;
	}
}

/*构建课程信息的生成函数，用于输入课程信息*/
void Course::input()
{
	pClist p = pc;
	pClist s;
	char tag;
	int i = 0;
	cout << "请输入课程信息:" << endl;
	cout << "课程名\t课程号\t周学时\t总学时\t优先级" << endl;
	do {
		if (i >= 1)
		{
			cout << "请输入课程信息:" << endl;
			cout << "课程名\t课程号\t周学时\t总学时\t优先级" << endl;
		}
		s = (pClist)malloc(sizeof(Clist));
		cin >> s->name >> s->num >> s->week_time >> s->total_time >> s->priority;
		fflush(stdin);
		s->kb = true;
		s->next = NULL;
		i++;
		if (!pc)
		{
			pc = s;
			p = pc;
		}
		else
		{
			p->next = s;
			p = p->next;
		}
		cout << "是否继续载入课程信息? y/n" << endl;
		cin >> tag;
		system("cls");
	} while (tag == 'y' || tag == 'n');
}

/*构建课程保存函数，用于保存输入的课程信息*/
void Course::preserve()
{
	char path[20] = "E:\\course.txt";
	pClist p = pc;
	char str[100] = { '\0' };
	cout << "请输入文件保存路径:" << endl;
	cin >> path;
	ofstream outfile(path);
	if (!outfile)
	{
		cerr << "保存失败,请检查输入路径是否正确";
		return;
	}
	sprintf_s(str, "课程名\t课程号\t周学时\t总学时\t优先级\n");
	outfile.write((char*)str, strlen(str));
	while (p)
	{
		sprintf_s(str, "%s\t%s\t%d\t%d\t%d\n", p->name, p->num, p->week_time, p->total_time, p->priority);
		outfile.write((char*)str, strlen(str));
		p = p->next;

	}
	outfile.close();
	cout << "保存成功!" << endl;
}

/*匹配函数*/
pClist transform(Course& c, char* s)
{
	pClist p = c.pc;
	while (p)
	{
		if (0 == strcmp(p->name, s))
			return p;
		else
			p = p->next;
	}
	cout << "应用程序出错!" << endl;
	return NULL;
}