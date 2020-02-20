#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "QS.h"
using namespace std;

QS::QS() {
	int insertIndex = 0;
	int numberElements = 0;
	if (table != 0) {
		delete [] table;
		table = 0;
	}
	int * table = new int[numberElements];
}

QS::~QS() {
	//if (table != 0) {
	delete [] table;
	table = 0;
	//}
}

bool QS::createArray(int capacity) {
	if (table != 0) {
		delete [] table;
		table = 0;
		table = new int[capacity];	
	} else {
		table = new int[capacity];
	}
	
	numberElements = capacity;
	insertIndex = 0;
	return true;
}

bool QS::addToArray(int value) {
	if (insertIndex < numberElements) {
		table[insertIndex] = value;
		insertIndex += 1;
		return(true);
	} else {
		return(false);
	}
}

void QS::clear() {
	if (table != 0) {
		delete [] table;
		table = 0;
		int * table = new int[0];
		numberElements = 0;
		insertIndex = 0;
	}
}

string QS::getArray() const {
	string output;
	for (int i = 0; i < numberElements; i++) {
		if (i < insertIndex) {
			output.append(to_string(table[i]));
			if (i < numberElements - 1 && i != insertIndex - 1) {
				output.append(",");
			}
		}
	}
	return(output);
}

int QS::getSize() const {
	return insertIndex;
}

int QS::partition(int left, int right, int pivotIndex) {
	if (getSize() < 1 || left < 0 || right > getSize() - 1 || pivotIndex < 0 || pivotIndex > getSize() - 1 || left >= right || pivotIndex < left || pivotIndex > right) {
		return -1;
	}
	int temp = table[pivotIndex];
	table[pivotIndex] = table[left];
	table[left] = temp;
	int up = left + 1;
	int down = right;
	do {
		while((table[up] <= table[left]) && (up < right)) {up++;}
		while((table[down] > table[left]) && (down > left)) {down--;}
		if (up < down) {
			temp = table[up];
			table[up] = table[down];
			table[down] = temp;
		}
	} while (up < down);
	temp = table[left];
	table[left] = table[down];
	table[down] = temp;
	return down;
}

int QS::medianOfThree(int left, int right) {
	if (getSize() < 1 || left < 0 || right > getSize() - 1 || left >= right) {
		return -1;
	}
	int middle = (left + right) / 2;
	int temp = 0;
	if (table[left] > table[middle])  {
		temp = table[middle];
		table[middle] = table[left];
		table[left] = temp;
	}
	if (table[right] < table[middle]) {
		temp = table[middle];
		table[middle] = table[right];
		table[right] = temp;
	}
	if (table[middle] < table[left]) {
		temp = table[left];
		table[left] = table[middle];
		table[middle] = temp;
	}
	return middle;
}

void QS::quicksort(int first, int last) {
	if ((last - first) < 1) return;
	int pivot = medianOfThree(first, last);
	pivot = partition(first, last, pivot);
	quicksort(first, pivot - 1);
	quicksort(pivot + 1, last);
}

void QS::sortAll() {
	quicksort(0, getSize() - 1);
}
