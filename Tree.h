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
	//������
	TreeElem* root;
public:
	Tree();
	~Tree();
	//������ �� ���������� ����
	void Print(TreeElem* Node);
	//����� �� ���������� ����
	TreeElem* Search(TreeElem* Node, char* key);
	//min �� ���������� ����
	TreeElem* Min(TreeElem* Node);
	//max �� ���������� ����
	TreeElem* Max(TreeElem* Node);
	//��������� ��� ���������� ����
	TreeElem* Next(TreeElem* Node);
	//���������� ��� ���������� ����
	TreeElem* Previous(TreeElem* Node);
	//������� ����
	void Insert(TreeElem* z);
	//�������� ����� ��� ���������� ����,
	//0 - �������� ����� ������
	void Del(TreeElem* z = 0);
	//�������� ������
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

//����������� ����� ������
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
//	//���� ���� ���� � ����� �� ���������
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
//	//����� ������ "������" ����
//	if (Node != 0)
//		while (Node->left != 0)
//			Node = Node->left;
//	return Node;
//}
//TreeElem* Tree::Max(TreeElem* Node)
//{
//		//����� ������ "�������" ����
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
//		//���� ���� ������ �������
//		if (Node->right != 0)
//			return Min(Node->right);
//		//�������� ����
//		y = Node->parent;
//		//���� Node �� ������ � Node ������
//		while (y != 0 && Node == y->right)
//		{
//			//�������� �����
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
//		//���� ���� ����� �������
//		if (Node->left != 0)
//			return Max(Node->left);
//
//			//�������� ����
//			y = Node->parent;
//		//���� Node �� ������ � Node �����
//		while (y != 0 && Node == y->left)
//		{
//			//�������� �����
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
	//�������� ���
	z->left = NULL;
	z->right = NULL;
	TreeElem* y = NULL;
	TreeElem* Node = root;
	//����� �����
	while (Node != 0)
	{
		//������� ��������
		y = Node;
		if (z->keyNumb > Node->keyNumb)
			Node = Node->left;
		else
			Node = Node->right;
	}
		//��������� ��������
		z->parent = y;
	if (y == 0) //������� ������ (������������)
		root = z;
	//��� ���� ������?
	else if (z->keyNumb > y->keyNumb)
		y->left = z;
	else
		y->right = z;
}
//void Tree::Del(TreeElem* z)
//{
//	//�������� �����
//	if (z != 0)
//	{
//		TreeElem* Node, * y;
//		//�� 2 �������
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
//		//��������� �������� ����?
//		if (y->parent == 0)
//			root = Node;
//		else if (y == y->parent->left)
//			//����� �� ��������?
//			y->parent->left = Node;
//		else
//			//������ �� ��������?
//			y->parent->right = Node;
//		if (y != z)
//		{
//			//����������� ������ ����
//			strcpy(z->keyNumb, y->keyNumb);
//			strcpy(z->Opponent, y->Opponent);
//			strcpy(z->Match, y->Match);
//			z->OppPoints = y->OppPoints;
//			z->OwnerPoints = y->OwnerPoints;
//		}
//		delete y;
//	}
//	else //�������� ����� ������
//		while (root != 0)
//			Del(root);
//}
//��������� �������
//Tree tournament;
//void Game(char Commands[][20], int N)
//{
//	int i, j;
//	int p1, p2; //����
//	//������ ������� ������ � ������ �� 2 ���� - 
//	//���� � � ������
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
//						//1 ����
//						strcpy(temp->keyNumb, Commands[i]);
//						strcpy(temp->Opponent, Commands[j]);
//					}
//					else
//					{
//						//2 ����
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
//					//������ �����
//					sprintf(temp->Match, " %d : %d ", p1, p2);
//				
//						//���������� ������
//						tournament.Insert(temp);
//				}
//		}
//}

//class Elem
//{
//	int keyNumb
//		int OppPoints; //���� ���������
//	char Match[10]; //����
//	char Name[20]; //�������
//	char Opponent[20]; //��������
//	Elem* left, * right, * parent;
//};
