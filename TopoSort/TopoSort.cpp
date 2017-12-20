// TopoSort.cpp : �������̨Ӧ�ó������ڵ㡣
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
	numberOfsemeter1 = 0;//���еĵ�һѧ�ڿγ���
	numberOfsemeter2 = 0;//���еĵڶ�ѧ�ڿγ���
	numberOfsemeter3 = 0;//���еĵ���ѧ�ڿγ���
	numberOfsemeter4 = 0;//���еĵ���ѧ�ڿγ���
	numberOfsemeter5 = 0;//���еĵ���ѧ�ڿγ���
	numberOfsemeter6 = 0;//���еĵ���ѧ�ڿγ���
	numberOfsemeter7 = 0;//���еĵ���ѧ�ڿγ���
	numberOfsemeter8 = 0;//���еĵڰ�ѧ�ڿγ���
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
			HeadNode *newNode = new HeadNode; // �����µĽ��
			headNode = newNode;//ͷ���ָ���һ�����
			curNode = newNode;//��ǰ���ָ���һ�����
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
			HeadNode *newNode = new HeadNode; // �����µĽ��
			curNode->pNextHeadNode = newNode;//����ǰ��㡱����һ�����ָ���´����Ľ��
			curNode = newNode;//����ǰ��㡱ָ���´����Ľ��
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
	//�����ж�����
	int judge;

	while (leftNodeCount != 0)
	{
		curNode = headNode;
		judge = outCourseCount;
		for (int i = 0; i < MAXCOURSE; i++)
		{
			//����Ѿ����˽�β��������һ��ָ��Ľ����Ϊ��
			if (i == MAXCOURSE - 1)
			{
				curNode->pNextHeadNode = NULL;
			}

			//����ý���ѱ��������ָ����һ�����
			if (curNode->isOut)
			{
				curNode = curNode->pNextHeadNode;
			}
			//���δ����������ٽ����ж�
			else
			{
				//������������Ϊ0����ָ����һ�����
				if (curNode->inDegreeNumber != 0)
				{
					curNode = curNode->pNextHeadNode;
					continue;
				}
				//�������Ϊ0ʱ�������Ϣ���洢���飬�����Ƿ��������Ϊ���ǡ����������������������
				else
				{
					//����γ�����ѧ����
					topoCourseName[outCourseCount] = curNode->name;
					topoSemester[outCourseCount] = curNode->semester;
					outCourseCount++;//������γ���Ϣ����
					leftNodeCount--;//ʣ�������γ���Ϣ������һ

									//�����Ƿ��������Ϊ���ǡ�
					curNode->isOut = true;

					//�������������������
					pMiddleHeadNode = headNode;
					for (int m = 0; m < MAXCOURSE; m++)
					{
						//���ѵ�MAXCOURSE-1����Ӧ�������һ��ָ��ָ�����һ��ָ����ΪNULL
						if (m == MAXCOURSE - 1)
						{
							pMiddleHeadNode->pNextHeadNode = NULL;
						}
						//����ý���ѱ��������ָ����һ�����
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
									pMiddleHeadNode->inDegreeNumber--;//�������һ
									pMiddleHeadNode = pMiddleHeadNode->pNextHeadNode;//ָ����һ�����
									countPreDe++;
									break;
								}
							}
							if (countPreDe == 0)
								pMiddleHeadNode = pMiddleHeadNode->pNextHeadNode;//ָ����һ�����;
							countPreDe = 0;
						}
						if (i == 0 && m == 36)
						{
							int debug = 0;
						}
					}
					//����ǰ�ṹ��ָ��������һ�����
					curNode = curNode->pNextHeadNode;
				}
			}

			//����Ѿ�����ѭ�����������ж����������������Ȼ��ȣ���֤������ѭ��
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
	cout << "��һѧ�ڣ�";
	for (int i = 0; i < NUMBEROFSEMETER1; i++)
	{
		cout << semeter1[i] << " ";
	}
	cout << endl;
	cout << "�ڶ�ѧ�ڣ�";
	for (int i = 0; i < NUMBEROFSEMETER2; i++)
	{
		cout << semeter2[i] << " ";
	}
	cout << endl;
	cout << "����ѧ�ڣ�";
	for (int i = 0; i < NUMBEROFSEMETER3; i++)
	{
		cout << semeter3[i] << " ";
	}
	cout << endl;
	cout << "����ѧ�ڣ�";
	for (int i = 0; i < NUMBEROFSEMETER4; i++)
	{
		cout << semeter4[i] << " ";
	}
	cout << endl;
	cout << "����ѧ�ڣ�";
	for (int i = 0; i < NUMBEROFSEMETER5; i++)
	{
		cout << semeter5[i] << " ";
	}
	cout << endl;
	cout << "����ѧ�ڣ�";
	for (int i = 0; i < NUMBEROFSEMETER6; i++)
	{
		cout << semeter6[i] << " ";
	}
	cout << endl;
	cout << "����ѧ�ڣ�";
	for (int i = 0; i < NUMBEROFSEMETER7; i++)
	{
		cout << semeter7[i] << " ";
	}
	cout << endl;
	cout << "�ڰ�ѧ�ڣ�";
	for (int i = 0; i < NUMBEROFSEMETER8; i++)
	{
		cout << semeter8[i] << " ";
	}
}
