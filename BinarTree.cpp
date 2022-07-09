

#include <iostream>
#include "penalty.h"
#include "Tree.h"
using namespace std;

int main()
{
   

	Penalty p(500600, 500, "rt");
	//p.printPenalty();

	List <Penalty> L;
	L.Add(p);
	L.Print();
	cout << endl;
	TreeElem *first;
	Tree arrayNumb;
	arrayNumb.Print(arrayNumb.GetRoot());
	arrayNumb.add(500600, L, first);
	arrayNumb.Print(first);
}
