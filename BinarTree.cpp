

#include <iostream>
#include "penalty.h"
#include "Tree.h"
using namespace std;

int main()
{
   

	Penalty p("qwe05u62", 500, "rt");
	//p.printPenalty();

	List <Penalty> L;
	L.Add(p);
	L.Print();
	

}
