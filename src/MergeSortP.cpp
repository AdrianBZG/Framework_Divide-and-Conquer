/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

#include "headers/MergeSortP.hpp"

MergeSortP::MergeSortP(vector<int> array) : Problem::Problem() {
	array_ = array;
}

MergeSortP::~MergeSortP() {

}

bool MergeSortP::isSimple() {
	return (array_.size() < 3);
}

pair<Problem*,Problem*> MergeSortP::decompose() {
	pair<Problem*,Problem*> subProblems;
	
	vector<int> U(array_.cbegin(),array_.cbegin()+array_.size()/2);
	vector<int> V(array_.cbegin()+array_.size()/2,array_.cend());
	
	subProblems.first = new MergeSortP(U);
	subProblems.second = new MergeSortP(V);
	return subProblems;
}

int& MergeSortP::getCount () {
	return count_;
}

void MergeSortP::simplySolve(Solution* s) {
	if (array_.size() == 1){
		vector<int> U;
		U.push_back(array_[0]);
		array_ = U;
		count_++; //Statistics
	} else if (array_.size() == 2) {
		vector<int> U = array_;
		//Swap it if it's not correctly ordered
		if(U[0] > U[1]) {
			int aux = U[0];
			U[0] = U[1];
			U[1] = aux;
		}
		count_++; //Statistics
		//
		array_ = U;
	} else if (array_.size() > 2) {
		//Sort the elements
		vector<int> U = array_;
		sort(U.begin(), U.end());
		array_ = U;
		count_++; //Statistics
		//
	}
	((MergeSortS*)s)->setValue(array_);
}

void MergeSortP::resetCount() {
	count_ = 0;
}

int MergeSortP::count_ = 0;
