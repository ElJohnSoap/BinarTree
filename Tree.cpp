#include "Tree.h"
Tree::Tree()
{
	root = NULL;
}
Tree::~Tree()
{
	Del();
}

//����������� ����� ������
void Tree::Print(TreeElem* Node)
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
TreeElem* Tree::Min(TreeElem* Node)
{
	//����� ������ "������" ����
	if (Node != 0)
		while (Node->left != 0)
			Node = Node->left;
	return Node;
}
//TreeElem* Tree::Max(TreeElem* Node)
//{
//		//����� ������ "�������" ����
//		if (Node != 0)
//			while (Node->right != 0)
//				Node = Node->right;
//	return Node;
//}
TreeElem* Tree::Next(TreeElem* Node)
{
	TreeElem* y = 0;
	if (Node != 0)
	{
		//���� ���� ������ �������
		if (Node->right != 0)
			return Min(Node->right);
		//�������� ����
		y = Node->parent;
		//���� Node �� ������ � Node ������
		while (y != 0 && Node == y->right)
		{
			//�������� �����
			Node = y;
			y = y->parent;
		}
	}
	return y;
}
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
void Tree::Del(TreeElem* z)
{
	//�������� �����
	if (z != 0)
	{
		TreeElem* Node, * y;
		//�� 2 �������
		if (z->left == 0 || z->right == 0)
			y = z;
		else
			y = Next(z);
		if (y->left != 0)
			Node = y->left;
		else
			Node = y->right;
		if (Node != 0)
			Node->parent = y->parent;
		//��������� �������� ����?
		if (y->parent == 0)
			root = Node;
		else if (y == y->parent->left)
			//����� �� ��������?
			y->parent->left = Node;
		else
			//������ �� ��������?
			y->parent->right = Node;
		if (y != z)
		{
			//����������� ������ ����
			z->keyNumb = y->keyNumb;

		}
		delete y;
	}
	else //�������� ����� ������
		while (root != 0)
			Del(root);
}

	void Tree::add(int keyNumb, List <Penalty> listOfFines, TreeElem * &elem)
	{
		if (elem == NULL)
		{
			elem = new TreeElem;
			elem->keyNumb = keyNumb;
			elem->listOfFines = listOfFines;
			elem->left = nullptr;
			elem->right = nullptr;
			elem->parent = nullptr;
			return;
		}
		if (keyNumb > elem->keyNumb)
		{
			add(keyNumb, listOfFines, elem->right);
		}
		else
		{
			add(keyNumb, listOfFines, elem->left);
		}
	}
