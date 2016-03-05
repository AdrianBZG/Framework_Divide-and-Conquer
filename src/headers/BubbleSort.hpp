/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
    
    This is the BubbleSort algorithm, not included into the Framework because it not uses a 'Divide and Conquer' approach, the idea is to compare the complexity of this
    algorithm with the complexity of Merge Sort (that uses Divide and Conquer)
*/

#ifndef _BUBBLESORT_HPP_
#define _BUBBLESORT_HPP_

#include <vector>
#include <iostream>

using namespace std;

class BubbleSort {
    private:
	    vector<int> array_;
	    
    public:
	    BubbleSort(vector<int>);
	    ~BubbleSort();
	    
	    vector<int> getArray();
	    void setArrayItem(int,int);

	    void print();
	    void sort();
};

#endif /* _BUBBLESORT_HPP_ */
