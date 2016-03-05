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
};

#endif /* _SOLUTION_HPP_ */
