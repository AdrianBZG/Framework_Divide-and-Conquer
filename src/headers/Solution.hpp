/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
    public:
	    Solution();
	    virtual ~Solution();

	    virtual void solve();
	    virtual void combine(pair<Solution*,Solution*>);
	    virtual Solution* getInstance();
	    
	    virtual int& getCount ();
	    virtual void resetCount ();
};

#endif /* _SOLUTION_HPP_ */
