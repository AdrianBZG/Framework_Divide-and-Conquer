/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

#ifndef _PROBLEM_HPP_
#define _PROBLEM_HPP_

#include <vector>
#include <utility>
#include <iostream>
#include "Solution.hpp"

using namespace std;

class Problem {
    public:
	    Problem();
	    virtual ~Problem();

	    virtual bool isSimple();
	    virtual pair<Problem*,Problem*> decompose();
	    virtual void simplySolve(Solution* s);
};

#endif /* _PROBLEM_HPP_ */
