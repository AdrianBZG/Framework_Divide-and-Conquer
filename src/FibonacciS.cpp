/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

#include <iostream>

#include "headers/FibonacciS.hpp"

FibonacciS::FibonacciS() : Solution::Solution() {
}

FibonacciS::~FibonacciS() {
}


void FibonacciS::solve() {
	cout << _n << endl;
}

void FibonacciS::combine(pair<Solution*,Solution*> subSolutions) {
	int n1 = (((FibonacciS*)subSolutions.first))->_n;
	int n2 = ((FibonacciS*)subSolutions.second)->_n;
	_n = n1+n2;
}

Solucion* FibonacciS::getInstance() {
	return new FibonacciS();
}

void FibonacciS::setValue(int n) {
	_n = n;
}