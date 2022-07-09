#pragma once
#include <iostream>
#include <string>
using namespace std;

class Penalty
{
public:
	int numberAuto;
	int prise;
	string namePenalty;

	Penalty(int numbAuto, int prise, string name) : numberAuto{ numbAuto }, prise{ prise }, namePenalty{ name }{};

	Penalty() : numberAuto{ 0 }, prise{ 0 }, namePenalty{ "0"}{};
	void printPenalty()
	{
		cout << "Number - " << numberAuto << endl;
		cout << "Prise: " << prise << endl;
		cout << "Name penalty - " << namePenalty << endl;
	}

	friend ostream& operator<< (ostream& output, const Penalty& p)
	{
		output << "Number - " << p.numberAuto << endl;
		output << "Prise: " << p.prise << endl;
		output << "Name penalty - " << p.namePenalty << endl;
		return output;
	}
};

template <typename T> class Element
{
public:
	//������
	T p;
	//����� ���������� �������� ������
	Element<T>* Next;
};
//����������� ������
template <typename T> class List
{
	//����� ��������� �������� ������
	Element<T>* Head;
	//����� ��������� �������� ������
	Element<T>* Tail;
		//���������� ��������� ������
		int Count;
public:
	//�����������
	List();
	//����������
	~List();
	//���������� �������� � ������
	//(����� ������� ���������� ���������)
	void Add(T);
	//�������� �������� ������
	//(��������� �������� �������)
	void Del();
	//�������� ����� ������
	void DelAll();
	//���������� ����������� ������
	//(���������� ���������� � ��������� ��������) 
	void Print();
	//��������� ���������� ���������,
	//����������� � ������
	int GetCount();
};

template <typename T>List <T>::List()
{
	//���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}
template <typename T>List <T>::~List()
{
	//����� ������� ��������
	DelAll();
}

template <typename T>
int List<T>::GetCount()
{
	//���������� ���������� ���������
	return Count;
}

template <typename T>
void List<T>::Add(T p)
{
	//�������� ������ ��������
	Element<T>* temp = new Element<T>;
	//���������� �������
	temp->p = p;
	//��������� ������� �����������
	temp->Next = NULL;
	//����� ������� ���������� ��������� ��������� ������
	//���� �� �� ������ �����������
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	//����� ������� ���������� ������������
	//���� �� ������ �����������
	else {
		Head = Tail = temp;
	}
}
template <typename T>
void List<T>::Del()
{
	//���������� ����� ��������� ��������
	Element<T>* temp = Head;
	//������������� ������ �� ��������� �������
	Head = Head->Next;
	//������� ������ �������� �������
	delete temp;
}

template <typename T>
void List<T>::DelAll()
{
	//���� ��� ���� �������� 
	while (Head != 0)
		//������� �������� �� ������
		Del();
}
template <typename T>
void List<T>::Print()
{
	//���������� ����� ��������� ��������
	Element<T>* temp = Head;
	//���� ��� ���� ��������
	while (temp != 0)
	{
		//������� ������
		cout << temp->p << " ";
		//��������� �� ��������� �������
		temp = temp->Next;
	}
	cout << "\n\n";
}

//????????????????????????????????????????????????
//template <typename T>
//struct Elem
//{
//	// ����� ������
//	T data;
//	Elem* next, * prev;
//};
//template <typename T>
//class List
//{
//	35
//		������� �������
//		// ������ �����
//		Elem<T> *Head, * Tail;
//	int Count;
//public:
//	List();
//	List(const List&);
//	~List();
//	int GetCount();
//	Elem<T>* GetElem(int);
//	void DelAll();
//	void Del(int);
//	void Del();
//	void AddTail();
//	void AddTail(T);
//	void AddHead(T);
//	void AddHead();
//	void Print();
//	void Print(int pos);
//	List& operator = (const List&);
//	List operator + (const List&);
//	bool operator == (const List&);
//	bool operator != (const List&);
//	bool operator <= (const List&);
//	bool operator >= (const List&);
//	bool operator < (const List&);
//	bool operator > (const List&);
//	List operator - ();
//};
//36
//���� �8
//template <typename T>
//List<T>::List()
//{
//	Head = Tail = 0;
//	Count = 0;
//}
//template <typename T>
//List<T>::List(const List& L)
//{
//	Head = Tail = 0;
//	Count = 0;
//	Elem<T>* temp = L.Head;
//	while (temp != 0)
//	{
//		AddTail(temp->data);
//		temp = temp->next;
//	}
//}
//template <typename T>
//List<T>::~List()
//{
//	DelAll();
//}
//template <typename T>
//Elem<T>* List<T>::GetElem(int pos)
//{
//	Elem<T>* temp = Head;
//	//������� �� 1 �� Count?
//	if (pos < 1 || pos > Count)
//	{
//		//�������� �������
//		cout << "Incorrect position !!!\n";
//		37
//			������� �������
//			return;
//	}
//	int i = 1;
//	while (i < pos && temp != 0)
//	{
//		temp = temp->next;
//		i++;
//	}
//	if (temp == 0)
//		return 0;
//	else
//		return temp;
//}
//template <typename T>
//void List<T>::AddHead()
//{
//	Elem<T>* temp = new Elem<T>;
//	temp->prev = 0;
//	int n;
//	cout << "Input new number: ";
//	cin >> n;
//	temp->data = n;
//	temp->next = Head;
//	if (Head != 0)
//		Head->prev = temp;
//	if (Count == 0)
//		Head = Tail = temp;
//	else
//		Head = temp;
//	38
//		���� �8
//		Count++;
//}
//template <typename T>
//void List<T>::AddHead(T n)
//{
//	Elem<T>* temp = new Elem<T>;
//	temp->prev = 0;
//	temp->data = n;
//	temp->next = Head;
//	if (Head != 0)
//		Head->prev = temp;
//	if (Count == 0)
//		Head = Tail = temp;
//	else
//		Head = temp;
//	Count++;
//}
//template <typename T>
//void List<T>::AddTail()
//{
//	Elem<T>* temp = new Elem<T>;
//	temp->next = 0;
//	int n;
//	cout << "Input new number: ";
//	cin >> n;
//	temp->data = n;
//	temp->prev = Tail;
//	if (Tail != 0)
//		Tail->next = temp;
//	if (Count == 0)
//		39
//		������� �������
//		Head = Tail = temp;
//	else
//		Tail = temp;
//	Count++;
//}
//template <typename T>
//void List<T>::AddTail(T n)
//{
//	Elem<T>* temp = new Elem<T>;
//	temp->next = 0;
//	temp->data = n;
//	temp->prev = Tail;
//	if (Tail != 0)
//		Tail->next = temp;
//	if (Count == 0)
//		Head = Tail = temp;
//	else
//		Tail = temp;
//	Count++;
//}
//template <typename T>
//void List<T>::Del()
//{
//	int n;
//	cout << "Input position: ";
//	cin >> n;
//	if (n < 1 || n > Count)
//	{
//		cout << "Incorrect position !!!\n";
//		return;
//	}
//	40
//		���� �8
//		int i = 1;
//	Elem<T>* Del = Head;
//	while (i <= n)
//	{
//		//������� �� ��������, ������� ���������
//		Del = Del->next;
//		i++;
//	}
//	//������� �� ��������, ������� ������������ 
//	//����������
//	Elem<T>* PrevDel = Del->prev;
//	//������� �� ��������, ������� ������� �� ���������
//	Elem<T>* AfterDel = Del->next;
//	if (PrevDel != 0 && Count != 1)
//		PrevDel->next = AfterDel;
//	if (AfterDel != 0 && Count != 1)
//		AfterDel->prev = PrevDel;
//	if (n == 1)
//		Head = AfterDel;
//	if (n == Count)
//		Tail = PrevDel;
//	delete Del;
//	Count--;
//}
//template <typename T>
//void List<T>::Del(int n)
//{
//	if (n < 1 || n > Count)
//	{
//		cout << "Incorrect position !!!\n";
//		return;
//	}
//	41
//		������� �������
//		int i = 1;
//	Elem<T>* Del = Head;
//	while (i < n)
//	{
//		//������� �� ��������, ������� ���������
//		Del = Del->next;
//		i++;
//	}
//	//������� �� ��������, ������� ������������
//	//����������
//	Elem<T>* PrevDel = Del->prev;
//	//������� �� ��������, ������� ������� ��
//	//���������
//	Elem<T>* AfterDel = Del->next;
//	if (PrevDel != 0 && Count != 1)
//		PrevDel->next = AfterDel;
//	if (AfterDel != 0 && Count != 1)
//		AfterDel->prev = PrevDel;
//	if (n == 1)
//		Head = AfterDel;
//	if (n == Count)
//		Tail = PrevDel;
//	delete Del;
//	Count--;
//}
//template <typename T>
//void List<T>::Print(int pos)
//{
//	42
//		���� �8
//		//������� �� 1 �� Count?
//		if (pos < 1 || pos > Count)
//		{
//			//�������� �������
//			cout << "Incorrect position !!!\n";
//			return;
//		}
//	Elem<T>* temp;
//	//���������� � ����� �������
//	//������� ���������
//	if (pos <= Count / 2)
//	{
//		//������ � ������
//		temp = Head;
//		int i = 1;
//		while (i < pos)
//		{
//			// ��������� �� ������� ��������
//			temp = temp->next;
//			i++;
//		}
//	}
//	else
//	{
//		//������ � ������
//		temp = Tail;
//		int i = 1;
//		while (i <= Count - pos)
//		{
//			//��������� �� ������� ��������
//			temp = temp->prev;
//			i++;
//		}
//	}
//	43
//		������� �������
//		//����� ��������
//		cout << pos << " element: ";
//	cout << temp->data << "\n";
//}
//template <typename T>
//void List<T>::Print()
//{
//	if (Count != 0)
//	{
//		Elem<T>* temp = Head;
//		while (temp != 0)
//		{
//			cout << temp->data << "\n";
//			temp = temp->next;
//		}
//	}
//}
//template <typename T>
//void List<T>::DelAll()
//{
//	while (Count != 0)
//		Del(1);
//}
//template <typename T>
//int List<T>::GetCount()
//{
//	return Count;
//}
//template <typename T>
//List<T>& List<T>::operator = (const List<T>& L)
//{
//	if (this == &L)
//		return *this;
//	44
//		���� �8
//		this->~List();
//	Elem<T>* temp = L.Head;
//	while (temp != 0)
//	{
//		AddTail(temp->data);
//		temp = temp->next;
//	}
//	return *this;
//}
//template <typename T>
//List<T> List<T>::operator + (const List<T>& L)
//{
//	List Result(*this);
//	Elem<T>* temp = L.Head;
//	while (temp != 0)
//	{
//		Result.AddTail(temp->data);
//		temp = temp->next;
//	}
//	return Result;
//}
//template <typename T>
//bool List<T>::operator == (const List<T>& L)
//{
//	if (Count != L.Count)
//		return false;
//	Elem<T>* t1, * t2;
//	t1 = Head;
//	t2 = L.Head;
//	45
//		������� �������
//		while (t1 != 0)
//		{
//			if (t1->data != t2->data)
//				return false;
//			t1 = t1->next;
//			t2 = t2->next;
//		}
//	return true;
//}
//template <typename T>
//bool List<T>::operator != (const List& L)
//{
//	if (Count != L.Count)
//		return true;
//	Elem<T>* t1, * t2;
//	t1 = Head;
//	t2 = L.Head;
//	while (t1 != 0)
//	{
//		if (t1->data != t2->data)
//			return true;
//		t1 = t1->next;
//		t2 = t2->next;
//	}
//	return false;
//}
//template <typename T>
//bool List<T>::operator >= (const List& L)
//{
//	if (Count > L.Count)
//		return true;
//	46
//		���� �8
//		if (*this == L)
//			return true;
//	return false;
//}
//template <typename T>
//bool List<T>::operator <= (const List& L)
//{
//	if (Count < L.Count)
//		return true;
//	if (*this == L)
//		return true;
//	return false;
//}
//template <typename T>
//bool List<T>::operator > (const List& L)
//{
//	if (Count > L.Count)
//		return true;
//	return false;
//}
//template <typename T>
//bool List<T>::operator < (const List& L)
//{
//	if (Count < L.Count)
//		return true;
//	return false;
//}
//47
//������� �������
//template <typename T>
//List<T> List<T>::operator - ()
//{
//	List Result;
//	Elem<T>* temp = Head;
//	while (temp != 0)
//	{
//		Result.AddHead(temp->data);
//		temp = temp->next;
//	}
//	return Result;
//
