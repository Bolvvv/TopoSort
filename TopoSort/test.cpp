#include"stdafx.h"
/*#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define MAXPREDE 2//最大先决条件为2
#define MAXCOURSE 38//最大课程数

struct strTest {
	string number;//编号
	string name;//名称
	string semester;//学期
	string preDe[MAXPREDE];//先决条件
};


int main()
{
	strTest str[MAXCOURSE];//存储数据
	FILE *fin = fopen("in.txt", "rt");
	if (!fin)
	{
		printf("errror!\n");
		exit(-1);
	}
	for (int i = 0; i < MAXCOURSE; i++)
	{
		fscanf(fin, "%s%s%s", str[i].number.c_str(), str[i].name.c_str(), str[i].semester.c_str());
		for (int s = 0; s < MAXPREDE; s++)
		{
			fscanf(fin, "%s", str[i].preDe[s].c_str());
		}
	}
	fclose(fin);
	cout << str[20].preDe[1].c_str() << endl;
	return 0;
}*/