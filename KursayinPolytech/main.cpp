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
#if defined(__APPLE__) && defined(__MACH__)
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

using namespace std;

bool sortByVal(const pair<int, int> &a,
               const pair<int, int> &b)
{
  return (a.second > b.second);
}

class Matrix {
public:
  int** myMat;
  int M,N;
  //map<int,int> rowValues;
  vector<pair<int,int>> rowValues;
  Matrix(int m,int n){
    
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
        myMat[i][j] = (rand() % 70)+1;
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
  void printMatrix(){
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        cout<<myMat[i][j] << " ";
      }
      cout << endl;
    }
  }
  void printSumMap(){
    for (int i = 0; i < rowValues.size(); i++)
    {
      cout << rowValues[i].first << ": " << rowValues[i].second << endl;
    }
  }
  
  void sortRowValues(){
    sort(rowValues.begin(),rowValues.end(),sortByVal);
  }
  
  void sortMatrix(){
    for (int i = 0 ; i < M; i++) {
      sort(myMat[i],myMat[i] + N, greater<int>());
    }
  }
  
  int SumOfRow(int n){
    int sum = 0;
    for (int i = 0; i<M; i++) {
      sum += myMat[n][i];
    }
    return sum;
  }
  
  
  void SetRow(Matrix* mat, int rowNum, int newMatRowNum){
    for (int i = 0; i < N; i++) {
      myMat[rowNum][i] = mat->myMat[newMatRowNum][i];
    }
  }
  
  
  //TODO
  void sortRows(){
    Matrix* newMat = new Matrix(M,N);
    //vector<int> rowIndexes;
    
    for (int i = 0; i<M; i++) {
      int sortedRowNum = rowValues[i].first;
      newMat->SetRow(this, i, sortedRowNum);
    }
    
    myMat = newMat->myMat;
  }
};






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
  //    cout << "Hello, World!\n"<<endl;
  return 0;
}

