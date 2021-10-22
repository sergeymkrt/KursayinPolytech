//
//  Matrix.cpp
//  KursayinPolytech
//
//  Created by Sergey Mkrtumyan on 08.10.21.
//

#include "Matrix.hpp"
#include <iostream>
#include <ctime>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <curses.h>
#include <unistd.h>

using namespace std;

bool sortByVal(const pair<int, int> &a,
               const pair<int, int> &b)
{
  return (a.second > b.second);
}


Matrix::Matrix(int m,int n){
    
    myMat = new int*[m];
    
    // dynamically create an array of pointers of size `M`
    for (int i = 0; i < m; i++) {
      myMat[i] = new int[n];
    }
    
    
    srand((unsigned) time(0));
    
    // dynamically allocate memory of size `N` for each row
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++) {
        myMat[i][j] = (rand() % 80)+10;
      }
    }
    M = m;
    N = n;
    
    for (int i = 0; i < M; i++) {
      rowValues.push_back(make_pair(i, SumOfRow(i)));
      //rowValues[i] = SumOfRow(i);
    }
    //printSumMap();
    
}

void Matrix::printMatrix(){
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
          if(myMat[i][j] % 10 > 0 && myMat[i][j] / 10 == 0){
              cout<< " "<<myMat[i][j]<<" ";
          }
          else{
              cout<<myMat[i][j] << " ";
          }
      }
      cout << endl;
    }
}

void Matrix::printSumMap(){
    for (int i = 0; i < rowValues.size(); i++)
    {
      cout << rowValues[i].first << ": " << rowValues[i].second << endl;
    }
}

void Matrix::sortRowValues(){
    sort(rowValues.begin(),rowValues.end(),sortByVal);
}

void Matrix::sortMatrix(){
    for (int i = 0 ; i < M; i++) {
      sort(myMat[i],myMat[i] + N, greater<int>());
    }
}



int Matrix::SumOfRow(int n){
    int sum = 0;
    for (int i = 0; i<M; i++) {
      sum += myMat[n][i];
    }
    return sum;
}
  
void Matrix::SetRow(Matrix* mat, int rowNum, int newMatRowNum){
    for (int i = 0; i < N; i++) {
      myMat[rowNum][i] = mat->myMat[newMatRowNum][i];
    }
}
  
void Matrix::sortRows(){
    Matrix* newMat = new Matrix(M,N);
    //vector<int> rowIndexes;
    
    for (int i = 0; i<M; i++) {
      int sortedRowNum = rowValues[i].first;
      newMat->SetRow(this, i, sortedRowNum);
    }
    
    myMat = newMat->myMat;
}

void PrintMatrix::printRow(int n, int xOfFirst, int yOfFirst, Matrix* m){
    int rowLength = m->N;
    
    move(xOfFirst,yOfFirst);
    for (int i = 0 ; i < rowLength; i++) {
        string s = to_string(m->myMat[n][i]);
        int l = s.length();
        char arr[l+2];
        strcpy(arr, s.c_str());
        arr[l] =' ';
        arr[l+1] = ' ';
        
        printw(arr);
        usleep(150000);
        refresh();
    }
}
void PrintMatrix::eraseRow(int xOfFirst, int yOfFirst, Matrix* m){
    move(xOfFirst,yOfFirst);
    for (int i = 0; i < m->N; i++) {
        printw("    ");
        usleep(150000);
        refresh();
    }
}
void PrintMatrix::moveRow(int xOfFirst, int yOfFirst, int xOfSecond, int yOfSecond,int n, Matrix* m){
    eraseRow(xOfFirst,yOfFirst,m);
    printRow(n, xOfSecond, yOfSecond, m);
}

  
  
