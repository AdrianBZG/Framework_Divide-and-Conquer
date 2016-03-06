/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

#ifndef _MERGESORTS_HPP_
#define _MERGESORTS_HPP_

#include "Solution.hpp"

class MergeSortS: public Solution {
    private:
	    vector<int> array_;
	    static int count_;
	    
    public:
	    MergeSortS();
	    virtual ~MergeSortS();

	    void solve();
	    void combine(pair<Solution*,Solution*>);
	    Solution* getInstance();

	    void setValue(vector<int>);
	    
	    int& getCount ();
	    void resetCount();
};

#endif /* _MERGESORTS_HPP_ */
