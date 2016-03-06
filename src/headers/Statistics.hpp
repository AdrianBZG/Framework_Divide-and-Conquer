/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

#ifndef _STATISTICS_HPP_
#define _STATISTICS_HPP_

#include <vector>

using namespace std;

class Statistics {
    private:
	    int first_;
	    int second_;
	    int size_ = 0;
	    
    public:
	    Statistics();
	    ~Statistics();
	    
	    inline int getFirst() { return first_; }
	    inline int getSecond() { return second_; }
	    inline int getTestingCasesNumber() { return size_; }
	    inline void setTestingCasesNumber(int num) { size_ = num; }
	    
	    inline void addToFirst(int num) { first_ = num; }
	    inline void addToSecond(int num) { second_ = num; }
	    
	    void clear();
};

#endif /* _STATISTICS_HPP_ */
