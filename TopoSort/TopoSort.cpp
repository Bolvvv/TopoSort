// TopoSort.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "TopoSort.h"
#include<fstream>

TopoSort::TopoSort()
{
	headNode = NULL;
	curNode = NULL;
	leftNodeCount = MAXCOURSE;
	outCourseCount = 0;
	numberOfsemeter1 = 0;//已有的第一学期课程数
	numberOfsemeter2 = 0;//已有的第二学期课程数
	numberOfsemeter3 = 0;//已有的第三学期课程数
	numberOfsemeter4 = 0;//已有的第四学期课程数
	numberOfsemeter5 = 0;//已有的第五学期课程数
	numberOfsemeter6 = 0;//已有的第六学期课程数
	numberOfsemeter7 = 0;//已有的第七学期课程数
	numberOfsemeter8 = 0;//已有的第八学期课程数
}

void TopoSort::getFileInfor()
{
	FILE *fi = fopen("in.txt", "rt");
	strTest readCourse[MAXCOURSE];
	if (!fi)
	{
		printf("errror!\n");
		exit(-1);
	}
	for (int i = 0; i < MAXCOURSE; i++)
	{
		char number[10];
		char name[20];
		char semester[20];
		char preDe[MAXPREDE][10];
		fscanf(fi, "%s%s%s", number, name, semester);
		readCourse[i].number = number;
		readCourse[i].name = name;
		readCourse[i].semester = semester;
		for (int s = 0; s < MAXPREDE; s++)
		{
			fscanf(fi, "%s", preDe[s]);
			readCourse[i].preDe[s] = preDe[s];
		}
	}
	fclose(fi);
	for (int i = 0; i < MAXCOURSE; i++)
	{
		if (i == 0)
		{
			HeadNode *newNode = new HeadNode; // 创建新的结点
			headNode = newNode;//头结点指向第一个结点
			curNode = newNode;//当前结点指向第一个结点
			newNode->number = readCourse[i].number;
			newNode->name = readCourse[i].name;
			newNode->semester = readCourse[i].semester;
			for (int m = 0; m < MAXPREDE; m++)
			{
				if (readCourse[i].preDe[m] == "#")
					break;
				else
				{
					newNode->preDe[m] = readCourse[i].preDe[m];
					newNode->inDegreeNumber = newNode->inDegreeNumber + 1;
					newNode->maxInDegreeNumber = newNode->maxInDegreeNumber + 1;
				}
			}
		}
		else
		{
			HeadNode *newNode = new HeadNode; // 创建新的结点
			curNode->pNextHeadNode = newNode;//“当前结点”的下一个结点指向新创建的结点
			curNode = newNode;//“当前结点”指向新创建的结点
			newNode->number = readCourse[i].number;
			newNode->name = readCourse[i].name;
			newNode->semester = readCourse[i].semester;
			for (int m = 0; m < MAXPREDE; m++)
			{
				if (readCourse[i].preDe[m] == "#")
					break;
				newNode->preDe[m] = readCourse[i].preDe[m];
				newNode->inDegreeNumber = newNode->inDegreeNumber + 1;
				newNode->maxInDegreeNumber = newNode->maxInDegreeNumber + 1;
			}
		}
	}
}

bool TopoSort::topoShow()
{
	//设置判断数量
	int judge;

	while (leftNodeCount != 0)
	{
		curNode = headNode;
		judge = outCourseCount;
		for (int i = 0; i < MAXCOURSE; i++)
		{
			//如果已经到了结尾，则将其下一个指向的结点置为空
			if (i == MAXCOURSE - 1)
			{
				curNode->pNextHeadNode = NULL;
			}

			//如果该结点已被输出，则指向下一个结点
			if (curNode->isOut)
			{
				curNode = curNode->pNextHeadNode;
			}
			//如果未被输出，则再进行判断
			else
			{
				//如果入度数量不为0，则指向下一个结点
				if (curNode->inDegreeNumber != 0)
				{
					curNode = curNode->pNextHeadNode;
					continue;
				}
				//入度数量为0时，输出信息至存储数组，将“是否输出”改为“是”，更改其他结点的入度数量
				else
				{
					//输出课程名和学期数
					topoCourseName[outCourseCount] = curNode->name;
					topoSemester[outCourseCount] = curNode->semester;
					outCourseCount++;//已输出课程信息加以
					leftNodeCount--;//剩余可输出课程信息数量减一

									//将“是否输出”置为“是”
					curNode->isOut = true;

					//更改其他结点的入度数量
					pMiddleHeadNode = headNode;
					for (int m = 0; m < MAXCOURSE; m++)
					{
						//若已到MAXCOURSE-1，则应将其最后一个指针指向的下一个指针置为NULL
						if (m == MAXCOURSE - 1)
						{
							pMiddleHeadNode->pNextHeadNode = NULL;
						}
						//如果该结点已被输出，则指向下一个结点
						if (pMiddleHeadNode->isOut)
						{
							pMiddleHeadNode = pMiddleHeadNode->pNextHeadNode;
						}

						else
						{
							int countPreDe = 0;
							for (int h = 0; h < pMiddleHeadNode->maxInDegreeNumber; h++)
							{
								if (pMiddleHeadNode->preDe[h] == curNode->number)
								{
									pMiddleHeadNode->inDegreeNumber--;//入度数减一
									pMiddleHeadNode = pMiddleHeadNode->pNextHeadNode;//指向下一个结点
									countPreDe++;
									break;
								}
							}
							if (countPreDe == 0)
								pMiddleHeadNode = pMiddleHeadNode->pNextHeadNode;//指向下一个结点;
							countPreDe = 0;
						}
						if (i == 0 && m == 36)
						{
							int debug = 0;
						}
					}
					//将当前结构体指针移向下一个结点
					curNode = curNode->pNextHeadNode;
				}
			}

			//如果已经到了循环结束，且判断数量和输出数量仍然相等，则证明存在循环
			if ((i == MAXCOURSE - 1) && (judge = outCourseCount) && outCourseCount != MAXCOURSE)
				return false;
		}

	}
}

void TopoSort::disperseCourseToSemeter()
{
	for (int i = 0; i < MAXCOURSE; i++)
	{
		if (topoSemester[i] != "0")
		{
			if (topoSemester[i] == "1")
			{
				semeter1[numberOfsemeter1] = topoCourseName[i];
				numberOfsemeter1++;
			}
			else if (topoSemester[i] == "2")
			{
				semeter2[numberOfsemeter2] = topoCourseName[i];
				numberOfsemeter2++;
			}
			else if (topoSemester[i] == "3")
			{
				semeter3[numberOfsemeter3] = topoCourseName[i];
				numberOfsemeter3++;
			}
			else if (topoSemester[i] == "4")
			{
				semeter4[numberOfsemeter4] = topoCourseName[i];
				numberOfsemeter4++;
			}
			else if (topoSemester[i] == "5")
			{
				semeter5[numberOfsemeter5] = topoCourseName[i];
				numberOfsemeter5++;
			}
			else if (topoSemester[i] == "6")
			{
				semeter6[numberOfsemeter6] = topoCourseName[i];
				numberOfsemeter6++;
			}
			else if (topoSemester[i] == "7")
			{
				semeter7[numberOfsemeter7] = topoCourseName[i];
				numberOfsemeter7++;
			}
			else if (topoSemester[i] == "8")
			{
				semeter8[numberOfsemeter8] = topoCourseName[i];
				numberOfsemeter8++;
			}
		}
	}
	for (int i = 0; i < MAXCOURSE; i++)
	{
		if (topoSemester[i] == "0")
		{
			if (numberOfsemeter1 != NUMBEROFSEMETER1)
			{
					semeter1[numberOfsemeter1] = topoCourseName[i];
					numberOfsemeter1++;
			}
			else if (numberOfsemeter2 != NUMBEROFSEMETER2)
			{
					semeter2[numberOfsemeter2] = topoCourseName[i];
					numberOfsemeter2++;
			}
			else if (numberOfsemeter3 != NUMBEROFSEMETER3)
			{
					semeter3[numberOfsemeter3] = topoCourseName[i];
					numberOfsemeter3++;
			}
			else if (numberOfsemeter4 != NUMBEROFSEMETER4)
			{
					semeter4[numberOfsemeter4] = topoCourseName[i];
					numberOfsemeter4++;
			}
			else if (numberOfsemeter5 != NUMBEROFSEMETER5)
			{
					semeter5[numberOfsemeter5] = topoCourseName[i];
					numberOfsemeter5++;
			}
			else if (numberOfsemeter6 != NUMBEROFSEMETER6)
			{
					semeter6[numberOfsemeter6] = topoCourseName[i];
					numberOfsemeter6++;
			}
			else if (numberOfsemeter7 != NUMBEROFSEMETER7)
			{
					semeter7[numberOfsemeter7] = topoCourseName[i];
					numberOfsemeter7++;
			}
			else if (numberOfsemeter8 != NUMBEROFSEMETER8)
			{
					semeter8[numberOfsemeter8] = topoCourseName[i];
					numberOfsemeter8++;
			}
		}
	}
}

void TopoSort::showConPanel()
{
	cout << "第一学期：";
	for (int i = 0; i < NUMBEROFSEMETER1; i++)
	{
		cout << semeter1[i] << " ";
	}
	cout << endl;
	cout << "第二学期：";
	for (int i = 0; i < NUMBEROFSEMETER2; i++)
	{
		cout << semeter2[i] << " ";
	}
	cout << endl;
	cout << "第三学期：";
	for (int i = 0; i < NUMBEROFSEMETER3; i++)
	{
		cout << semeter3[i] << " ";
	}
	cout << endl;
	cout << "第四学期：";
	for (int i = 0; i < NUMBEROFSEMETER4; i++)
	{
		cout << semeter4[i] << " ";
	}
	cout << endl;
	cout << "第五学期：";
	for (int i = 0; i < NUMBEROFSEMETER5; i++)
	{
		cout << semeter5[i] << " ";
	}
	cout << endl;
	cout << "第六学期：";
	for (int i = 0; i < NUMBEROFSEMETER6; i++)
	{
		cout << semeter6[i] << " ";
	}
	cout << endl;
	cout << "第七学期：";
	for (int i = 0; i < NUMBEROFSEMETER7; i++)
	{
		cout << semeter7[i] << " ";
	}
	cout << endl;
	cout << "第八学期：";
	for (int i = 0; i < NUMBEROFSEMETER8; i++)
	{
		cout << semeter8[i] << " ";
	}
}
