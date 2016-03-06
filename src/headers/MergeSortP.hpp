/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

#ifndef _MERGESORTP_HPP_
#define _MERGESORTP_HPP_

#include "Problem.hpp"
#include "MergeSortS.hpp"

class MergeSortP: public Problem {
    private:
	    vector<int> array_;
	    static int count_;
	    
    public:
	    MergeSortP(vector<int>);
	    virtual ~MergeSortP();

	    bool isSimple();
	    pair<Problem*,Problem*> decompose();
	    void simplySolve(Solution* s);
	    
	    int& getCount ();
	    void resetCount();
};

#endif /* _MERGESORTP_HPP_ */
