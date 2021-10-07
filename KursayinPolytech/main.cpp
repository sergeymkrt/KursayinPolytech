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
#if defined(__APPLE__) && defined(__MACH__)
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

using namespace std;

int main(int argc, const char * argv[]) {
  
  system("clear");
  cout<< "Hello, enter N and M :)";
  int m,n;
  cin>>m>>n;
  cout<<"Thanks , here is your matrix :)"<<endl;
  
  //creating, generating and printing the Matrix
  Matrix* myMat = new Matrix(m,n);
  
  myMat->printMatrix();
  
  cout<<"Want to sort every line of matrix? type: Y,N"<<endl;
  string choice = "";
  bool ok = true;
  
  //Sorting matrix ( or not )
  while(ok){
    cin >> choice;
    
    if(choice == "Y" || choice == "y"){
      
      cout<< " Okay , here is the sorted matrix"<<endl;
      myMat->sortMatrix();
      myMat->printMatrix();
      ok = false;
      
    }
    else if (choice == "N" || choice == "n"){
      
      cout<<"Ok";
      ok = false;
    }
    else{
      cout<<"Error.. try again please"<<endl;
    }
  }
  
  cout<<"And here is the sorted matrix with rows sorted \n"<<endl;
  
  myMat->sortRowValues();
  myMat->printSumMap();
  
  cout<<endl;
  cout<<"Here is the sorted matrix"<<endl;
  
  
  myMat->sortRows();
  myMat->printMatrix();
  
  
  cout<<endl;
  return 0;
}

