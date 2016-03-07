/*
    Author: Adrián Rodríguez Bazaga
    Contact: arodriba@ull.edu.es / alu0100826456@ull.edu.es
    Date: 05/03/2016
*/

#include "headers/StrassenP.hpp"

StrassenP::StrassenP(vector< vector<int> > A, vector< vector<int> > B) {
	matrixA_ = A;
	matrixB_ = B;
	size_ = A.size() + A[0].size();
	matrixC_.resize(size_);
}

StrassenP::~StrassenP() {
	matrixA_.clear();
	matrixB_.clear();
	matrixC_.clear();
	size_ = -1;
}

void StrassenP::init() {
    unsigned int nextPowerOfTwo = pow(2, int(ceil(log2(getSize()))));
    vector<int> innerMatrix(nextPowerOfTwo);
    vector< vector<int> > auxMatrixA(nextPowerOfTwo, innerMatrix), auxMatrixB(nextPowerOfTwo, innerMatrix), auxMatrixC(nextPowerOfTwo, innerMatrix);
	
    for(unsigned int i = 0; i < getSize() / 2; i++) {
        for (unsigned int j = 0; j < getSize() / 2; j++) {
            auxMatrixA[i][j] = getMatrixA()[i][j];
            auxMatrixB[i][j] = getMatrixB()[i][j];
        }
    }
    solve(auxMatrixA, auxMatrixB, auxMatrixC, nextPowerOfTwo);
}

void StrassenP::print() {
	for (int i=0; i < getSize() / 2; i++) {
        for (int j=0; j < getSize() / 2; j++) {
            cout << "\t\t";
            if(j == 0) cout << "|";
            cout << getMatrixC()[i][j];
            if(j != (getSize() / 2) - 1) {
                cout << ",";
            } else {
                cout << "|";
            }
        }
        cout << endl;
    }
}

void StrassenP::solve(vector< vector<int> > &M1, vector< vector<int> > &M2, vector< vector<int> > &RM, int size) {
	solveRecursively(M1, M2, RM, size);
	setMatrixC(RM);
	print();
}

void StrassenP::solveRecursively(vector< vector<int> > &M1, vector< vector<int> > &M2, vector< vector<int> > &RM, int size) {
    if (isSimple(size)) { // Simple case
        simplySolve(M1, M2, RM, size); //We perform the simply silve: a basic multiplication
        return;
    }
    else { // Not a simple case
        int newSize = size/2;
        vector<int> innerMatrix (newSize);
        vector< vector<int> > 
            a11(newSize,innerMatrix), a12(newSize,innerMatrix), a21(newSize,innerMatrix), a22(newSize,innerMatrix),
            b11(newSize,innerMatrix), b12(newSize,innerMatrix), b21(newSize,innerMatrix), b22(newSize,innerMatrix),
            c11(newSize,innerMatrix), c12(newSize,innerMatrix), c21(newSize,innerMatrix), c22(newSize,innerMatrix),
            p1(newSize,innerMatrix), p2(newSize,innerMatrix), p3(newSize,innerMatrix), p4(newSize,innerMatrix), 
            p5(newSize,innerMatrix), p6(newSize,innerMatrix), p7(newSize,innerMatrix),
            aResult(newSize,innerMatrix), bResult(newSize,innerMatrix);
 
        
 
        // Divide in 4 sub-matrix:
        for (unsigned i = 0; i < newSize; i++) {
            for (unsigned j = 0; j < newSize; j++) {
                a11[i][j] = M1[i][j];
                a12[i][j] = M1[i][j + newSize];
                a21[i][j] = M1[i + newSize][j];
                a22[i][j] = M1[i + newSize][j + newSize];
 
                b11[i][j] = M2[i][j];
                b12[i][j] = M2[i][j + newSize];
                b21[i][j] = M2[i + newSize][j];
                b22[i][j] = M2[i + newSize][j + newSize];
            }
        }
 
        // Now we are going to solve the 7 subproblems (p1...p7):
 
        sum(a11, a22, aResult, newSize); // a11 + a22
        sum(b11, b22, bResult, newSize); // b11 + b22
        //Re-calling recursively to solve this subproblem
        solveRecursively(aResult, bResult, p1, newSize); // p1 = (a11+a22) * (b11+b22)
 
        sum(a21, a22, aResult, newSize); // a21 + a22
        //Re-calling recursively to solve this subproblem
        solveRecursively(aResult, b11, p2, newSize); // p2 = (a21+a22) * (b11)
 
        sub(b12, b22, bResult, newSize); // b12 - b22
        //Re-calling recursively to solve this subproblem
        solveRecursively(a11, bResult, p3, newSize); // p3 = (a11) * (b12 - b22)
 
        sub(b21, b11, bResult, newSize); // b21 - b11
        //Re-calling recursively to solve this subproblem
        solveRecursively(a22, bResult, p4, newSize); // p4 = (a22) * (b21 - b11)
 
        sum(a11, a12, aResult, newSize); // a11 + a12
        //Re-calling recursively to solve this subproblem
        solveRecursively(aResult, b22, p5, newSize); // p5 = (a11+a12) * (b22)   
 
        sub(a21, a11, aResult, newSize); // a21 - a11
        sum(b11, b12, bResult, newSize); // b11 + b12
        //Re-calling recursively to solve this subproblem
        solveRecursively(aResult, bResult, p6, newSize); // p6 = (a21-a11) * (b11+b12)
 
        sub(a12, a22, aResult, newSize); // a12 - a22
        sum(b21, b22, bResult, newSize); // b21 + b22
        //Re-calling recursively to solve this subproblem
        solveRecursively(aResult, bResult, p7, newSize); // p7 = (a12-a22) * (b21+b22)
 
        // Calculating the final submatrix c21, c21, c11 and c22:
 
        sum(p3, p5, c12, newSize); // c12 = p3 + p5
        sum(p2, p4, c21, newSize); // c21 = p2 + p4
 
        sum(p1, p4, aResult, newSize); // p1 + p4
        sum(aResult, p7, bResult, newSize); // p1 + p4 + p7
        sub(bResult, p5, c11, newSize); // c11 = p1 + p4 - p5 + p7
 
        sum(p1, p3, aResult, newSize); // p1 + p3
        sum(aResult, p6, bResult, newSize); // p1 + p3 + p6
        sub(bResult, p2, c22, newSize); // c22 = p1 + p3 - p2 + p6
 
        // Group the results in a result matrix:
        for (unsigned i = 0; i < newSize ; i++) {
            for (unsigned j = 0 ; j < newSize ; j++) {
                RM[i][j] = c11[i][j];
                RM[i][j + newSize] = c12[i][j];
                RM[i + newSize][j] = c21[i][j];
                RM[i + newSize][j + newSize] = c22[i][j];
            }
        }
    }
}

void StrassenP::sub(vector< vector<int> > M1, vector< vector<int> > M2, vector< vector<int> > &RM, int size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size; j++) {
            RM[i][j] = M1[i][j] - M2[i][j];
        }
    } 
}

void StrassenP::sum(vector< vector<int> > M1, vector< vector<int> > M2, vector< vector<int> > &RM, int size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size; j++) {
            RM[i][j] = M1[i][j] + M2[i][j];
        }
    }
}

void StrassenP::basicMul(vector< vector<int> > M1, vector< vector<int> > M2, vector< vector<int> > &RM, int size) {
    RM[0][0] = M1[0][0] * M2[0][0]; // O(1) operation
}

bool StrassenP::isSimple(int size) {
    return (size == 1); //Just one element, we ended dividing the matrix
}

void StrassenP::simplySolve(vector< vector<int> > M1, vector< vector<int> > M2, vector< vector<int> > &RM, int size) {
    basicMul(M1, M2, RM, size); //We multiply the unique elements from matrix M1 and M2 and store it in RM; RM[0,0] = M1[0,0] * M2[0,0]
}