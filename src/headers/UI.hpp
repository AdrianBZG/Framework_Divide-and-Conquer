/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
    
    This is the UI class, the tests are always done with 10 problems but each problem has a defined-by-user quantity of items (for example 50 integers)
*/

#ifndef _UI_HPP_
#define _UI_HPP_

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <random>

//Include the mandatory files to use the Framework
#include "headers/Framework.hpp"
//
//Include the specific problems implementations
#include "headers/FibonacciP.hpp"
#include "headers/FibonacciS.hpp"
#include "headers/MergeSortP.hpp"
#include "headers/MergeSortS.hpp"
#include "headers/StrassenP.hpp"
//

//BubbleSort (Not using framework, cause not using Divide and Conquer approach)
#include "headers/BubbleSort.hpp"
//

//Statitics Class
#include "headers/Statistics.hpp"
//

using namespace std;


class UI
{
    private:
        vector<int> definedVector;
        vector< vector<int> > definedMatrixA;
        vector< vector<int> > definedMatrixB;
        vector< vector<int> > randomVectors;
        int testProblemsSize;
        vector<Statistics> statistics;
        
    public:
        UI();
        ~UI();
        
        void init();
        void showMenu();
        void waitForKey();
        
        void generateRandomVectors(int problemSize);
        void showTable(vector<int>); //Show the result table
        void doStudy(int);  //Do a full study with 'int' problem size
        void doSpecificStudy(vector<int>);
};

#endif