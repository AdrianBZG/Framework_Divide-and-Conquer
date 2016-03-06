/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

#include <iostream>

#include "headers/MergeSortS.hpp"

MergeSortS::MergeSortS() {
}

MergeSortS::~MergeSortS() {
}


void MergeSortS::solve() {
	for(auto element : array_) {
		cout << element << " ";
	}
	cout << endl;
}

void MergeSortS::combine(pair<Solution*,Solution*> subSolutions) {
	vector<int> a1 = (((MergeSortS*)subSolutions.first))->array_;
	vector<int> a2 = ((MergeSortS*)subSolutions.second)->array_;
	
	//Centinelas
	a1.push_back(9999999);
	a2.push_back(9999999);
	//
	//Temp vars
	unsigned i = 0;
	unsigned j = 0;
	unsigned size = (a1.size()-1) + (a2.size()-1);
	//
	//Resize the solution array
	array_.resize(size);
	//
	
	for(unsigned k=0; k < size; k++)
	{
		if((a1[i] < a2[j]))
		{
			array_[k] = a1[i];
			i++;
			count_++; //Statistics
		}
		else
		{
			array_[k] = a2[j];
			j++;
			count_++; //Statistics
		}
	}
}

Solution* MergeSortS::getInstance() {
	return new MergeSortS();
}

int& MergeSortS::getCount () {
	return count_;
}

void MergeSortS::setValue(vector<int> array) {
	array_ = array;
}

void MergeSortS::resetCount() {
	count_ = 0;
}

int MergeSortS::count_ = 0;