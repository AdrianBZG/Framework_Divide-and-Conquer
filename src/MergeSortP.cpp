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

void MergeSortP::simplySolve(Solution* s) {
	if (array_.size() == 1){
		vector<int> U(0);
		array_ = U;
	} else {
		vector<int> U;
		U.push_back(*max_element(array_.cbegin(),array_.cend()));
		array_ = U;
	}
	((MergeSortS*)s)->setValue(array_);
}
