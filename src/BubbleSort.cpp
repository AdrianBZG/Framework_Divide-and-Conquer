/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
    
    This is the BubbleSort algorithm, not included into the Framework because it not uses a 'Divide and Conquer' approach, the idea is to compare the complexity of this
    algorithm with the complexity of Merge Sort (that uses Divide and Conquer)
*/

#include "headers/BubbleSort.hpp"

BubbleSort::BubbleSort(vector<int> array) {
	array_ = array;
}

BubbleSort::~BubbleSort() {
	array_.clear();
}

vector<int> BubbleSort::getArray() {
	return array_;
}

void BubbleSort::setArrayItem (int index, int item) {
	array_[index] = item;
}

void BubbleSort::sort() {
	int aux; 	//Temp var to swap the items
	for(unsigned i = 0; i < getArray().size() - 1; i++) {
		for(unsigned j = 0; j < getArray().size() - 1 - i; j++) {
			if(getArray()[j] > getArray()[j+1])
			{
				count_++; //Statistics
				aux=getArray()[j];
				setArrayItem(j, getArray()[j+1]);
				setArrayItem(j+1, aux);
			}
		}
	}
}

void BubbleSort::print() {
	for(auto element : array_) {
		cout << element << " ";
	}
	cout << endl;
}
