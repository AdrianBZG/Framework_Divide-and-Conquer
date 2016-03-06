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
	unsigned int m = pow(2, int(ceil(log2(getSize()))));
    vector<int> inner(m);
    vector< vector<int> > APrep(m, inner), BPrep(m, inner), CPrep(m, inner);
	
    for(unsigned int i = 0; i < getSize() / 2; i++) {
        for (unsigned int j = 0; j < getSize() / 2; j++) {
            APrep[i][j] = getMatrixA()[i][j];
            BPrep[i][j] = getMatrixB()[i][j];
        }
    }
    solve(APrep, BPrep, CPrep, m);
}

void StrassenP::print() {
	for (int i=0; i < getSize() / 2; i++) {
        for (int j=0; j < getSize() / 2; j++) {
            cout << "\t";
            if(j == 0) cout << "[";
            cout << getMatrixC()[i][j];
            if(j != (getSize() / 2) - 1) {
                cout << ",";
            } else {
                cout << "]";
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
	if (size <= 1) { // Simple case
        basicMul(M1, M2, RM, size);
        return;
    }
    else { // Not a simple case
        int newSize = size/2;
        vector<int> inner (newSize);
        vector< vector<int> > 
            a11(newSize,inner), a12(newSize,inner), a21(newSize,inner), a22(newSize,inner),
            b11(newSize,inner), b12(newSize,inner), b21(newSize,inner), b22(newSize,inner),
            c11(newSize,inner), c12(newSize,inner), c21(newSize,inner), c22(newSize,inner),
            p1(newSize,inner), p2(newSize,inner), p3(newSize,inner), p4(newSize,inner), 
            p5(newSize,inner), p6(newSize,inner), p7(newSize,inner),
            aResult(newSize,inner), bResult(newSize,inner);
 
        int i, j;
        
 
        // Divide in 4 sub-matrix:
        for (i = 0; i < newSize; i++) {
            for (j = 0; j < newSize; j++) {
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
 
        // Calculate p1 to p7:
 
        sum(a11, a22, aResult, newSize); // a11 + a22
        sum(b11, b22, bResult, newSize); // b11 + b22
        solveRecursively(aResult, bResult, p1, newSize); // p1 = (a11+a22) * (b11+b22)
 
        sum(a21, a22, aResult, newSize); // a21 + a22
        solveRecursively(aResult, b11, p2, newSize); // p2 = (a21+a22) * (b11)
 
        sub(b12, b22, bResult, newSize); // b12 - b22
        solveRecursively(a11, bResult, p3, newSize); // p3 = (a11) * (b12 - b22)
 
        sub(b21, b11, bResult, newSize); // b21 - b11
        solveRecursively(a22, bResult, p4, newSize); // p4 = (a22) * (b21 - b11)
 
        sum(a11, a12, aResult, newSize); // a11 + a12
        solveRecursively(aResult, b22, p5, newSize); // p5 = (a11+a12) * (b22)   
 
        sub(a21, a11, aResult, newSize); // a21 - a11
        sum(b11, b12, bResult, newSize); // b11 + b12
        solveRecursively(aResult, bResult, p6, newSize); // p6 = (a21-a11) * (b11+b12)
 
        sub(a12, a22, aResult, newSize); // a12 - a22
        sum(b21, b22, bResult, newSize); // b21 + b22
        solveRecursively(aResult, bResult, p7, newSize); // p7 = (a12-a22) * (b21+b22)
 
        // Calculate c21, c21, c11 and c22:
 
        sum(p3, p5, c12, newSize); // c12 = p3 + p5
        sum(p2, p4, c21, newSize); // c21 = p2 + p4
 
        sum(p1, p4, aResult, newSize); // p1 + p4
        sum(aResult, p7, bResult, newSize); // p1 + p4 + p7
        sub(bResult, p5, c11, newSize); // c11 = p1 + p4 - p5 + p7
 
        sum(p1, p3, aResult, newSize); // p1 + p3
        sum(aResult, p6, bResult, newSize); // p1 + p3 + p6
        sub(bResult, p2, c22, newSize); // c22 = p1 + p3 - p2 + p6
 
        // Group the results in the result matrix:
        for (i = 0; i < newSize ; i++) {
            for (j = 0 ; j < newSize ; j++) {
                RM[i][j] = c11[i][j];
                RM[i][j + newSize] = c12[i][j];
                RM[i + newSize][j] = c21[i][j];
                RM[i + newSize][j + newSize] = c22[i][j];
            }
        }
    }
}

void StrassenP::sub(vector< vector<int> > M1, vector< vector<int> > M2, vector< vector<int> > &RM, int size) {
	int i, j;
 
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            RM[i][j] = M1[i][j] - M2[i][j];
        }
    } 
}

void StrassenP::sum(vector< vector<int> > M1, vector< vector<int> > M2, vector< vector<int> > &RM, int size) {
	int i, j;
 
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            RM[i][j] = M1[i][j] + M2[i][j];
        }
    }
}

void StrassenP::basicMul(vector< vector<int> > M1, vector< vector<int> > M2, vector< vector<int> > &RM, int size) {
	for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            for (int j = 0; j < size; j++) {
                RM[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
}