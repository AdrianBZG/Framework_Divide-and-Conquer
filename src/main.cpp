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
#include "headers/MergeSortP.hpp"
#include "headers/MergeSortS.hpp"
//

//BubbleSort (Not using framework, cause not using Divide and Conquer approach)
#include "headers/BubbleSort.hpp"
//

using namespace std;

int main(int argc, char **argv) {
    
	/*
	//THIS IS USED TO CHECK PARAMETERS IN CASE WE NEED THEM
	if (argc != 2) {
		cout << "\nIncorrect number of parameters. Found: " << argc-1 << ". Required: 1"<< endl;
		exit(-1);
	}*/
    vector<int> arrayToSort = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3};
	Problem* problem = new MergeSortP(arrayToSort);
	Solution* solution = new MergeSortS();
	Framework* framework = new Framework();

	framework->divideAndConquer(problem, solution);
	cout << "\nResult (MergeSort):" << endl;
	solution->solve();
	
	
	BubbleSort bs(arrayToSort);
	bs.sort();
	cout << "\nResult (BubbleSort):" << endl;
	bs.print();
}