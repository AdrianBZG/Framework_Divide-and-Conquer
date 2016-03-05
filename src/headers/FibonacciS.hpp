/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

#ifndef _FIBONACCIS_HPP_
#define _FIBONACCIS_HPP_

#include "Solution.hpp"

class FibonacciS: public Solution {
    private:
	    int _n;
	    
    public:
	    FibonacciS();
	    virtual ~FibonacciS();

	    void solve();
	    void combine(pair<Solution*,Solution*>);
	    Solution* getInstance();

	    void setValue(int);
};

#endif /* _FIBONACCIS_HPP_ */
