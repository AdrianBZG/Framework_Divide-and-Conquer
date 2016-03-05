/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

#include <cstdio>
#include <iostream>
#include <cstdlib>

//Include the mandatory files to use the Framework
#include "headers/Framework.hpp"
//
//Include the specific problems implementations
#include "headers/FibonacciP.hpp"
#include "headers/FibonacciS.hpp"
//

using namespace std;

int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "\nIncorrect number of parameters. Found: " << argc-1 << ". Required: 1"<< endl;
		exit(-1);
	}

	Problem* problem = new FibonacciP(atoi(argv[1]));
	Solution* solution = new FibonacciS();
	Framework* framework = new Framework();

	framework->divideAndConquer(problem, solution);
	cout << "\nResult:" << endl;
	solution->solve();
}