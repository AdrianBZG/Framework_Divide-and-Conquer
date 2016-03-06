/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

#ifndef _STRASSENP_HPP_
#define _STRASSENP_HPP_

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class StrassenP {
    private:
	    vector< vector<int> > matrixA_;
	    vector< vector<int> > matrixB_;
	    vector< vector<int> > matrixC_;
	    int size_;
	    
    public:
	    StrassenP(vector< vector<int> >, vector< vector<int> >);
	    ~StrassenP();
	    
	    inline vector< vector<int> > getMatrixA() { return matrixA_; }
	    inline vector< vector<int> > getMatrixB() { return matrixB_; }
	    inline vector< vector<int> > getMatrixC() { return matrixC_; }
	    inline void setMatrixC(vector< vector<int> > newC) { matrixC_ = newC; }
	    inline int getSize() { return size_; }
	    
	    bool isSimple(int);
	    void simplySolve(vector< vector<int> >, vector< vector<int> >, vector< vector<int> >&, int);

        void init();
	    void solveRecursively(vector< vector<int> >&, vector< vector<int> >&, vector< vector<int> >&, int);
	    void solve(vector< vector<int> >&, vector< vector<int> >&, vector< vector<int> >&, int);
	    void print();
	    
	    void sub(vector< vector<int> >, vector< vector<int> >, vector< vector<int> >&, int);
	    void sum(vector< vector<int> >, vector< vector<int> >, vector< vector<int> >&, int);
	    void basicMul(vector< vector<int> >, vector< vector<int> >, vector< vector<int> >&, int);
};

#endif /* _STRASSENP_HPP_ */
