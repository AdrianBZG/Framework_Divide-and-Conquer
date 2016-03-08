/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 14/02/2016
*/

#ifndef _UI_CPP_
#define _UI_CPP_

#include "headers/UI.hpp"

using namespace std;

//Implementations

UI::UI(void) { 
}

UI::~UI(void) {
}

void UI::init(void) {
    //Show the menu
    showMenu();
    //
}

void UI::waitForKey(void) { 
    char selection = '0';
    while(selection!='y') {
        cout << "\nType 'y' to continue" << endl;
        cin >> selection;
    }
    system("clear"); //Clean the screen
}

void UI::showMenu(void) {
    //Here we show the menu
    char opcion = '0';
    int aux, aux2, aux3;
    string str1;
    
    do {
        cout << endl << "=====================================================\n";
        cout << "Algorithms: Divide and Conquer\n";
        cout << "By Adrian Rodriguez Bazaga (https://www.github.com/AdrianBZG)\n";
        cout << "a. Define test vector\n";
        cout << "b. Define test matrix (A and B)\n";
        cout << "c. Generate random test vectors with defined problems size\n";
        cout << "d. Run and show statistics for defined vector (MS+BS)\n";
        cout << "e. Run and show statistics of defined problems size (MS+BS)\n";
        cout << "f. Run full study (MS+BS)\n";
        cout << "g. Perform matrix multiplication (Strassen Algorithm)\n";
        cout << "h. Exit\n";
        cout << "=====================================================\n";
        cout << "Choose your option >";
      

        cin >> opcion;
        switch (opcion){
            case 'a':
                cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
                system("clear"); //Clean the screen
                
                definedVector.clear();
                cout << "Vector size?:" << endl;
                cin >> aux;
                definedVector.resize(aux);
                for(int i = 0; i < aux; i++) {
                    cout << "V[" << i << "]?:" << endl;
                    cin >> aux2;
                    definedVector[i] = aux2;
                }
                
                waitForKey();
                break;
            case 'b':
                cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
                system("clear"); //Clean the screen
                
                definedMatrixA.clear();
                definedMatrixB.clear();
                cout << "Rows and columns of the two matrix?:" << endl;
                cin >> aux;
                definedMatrixA.resize(aux);
                definedMatrixB.resize(aux);
                
                for(int i = 0; i < aux; i++) {
                    definedMatrixA[i].resize(aux);
                    definedMatrixB[i].resize(aux);
                }
                
                //Set values
                for(int i = 0; i < aux; i++) {
                    for (int j = 0; j < aux; j++) {
                        cout << "MatrixA[" << i << "," << j << "] ?:" << endl;
                        cin >> aux3;
                        definedMatrixA[i][j] = aux3;
                        cout << "MatrixB[" << i << "," << j << "] ?:" << endl;
                        cin >> aux3;
                        definedMatrixB[i][j] = aux3;
                    }
                }
                //
                
                waitForKey();
                break;
            case 'c':
                cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
                system("clear"); //Clean the screen
                
                randomVectors.clear();
                cout << "Problems size (Quantity of elements in each vector)?:" << endl;
                cin >> aux;
                generateRandomVectors(aux);
                
                waitForKey();
                break;
            case 'd': {
                cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
                system("clear"); //Clean the screen
                statistics.clear();
                statistics.resize(1);
                
                //MS
                Problem* problem = new MergeSortP(definedVector);
    	        Solution* solution = new MergeSortS();
	            Framework* framework = new Framework();
	            framework->divideAndConquer(problem, solution);
	            cout << "\nResult (MergeSort):" << endl;
	            solution->solve();
	            statistics[0].addToFirst(problem->getCount());
	            problem->resetCount();
	            //
	            
	            //BS
	            BubbleSort bs(definedVector);
            	bs.sort();
	            cout << "\nResult (BubbleSort):" << endl;
	            bs.print();
	            statistics[0].addToSecond(bs.getCount());
	            //
	            cout << endl << "Statistics:" << endl;
	            cout << "Comparisons\t\t\tMergeSort\tBubbleSort" << endl;
	            cout << "Size: " << definedVector.size() << "\t\t\t"<< statistics[0].getFirst() << "\t\t" << statistics[0].getSecond() << endl;
                
                waitForKey();
                break;
            }
            case 'e': {
                cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
                system("clear"); //Clean the screen
                
                doStudy(10);
                
                break;
            }
            case 'f': {
                cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
                system("clear"); //Clean the screen
                
                for(int i = 100; i <= 1000; i+=100) {
                	doStudy(i);
                }
                
                break;
            }
            case 'g':
                cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
                system("clear"); //Clean the screen
                
                StrassenP strassenProblem (definedMatrixA, definedMatrixB);
	            cout << "\nResult (Matrix multiplication with Strassen Algorithm):" << endl;
	            strassenProblem.init();
                
                waitForKey();
                break;
        }
    }while(opcion!='h');
    //
    
    system("clear"); //Clean the screen
    cout << "You have exited the program succesfully (Code 1)" << endl;
}

void UI::generateRandomVectors(int problemSize) {
    randomVectors.clear();
    randomVectors.resize(10);
    testProblemsSize = problemSize;
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < problemSize; j++) {
            if(j == 0) randomVectors[i].resize(problemSize);
            randomVectors[i][j] = (rand() % 30000) + 1;
        }
    }
}

void UI::doStudy(int problemSize) {
	const int MAX_INT_NUMBER = 2147483646;
	//For t=problemSize
    generateRandomVectors(problemSize);
    statistics.clear();
    statistics.resize(problemSize); //problemSize for MS and problemSize for BS, n=10 always (An Statistics object is a pair First (MS), Second (BS))
                
    for(int i = 0; i < 10; i++) {
    	//MS
        Problem* problem = new MergeSortP(randomVectors[i]);
    	Solution* solution = new MergeSortS();
	    Framework* framework = new Framework();
	    framework->divideAndConquer(problem, solution);
	    statistics[i].addToFirst(problem->getCount());
	    delete problem;
	    delete solution;
	    //
	    //BS
	    BubbleSort bs(randomVectors[i]);
        bs.sort();
    	statistics[i].addToSecond(bs.getCount());
	    //
    }
    
    //Gettings min, average and max from statistics
    int minMS = MAX_INT_NUMBER, minBS = MAX_INT_NUMBER;
    int aveMS = 0, aveBS = 0;
    int maxMS = 0, maxBS = 0;
    for(int i = 0; i < 10; i++) {
        //Average accum
        aveMS += statistics[i].getFirst();
        aveBS += statistics[i].getSecond();
        //
        
        //Min
        if(statistics[i].getFirst() < minMS) minMS = statistics[i].getFirst();
        if(statistics[i].getSecond() < minBS) minBS = statistics[i].getSecond();
        //
        
        //Max
        if(statistics[i].getFirst() > maxMS) maxMS = statistics[i].getFirst();
        if(statistics[i].getSecond() > maxBS) maxBS = statistics[i].getSecond();
        //
    }
    
    //Final operation to calculate the average
    aveMS /= 10;
    aveBS /= 10;
    //
    
    //Group the statistics result into an array and call showTable with that Array
    vector<int> results;
    results.push_back(problemSize);
    results.push_back(minMS);
    results.push_back(minBS);
    results.push_back(aveMS);
    results.push_back(aveBS);
    results.push_back(maxMS);
    results.push_back(maxBS);
    showTable(results);
}

void UI::showTable(vector<int> results) {
	system("clear"); //Clean the screen
	//Showing statistics for this study (values stored in the 'results' Array of int)
    cout << endl << "Statistics (Size = " << results[0] << "):" << endl;
    cout << "MergeSort\t\t\tMin\tAverage\tMax" << endl;
    cout << "\t\t\t\t"<< results[1] << "\t" << results[3] << "\t" << results[5] << endl << endl;
    cout << "BubbleSort\t\t\tMin\tAverage\tMax" << endl;
    cout << "\t\t\t\t"<< results[2] << "\t" << results[4] << "\t" << results[6] << endl << endl;
    
    waitForKey();
}

//
#endif