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
    void sortRows();
private:
    void SetRow(Matrix* mat, int rowNum, int newMatRowNum);
    int SumOfRow(int n);
};

class PrintMatrix{
public:
     void printRow(int n,int xOfFirst, int yOfFirst, Matrix* m);
     void eraseRow(int xOfFirst, int yOfFirst, Matrix* m);
     void moveRow(int xOfFirst, int yOfFirst, int xOfSecond, int yOfSecond,int n, Matrix* m);
     void getMatrixLow(int xOfFirst, int yOfFirst,int n ,int j,int index,vector<pair<int,int>>, Matrix* m);
     
};

#endif /* Matrix_hpp */

