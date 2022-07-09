#pragma once
#include <iostream>
#include <string>
#include "penalty.h"
using namespace std;

class TreeElem
{
public:
	int keyNumb;
	List <Penalty> listOfFines;
	TreeElem* left, * right, * parent;
	/*TreeElem() : keyNumb{ 0 }
	{
		List <Penalty> listOfFines();

		left = right = parent = NULL;
	};*/
};

class Tree
{
	//������
	TreeElem* root;
public:
	Tree();
	~Tree();
	//������ �� ���������� ����
	void Print(TreeElem* Node);
	////����� �� ���������� ����
	//TreeElem* Search(TreeElem* Node, char* key);
	//min �� ���������� ����
	TreeElem* Min(TreeElem* Node);
	////max �� ���������� ����
	//TreeElem* Max(TreeElem* Node);
	//��������� ��� ���������� ����
	TreeElem* Next(TreeElem* Node);
	////���������� ��� ���������� ����
	//TreeElem* Previous(TreeElem* Node);
	//������� ����
	void Insert(TreeElem* z);
	//�������� ����� ��� ���������� ����,
	//0 - �������� ����� ������
	void Del(TreeElem* z = 0);
	//�������� ������
	TreeElem* GetRoot();
	void add(int keyNumb, List <Penalty> listOfFines, TreeElem*& elem);
};