/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

#include "headers/Framework.hpp"

Framework::Framework() {
}

Framework::~Framework() {
}

void Framework::divideAndConquer(Problem* p, Solution* s){
	if (p->isSimple()){
		p->simplySolve(s);
	}
	else{
		pair<Problem*,Problem*> subProblems;
		pair<Solution*,Solution*> subSolutions;
		subProblems = p->decompose();
		subSolutions.first = s->getInstance();
		subSolutions.second = s->getInstance();
		divideAndConquer(subProblems.first, subSolutions.first);  //.1
		divideAndConquer(subProblems.second, subSolutions.second);  //.2
		s->combine(subSolutions);
	}
};