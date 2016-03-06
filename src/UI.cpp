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
        cout << "\nType 'y' to go back to the menu" << endl;
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
        cout << "f. Run full study (t=10, t=50, t=100, t=1000, t=10000, t=100000; MS+BS)\n";
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
            case 'd':
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
	            statistics[0].addToFirst(problem->getCount() + solution->getCount());
	            problem->resetCount();
	            solution->resetCount();
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
	            cout << "Size: " << definedVector.size() << "\t\t\t"<< statistics[0].getFirst()[0] << "\t\t" << statistics[0].getSecond()[0] << endl;
                
                waitForKey();
                break;
        }
    }while(opcion!='h');
    //
    
    system("clear"); //Clean the screen
    cout << "You have exited the program succesfully (Code 1)" << endl;
}

void UI::generateRandomVectors(int problemSize) {
    //
    //
}

//
#endif