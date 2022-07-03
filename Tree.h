#pragma once
#include <iostream>
#include <string>
using namespace std;

class TreeElem
{
public:
	int keyNumb;
	TreeElem* left, * right, * parent;
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
	//поиск от указанного узла
	TreeElem* Search(TreeElem* Node, char* key);
	//min от указанного узла
	TreeElem* Min(TreeElem* Node);
	//max от указанного узла
	TreeElem* Max(TreeElem* Node);
	//следующий дл€ указанного узла
	TreeElem* Next(TreeElem* Node);
	//предыдущий дл€ указанного узла
	TreeElem* Previous(TreeElem* Node);
	//вставка узла
	void Insert(TreeElem* z);
	//удаление ветки дл€ указанного узла,
	//0 - удаление всего дерева
	void Del(TreeElem* z = 0);
	//получить корень
	TreeElem* GetRoot();
};
Tree::Tree()
{
	root = NULL;
}
Tree::~Tree()
{
	Del();
}

//–екурсивный обход дерева
void Tree::Print(TreeElem * Node)
{
	if (Node != 0)
	{
		Print(Node->left);
		cout << Node->keyNumb
			<< endl;
		Print(Node->right);
	}
}
//TreeElem* Tree::Search(TreeElem* Node, char* k)
//{
//	//ѕока есть узлы и ключи не совпадают
//	while (Node != 0 && strcmp(k, Node->keyNumb) != 0)
//	{
//		if (strcmp(k, Node->keyNumb) < 0)
//			Node = Node->left;
//		else
//			Node = Node->right;
//	}
//	return Node;
//}
//TreeElem* Tree::Min(TreeElem* Node)
//{
//	//ѕоиск самого "левого" узла
//	if (Node != 0)
//		while (Node->left != 0)
//			Node = Node->left;
//	return Node;
//}
//TreeElem* Tree::Max(TreeElem* Node)
//{
//		//ѕоиск самого "правого" узла
//		if (Node != 0)
//			while (Node->right != 0)
//				Node = Node->right;
//	return Node;
//}
//TreeElem* Tree::Next(TreeElem* Node)
//{
//	TreeElem* y = 0;
//	if (Node != 0)
//	{
//		//если есть правый потомок
//		if (Node->right != 0)
//			return Min(Node->right);
//		//родитель узла
//		y = Node->parent;
//		//если Node не корень и Node справа
//		while (y != 0 && Node == y->right)
//		{
//			//ƒвижемс€ вверх
//			Node = y;
//			y = y->parent;
//		}
//	}
//	return y;
//}
//TreeElem* Tree::Previous(TreeElem* Node)
//{
//	TreeElem* y = 0;
//	if (Node != 0)
//	{
//		//если есть левый потомок
//		if (Node->left != 0)
//			return Max(Node->left);
//
//			//родитель узла
//			y = Node->parent;
//		//если Node не корень и Node слева
//		while (y != 0 && Node == y->left)
//		{
//			//ƒвижемс€ вверх
//			Node = y;
//			y = y->parent;
//		}
//	}
//	return y;
//}
TreeElem* Tree::GetRoot()
{
	return root;
}
void Tree::Insert(TreeElem* z)
{
	//потомков нет
	z->left = NULL;
	z->right = NULL;
	TreeElem* y = NULL;
	TreeElem* Node = root;
	//поиск места
	while (Node != 0)
	{
		//будущий родитель
		y = Node;
		if (z->keyNumb > Node->keyNumb)
			Node = Node->left;
		else
			Node = Node->right;
	}
		//заполн€ем родител€
		z->parent = y;
	if (y == 0) //элемент первый (единственный)
		root = z;
	//чей ключ больше?
	else if (z->keyNumb > y->keyNumb)
		y->left = z;
	else
		y->right = z;
}
//void Tree::Del(TreeElem* z)
//{
//	//удаление куста
//	if (z != 0)
//	{
//		TreeElem* Node, * y;
//		//не 2 ребенка
//		if (z->left == 0 || z->right == 0)
//			y = z;
//		else
//			y = Next(z);
//		if (y->left != 0)
//			Node = y->left;
//		else
//			Node = y->right;
//		if (Node != 0)
//			Node->parent = y->parent;
//		//”дал€етс€ корневой узел?
//		if (y->parent == 0)
//			root = Node;
//		else if (y == y->parent->left)
//			//слева от родител€?
//			y->parent->left = Node;
//		else
//			//справа от родител€?
//			y->parent->right = Node;
//		if (y != z)
//		{
//			// опирование данных узла
//			strcpy(z->keyNumb, y->keyNumb);
//			strcpy(z->Opponent, y->Opponent);
//			strcpy(z->Match, y->Match);
//			z->OppPoints = y->OppPoints;
//			z->OwnerPoints = y->OwnerPoints;
//		}
//		delete y;
//	}
//	else //удаление всего дерева
//		while (root != 0)
//			Del(root);
//}
//“урнирна€ таблица
//Tree tournament;
//void Game(char Commands[][20], int N)
//{
//	int i, j;
//	int p1, p2; //—чет
//	// ажда€ команда играет с каждой по 2 раза - 
//	//дома и в гост€х
//	int k;
//	TreeElem* temp;
//	for (k = 0; k < 2; k++)
//		for (i = 0; i < N - 1; i++)
//		{
//			for (j = i + 1; j < N; j++)
//				{
//					temp = new TreeElem;
//					if (k == 0)
//					{
//						//1 игра
//						strcpy(temp->keyNumb, Commands[i]);
//						strcpy(temp->Opponent, Commands[j]);
//					}
//					else
//					{
//						//2 игра
//						strcpy(temp->keyNumb, Commands[j]);
//						strcpy(temp->Opponent, Commands[i]);
//					}
//					p1 = rand() % 6;
//					p2 = rand() % 6;
//					if (p1 > p2)
//					{
//						temp->OwnerPoints = 3;
//						temp->OppPoints = 0;
//					}
//					else if (p1 == p2)
//					{
//						temp->OwnerPoints = 1;
//						temp->OppPoints = 1;
//					}
//					else
//					{
//						temp->OwnerPoints = 0;
//						temp->OppPoints = 3;
//					}
//					//«апись счета
//					sprintf(temp->Match, " %d : %d ", p1, p2);
//				
//						//ƒобавление записи
//						tournament.Insert(temp);
//				}
//		}
//}

//class Elem
//{
//	int keyNumb
//		int OppPoints; //ќчки соперника
//	char Match[10]; //—чет
//	char Name[20]; // оманда
//	char Opponent[20]; //—оперник
//	Elem* left, * right, * parent;
//};
