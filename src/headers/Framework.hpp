/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

#ifndef _FRAMEWORK_HPP_
#define _FRAMEWORK_HPP_

#include <vector>
#include <utility>
#include <iostream>
#include "Problem.h"
#include "Solution.h"
using namespace std;

class Framework {
    public:
	    Framework();
	    virtual ~Framework();
	    void divideAndConquer(Problem* p, Solution* s);
};

#endif /* _FRAMEWORK_HPP_ */
