#pragma once
#include "stdafx.h"
#include <string>
#include<iostream>
using namespace std;


#define MAXCOURSE 38//���γ���
#define MAXPREDE 2//����Ⱦ�����Ϊ2
#define NUMBEROFSEMETER1 6//��һѧ�ڿγ���
#define NUMBEROFSEMETER2 7//�ڶ�ѧ�ڿγ���
#define NUMBEROFSEMETER3 3//����ѧ�ڿγ���
#define NUMBEROFSEMETER4 6//����ѧ�ڿγ���
#define NUMBEROFSEMETER5 5//����ѧ�ڿγ���
#define NUMBEROFSEMETER6 5//����ѧ�ڿγ���
#define NUMBEROFSEMETER7 5//����ѧ�ڿγ���
#define NUMBEROFSEMETER8 1//�ڰ�ѧ�ڿγ���

struct strTest {
	string number;//���
	string name;//����
	string semester;//ѧ��
	string preDe[MAXPREDE];//�Ⱦ�����
};


//�ڽӱ���
struct HeadNode
{
	string number;//��� 
	string name;//�γ�����
	string semester;//ѧ��
	string preDe[MAXPREDE];//�Ⱦ�����
	int inDegreeNumber;//�������
	int maxInDegreeNumber;//����������(ʹ����������Ҫ����)
	bool isOut;//�жϸö����Ƿ��Ѿ������
	HeadNode *pNextHeadNode;//ָ����һ��ͷ�ڵ�
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
	HeadNode *headNode;//�����ͷ�ڵ�
	HeadNode *curNode;//Ŀǰ��ͷ�ڵ��ǰһ���
	HeadNode *pMiddleHeadNode;//�м����ָ�룬�ڽ����Ⱦ���������ȼ���ʱ��ʹ�õ�ָ��
	int leftNodeCount;//ʣ��������
	int outCourseCount;//�������
	string topoCourseName[MAXCOURSE];//�ź���Ŀγ�������������
	string topoSemester[MAXCOURSE];//�ź���Ŀγ����ƶ�Ӧ��ѧ��
	string semeter1[NUMBEROFSEMETER1];//��һѧ�ڿγ���Ϣ
	string semeter2[NUMBEROFSEMETER2];//�ڶ�ѧ�ڿγ���Ϣ
	string semeter3[NUMBEROFSEMETER3];//����ѧ�ڿγ���Ϣ
	string semeter4[NUMBEROFSEMETER4];//����ѧ�ڿγ���Ϣ
	string semeter5[NUMBEROFSEMETER5];//����ѧ�ڿγ���Ϣ
	string semeter6[NUMBEROFSEMETER6];//����ѧ�ڿγ���Ϣ
	string semeter7[NUMBEROFSEMETER7];//����ѧ�ڿγ���Ϣ
	string semeter8[NUMBEROFSEMETER8];//�ڰ�ѧ�ڿγ���Ϣ
	int numberOfsemeter1;//���еĵ�һѧ�ڿγ���
	int numberOfsemeter2;//���еĵڶ�ѧ�ڿγ���
	int numberOfsemeter3;//���еĵ���ѧ�ڿγ���
	int numberOfsemeter4;//���еĵ���ѧ�ڿγ���
	int numberOfsemeter5;//���еĵ���ѧ�ڿγ���
	int numberOfsemeter6;//���еĵ���ѧ�ڿγ���
	int numberOfsemeter7;//���еĵ���ѧ�ڿγ���
	int numberOfsemeter8;//���еĵڰ�ѧ�ڿγ���


public:
	TopoSort();
	void getFileInfor();//��ȡ�ļ���Ϣ�������������
	bool topoShow();
	//�����������
	//����Ϊ������ȷ������Ϊ�����ʾ���ڻ�
	void disperseCourseToSemeter();
	//���������з�ɢ��ÿһѧ�ڵ�������
	void showConPanel();
	//չʾ�ڿ���̨
};