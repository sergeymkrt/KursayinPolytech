//
//  Matrix.hpp
//  KursayinPolytech
//
//  Created by Sergey Mkrtumyan on 08.10.21.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool sortByVal(const pair<int, int> &a,
               const pair<int, int> &b);

class Matrix{
public:
    int** myMat;
    int M,N;
    vector<pair<int,int>> rowValues;
    Matrix(int m, int n);
    void printMatrix();
    void printSumMap();
    void sortRowValues();
    void sortMatrix();
    int SumOfRow(int n);
    void SetRow(Matrix* mat, int rowNum, int newMatRowNum);
    void sortRows();
};

#endif /* Matrix_hpp */
