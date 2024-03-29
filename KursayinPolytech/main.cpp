//
//  main.cpp
//  KursayinPolytech
//
//  Created by Sergey Mkrtumyan on 01.10.21.
//

#include <iostream>
#include <ctime>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "Matrix.hpp"
#include <curses.h>
#include <unistd.h>

using namespace std;

int main(int argc, const char * argv[]) {
  
  system("clear");
  
  
  cout<< "Hello, enter N and M :)";
  int m,n;
  cin>>m>>n;
  system("clear");
  cout<<"Thanks , here is your matrix :)"<<endl;
  
  //creating, generating and printing the Matrix
  Matrix* myMat = new Matrix(m,n);
  
  myMat->printMatrix();
  
  
  cout<<"Want to sort every line of matrix? type: Y,N"<<endl;
  string choice1 = "";
  bool ok1 = true;
  
  //Sorting matrix ( or not )
  while(ok1){
    cin >> choice1;
    
    if(choice1 == "Y" || choice1 == "y"){
      
      cout<< " Okay , here is the sorted matrix"<<endl;
      myMat->sortMatrix();
      myMat->printMatrix();
      ok1 = false;
      
    }
    else if (choice1 == "N" || choice1 == "n"){
      
      cout<<"Ok";
      ok1 = false;
    }
    else{
      cout<<"Error.. try again please"<<endl;
    }
  }
  
  cout<<"And here is the sorted matrix with rows sorted \n"<<endl;
  
  vector<pair<int,int>> notSortedRowValues = myMat->rowValues;
  
  myMat->sortRowValues();
  myMat->printSumMap();

 
  
  cout<<"Are you ready to enter the graphics mode? y/n"<<endl;
  string ready;
  cin>>ready;
  
  if (ready == "y" || ready == "Y") {
    //Entering the graphics mode
    initscr();
    
    int row,col;
    getmaxyx(stdscr, row, col);
    int firstRow,firstCol;
    firstRow = 2;
    int rowLength = myMat->N*3;
    firstCol = (col/2)-rowLength-10;
    
    PrintMatrix mat;
    
    //Printing the matrix
    for (int i = 0; i < myMat->N; i++) {
      mat.printRow(i, firstRow, firstCol, myMat);
      firstRow++;
    }
    
    firstRow = 2;
    
    
    int num = 0;
    for (int i = 0; i < myMat->N; i++) {
      int indexOfRow = myMat->rowValues[i].first;
      if(indexOfRow == notSortedRowValues[i].first){
        continue;
      }
      
      int index;
      for (int k = 0; k < notSortedRowValues.size(); k++) {
        if(indexOfRow == notSortedRowValues[k].first){
          index = k;
          break;
        }
      }
      
      mat.moveRow(firstRow + index,firstCol, firstRow + index, firstCol + n*4, indexOfRow, myMat);
      
      int tempIndex = notSortedRowValues[indexOfRow].first;
      pair<int,int> row = notSortedRowValues[index];
      
      mat.getMatrixLow(firstRow,firstCol, indexOfRow, i,index,notSortedRowValues, myMat);
      
      mat.moveRow(firstRow + index , firstCol + n*4,firstRow+i,firstCol,indexOfRow,myMat);
      
      
      
      notSortedRowValues.erase(notSortedRowValues.begin() + index);
      notSortedRowValues.insert(notSortedRowValues.begin()+ i,row);     
    }
    
  }
  else{
    cout<<"Okay :)";
  }
  
  getch();
  endwin();
  
  cout<<"Thank you for using me :)"<<endl;
  return 0;
}

