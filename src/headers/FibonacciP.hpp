/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

#ifndef _FIBONACCIP_HPP_
#define _FIBONACCIP_HPP_

#include "Problem.hpp"
#include "FibonacciS.hpp"

class FibonacciP: public Problem {
    private:
	    int _n;
	    
    public:
	    FibonacciP(int);
	    virtual ~FibonacciP();

	    bool isSimple();
	    pair<Problem*,Problem*> decompose();
	    void simplySolve(Solution* s);
};

#endif /* _FIBONACCIP_HPP_ */
