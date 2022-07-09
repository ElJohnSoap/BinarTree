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
	//корень
	TreeElem* root;
public:
	Tree();
	~Tree();
	//печать от указанного узла
	void Print(TreeElem* Node);
	////поиск от указанного узла
	//TreeElem* Search(TreeElem* Node, char* key);
	//min от указанного узла
	TreeElem* Min(TreeElem* Node);
	////max от указанного узла
	//TreeElem* Max(TreeElem* Node);
	//следующий для указанного узла
	TreeElem* Next(TreeElem* Node);
	////предыдущий для указанного узла
	//TreeElem* Previous(TreeElem* Node);
	//вставка узла
	void Insert(TreeElem* z);
	//удаление ветки для указанного узла,
	//0 - удаление всего дерева
	void Del(TreeElem* z = 0);
	//получить корень
	TreeElem* GetRoot();
	void add(int keyNumb, List <Penalty> listOfFines, TreeElem*& elem);
};