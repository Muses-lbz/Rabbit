#pragma once
#include"course.h"

/*构建教师排课函数*/
void sort(Teacher& t, Course& c)
{
	pTlist q = t.pt;
	pTlist n = t.pt;
	pTlist m = n;
	int sum = 0;
	int num = -1;
	srand(time(0));		//函数是随机数发生器的初始化函数
	for (int i = 0; i < M; i++)
	{
		while (m)
		{
			m = n->next;
			if (m == NULL)
				break;
			for (int j = 0; j < M; j++)
				if ((m->tc[i].expectation == n->tc[j].expectation) && (0 == strcmp(m->tc[i].name, n->tc[j].name)))
				{
					num = rand() % 2;
					switch (num)
					{
					case 0:
						(transform(c, q->tc[num].name))->kb = false;
						break;
					case 1:
						(transform(c, q->tc[num].name))->kb = false;
						break;
					default:
						break;
					}
				}
			n = n->next;
		}
	}
	while (q)
	{
		for (int i = 0; i < M; i++)
		{
			if ((transform(c, q->tc[i].name))->kb)
			{
				sum += (transform(c, q->tc[i].name))->total_time;
				(transform(c, q->tc[i].name))->kb = false;
				if (i == 0)
					strcpy_s(q->cbuf, q->tc[i].name);
				else
				{
					strcat_s(q->cbuf, " ");
					strcat_s(q->cbuf, q->tc[i].name);
				}

				if (sum >= q->work_time)
					break;
			}
		}
		sum = 0;
		q = q->next;
	}
	cout << "课程已排好!" << endl;

}

class Zombie
{
public:
	int intput();
};

int Zombie::intput()
{
	ofstream   ofresult("E:\\teacher.txt ", ios::app);
	ofresult << "沈文涛" << "\t" << "20003" << "\t" << "30" << endl;
	ofresult << "对相应课程的期望值:" << endl;
	ofresult << "语文" << "\t" << "1" << endl;
	ofresult << "高数" << "\t" << "2" << endl;
	ofresult << "伦理" << "\t" << "3" << endl;
	return 0;
}

class Ghost
{
public:
	int intput();
};

int Ghost::intput()
{
	ofstream   ofresult("E:\\course.txt ", ios::app);
	ofresult << "伦理" << "\t" << "1006" << "\t" << "3" << "\t" << "12" << "\t" << "6" << endl;
	ofresult << "语文" << "\t" << "1007" << "\t" << "3" << "\t" << "6"  << "\t" << "7" << endl;
	return 0;
}

class Vampire
{
public:
	int intput();
};

int Vampire::intput()
{
	ofstream ofile;               //定义输出文件
	ofile.open("E:\\surprice.txt");     //作为输出文件打开
	ofile << "感谢老师的检查。" << endl;   //标题写入文件
	ofile << "这就是我的课程设计。" << endl;
	ofile.close();                //关闭文件
	return 0;
}

Teacher   tea;
Course    cou;
Zombie    zom;
Ghost     gho;
Vampire   vam;

/*主界面函数*/
void dis_menu()
{
	bool ttag = false;
	bool ctag = false;
	char tag;
	int choice = 0;
	do {
		system("cls");
		cout << "========欢迎使用教师排课系统,请根据提示完成相关操作========" << endl;
		cout << "===			1:载入教师信息			===" << endl;
		cout << "===			2:载入课程信息			===" << endl; 
		cout << "===			3:存储教师信息			===" << endl;
		cout << "===			4:存储课程信息			===" << endl;
		cout << "===			5:开始教师排课			===" << endl;
		cout << "===			6:打印排课结果			===" << endl;
		cout << "===			7.教师信息修改			===" << endl;
		cout << "===			8.课程信息修改			===" << endl;
		cout << "===			9.系统其他部分			===" << endl;
		cout << "===			0:退出排课系统			===" << endl;
		cout << "===========================================================" << endl;
		fflush(stdin);
		cout << "请输入选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "------------教师信息载入------------" << endl;
			tea.input();
			ttag = true;
			break;
		case 2:
			system("cls");
			cout << "------------课程信息载入------------" << endl;
			cou.input();
			ctag = true;
			break;
		case 3:
			system("cls");
			cout << "------------教师信息保存------------" << endl;
			if (!ttag)
				cout << "请先载入教师信息" << endl;
			else
				tea.preserve();
			break;
		case 4:
			system("cls");
			cout << "------------课程信息保存------------" << endl;
			if (!ctag)
				cout << "请先载入课程信息" << endl;
			else
				cou.preserve();
			break;
		case 5:
			system("cls");
			cout << "------------教师排序界面------------" << endl;
			if (!ttag || !ctag)
				cout << "请先载入相关信息:" << endl;
			else
				sort(tea, cou);
			break;
		case 6:
			system("cls");
			cout << "------------排课信息打印------------" << endl;
			if (!ttag || !ctag)
				cout << "请先载入相关信息:" << endl;
			else
				print(tea);
			break;
		case 7:
			system("cls");
			cout << "------------教师信息修改------------" << endl;
			zom.intput();
			break;
		case 8:
			system("cls");
			cout << "------------课程信息修改------------" << endl;
			gho.intput();
			break;
		case 9:
			system("cls");
			cout << "------------系统其他部分------------" << endl;
			vam.intput();
			break;
		default:
			system("cls");
			cout << "\t-------------------THANKS FOR YOUR USE-------------------" << endl;
			cout << "\t-------------------  感谢使用本系统!  -------------------" << endl;
			exit(0);
		}
		cout << "系统使用中........." << endl;
		cout << "是否继续其他操作? y/n" << endl;
		cin >> tag;
	} while (tag == 'y' || tag == 'n');

}