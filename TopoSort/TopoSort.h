#pragma once
#include "stdafx.h"
#include <string>
#include<iostream>
using namespace std;


#define MAXCOURSE 38//最大课程数
#define MAXPREDE 2//最大先决条件为2
#define NUMBEROFSEMETER1 6//第一学期课程数
#define NUMBEROFSEMETER2 7//第二学期课程数
#define NUMBEROFSEMETER3 3//第三学期课程数
#define NUMBEROFSEMETER4 6//第四学期课程数
#define NUMBEROFSEMETER5 5//第五学期课程数
#define NUMBEROFSEMETER6 5//第六学期课程数
#define NUMBEROFSEMETER7 5//第七学期课程数
#define NUMBEROFSEMETER8 1//第八学期课程数

struct strTest {
	string number;//编号
	string name;//名称
	string semester;//学期
	string preDe[MAXPREDE];//先决条件
};


//邻接表顶点
struct HeadNode
{
	string number;//编号 
	string name;//课程名称
	string semester;//学期
	string preDe[MAXPREDE];//先决条件
	int inDegreeNumber;//入度数量
	int maxInDegreeNumber;//最大入度数量(使用链表则不需要此项)
	bool isOut;//判断该顶点是否已经被输出
	HeadNode *pNextHeadNode;//指向下一个头节点
	HeadNode()
	{
		inDegreeNumber = 0;
		maxInDegreeNumber = 0;
		isOut = false;
		pNextHeadNode = NULL;
	}
};
class TopoSort 
{
private:
	HeadNode *headNode;//链表的头节点
	HeadNode *curNode;//目前的头节点的前一结点
	HeadNode *pMiddleHeadNode;//中间变量指针，在进行先决条件的入度减少时所使用的指针
	int leftNodeCount;//剩余结点数量
	int outCourseCount;//输出数量
	string topoCourseName[MAXCOURSE];//排好序的课程名称拓扑序列
	string topoSemester[MAXCOURSE];//排好序的课程名称对应的学期
	string semeter1[NUMBEROFSEMETER1];//第一学期课程信息
	string semeter2[NUMBEROFSEMETER2];//第二学期课程信息
	string semeter3[NUMBEROFSEMETER3];//第三学期课程信息
	string semeter4[NUMBEROFSEMETER4];//第四学期课程信息
	string semeter5[NUMBEROFSEMETER5];//第五学期课程信息
	string semeter6[NUMBEROFSEMETER6];//第六学期课程信息
	string semeter7[NUMBEROFSEMETER7];//第七学期课程信息
	string semeter8[NUMBEROFSEMETER8];//第八学期课程信息
	int numberOfsemeter1;//已有的第一学期课程数
	int numberOfsemeter2;//已有的第二学期课程数
	int numberOfsemeter3;//已有的第三学期课程数
	int numberOfsemeter4;//已有的第四学期课程数
	int numberOfsemeter5;//已有的第五学期课程数
	int numberOfsemeter6;//已有的第六学期课程数
	int numberOfsemeter7;//已有的第七学期课程数
	int numberOfsemeter8;//已有的第八学期课程数


public:
	TopoSort();
	void getFileInfor();//获取文件信息并将其存入结点中
	bool topoShow();
	//输出拓扑序列
	//返回为真则正确，返回为假则表示存在环
	void disperseCourseToSemeter();
	//将拓扑序列分散到每一学期的数组中
	void showConPanel();
	//展示在控制台
};