/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

//Include the User Interface
#include "headers/UI.hpp"
//

using namespace std;

int main(int argc, char **argv) {
    
	/*
	//THIS IS USED TO CHECK PARAMETERS IN CASE WE NEED THEM
	if (argc != 2) {
		cout << "\nIncorrect number of parameters. Found: " << argc-1 << ". Required: 1"<< endl;
		exit(-1);
	}*/
	
	UI ui1;
    ui1.init();
	
    /*vector<int> arrayToSort = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3,3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3,3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3};
    int c1 = 0;
	Problem* problem = new MergeSortP(arrayToSort);
	Solution* solution = new MergeSortS();
	Framework* framework = new Framework();
	framework->divideAndConquer(problem, solution);
	cout << "\nResult (MergeSort):" << endl;
	solution->solve();
	
	Statistics statistics;
	statistics.addToFirst(problem->getCount() + solution->getCount());
	cout << "Number of comparisons: " << statistics.getFirst()[0] << endl;
	
	BubbleSort bs(arrayToSort);
	bs.sort();
	cout << "\nResult (BubbleSort):" << endl;
	bs.print();
	cout << "Number of comparisons: " << bs.getCount() << endl;*/
	
	
	/* Testing Strassen multiplication:
	Matrix A: 1 2
	          3 4
	          
	Matrix B: 5 6
	          7 8
	          
	Result should be:
	          19 22
	          43 50
	*/
	
	//Initialize matrix data
	//Matrix A
	/*vector< vector<int> > matA;
	vector<int> auxRow1 = {1, 2};
	vector<int> auxRow2 = {3, 4};
	matA.push_back(auxRow1);
	matA.push_back(auxRow2);
	//MatrixB
	vector< vector<int> > matB;
	vector<int> auxRow3 = {5, 6};
	vector<int> auxRow4 = {7, 8};
	matB.push_back(auxRow3);
	matB.push_back(auxRow4);
	//End initialize matrix data
	
	StrassenP strassenProblem (matA, matB);
	cout << "\nResult (Matrix multiplication with Strassen Algorithm):" << endl;
	strassenProblem.init();*/
}