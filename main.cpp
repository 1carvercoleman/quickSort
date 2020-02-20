#include <iostream>
#include <string>
#include <vector>
#include "QSInterface.h"
#include "QS.h"
using namespace std;

int main() {
	QS* qsptr = NULL;
	qsptr = new QS(); 
	qsptr->createArray(12);
	qsptr->addToArray(10);
	qsptr->addToArray(5);
	qsptr->addToArray(7);
	qsptr->addToArray(2);
	qsptr->addToArray(3);
	qsptr->addToArray(11);
	qsptr->addToArray(1);
	qsptr->addToArray(12);
	qsptr->addToArray(8);
	qsptr->addToArray(6);	
	qsptr->addToArray(4);
	qsptr->addToArray(9);	
	cout << "Entered array: " << qsptr->getArray() << endl;
	qsptr->sortAll();
	cout << "Sorted array: " << qsptr->getArray() << endl;
	return 0;
}
