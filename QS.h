#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "QSInterface.h"
using namespace std; 
          
class QS : public QSInterface {
        private:
                int *table = 0;
	      	int numberElements;
		int insertIndex;	
        public: 
                QS();
                ~QS();
                bool createArray(int capacity);
                bool addToArray(int value);
                void clear();
                string getArray() const;
                int getSize() const;  
                int partition(int left, int right, int pivotIndex);
                int medianOfThree(int left, int right);
                void sortAll(); 
                void quicksort(int first, int last);
};   
