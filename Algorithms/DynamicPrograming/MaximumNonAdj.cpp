#include<iostream>
using namespace std;

//https://codelearn.io/learningtask/index/thuat-toan-nang-cao?taskid=137472
int n, sumMax = -1e9, arr[1000005], c[1000005];
int Max(int a, int b, int c){
  int d = (a > b ? a : b);
  return d > c ? d : c;
}
//test case: 69 2 -92 69 102
int MaximumNonAdj(){
  c[0] = arr[0];
  c[1] = arr[1] > arr[0] ? arr[1] : arr[0];
  sumMax = c[1];
  for(int i = 2; i < n; i++){
    c[i] = Max(c[i - 1], c[i - 2] + arr[i], arr[i]);
    if(c[i] > sumMax)
      sumMax = c[i];
  }

  // for(int i = 0; i < n; i++)
  //   cout << c[i] << " ";
    
  return sumMax;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];

  cout << MaximumNonAdj();

  return 0;
}