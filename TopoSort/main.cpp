#include "stdafx.h"
#include <iostream>
#include "TopoSort.h"


using namespace std;

int main()
{
	TopoSort topo;
	topo.getFileInfor();
	if (!topo.topoShow())
	{
		cout << "���ڻ�" << endl;
	}
	topo.disperseCourseToSemeter();
	topo.showConPanel();
	return 0;
}