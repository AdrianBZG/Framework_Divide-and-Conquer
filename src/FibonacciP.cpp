/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

#include "headers/FibonacciP.hpp"

FibonacciP::FibonacciP(int n) : Problem::Problem() {
	_n = n;
}

FibonacciP::~FibonacciP() {

}

bool FibonacciP::isSimple() {
	return (_n < 2);
}

pair<Problem*,Problem*> FibonacciP::decompose() {
	pair<Problem*,Problem*> subProblems;
	subProblems.first = new FibonacciP(_n-1);
	subProblems.second = new FibonacciP(_n-2);
	return subProblems;
}

void FibonacciP::simplySolve(Solution* s) {
	if (_n == 0){  // caso especial fibonacci(0) = 1
		_n = 1;
	}
	((FibonacciS*)s)->setValue(_n);
}
