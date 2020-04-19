#include<iostream>
using namespace std;

//https://codelearn.io/learningtask/index/thuat-toan-nang-cao?taskid=137451
// f(n) = f(n-1) * f(n-2) + f(n-3) với f(1) = 1, f(2) = 1, f(3) = 2

//Recursion
int FibLikeSeqRecursion(int n){
  if(n == 3)
    return 2;
  if(n <= 2)
    return 1;
  return FibLikeSeqRecursion(n - 1) * FibLikeSeqRecursion(n - 2) + FibLikeSeqRecursion(n - 3);
}

int f[1000];
int FibLikeSeq(int n){
  f[1] = f[2] = 1, f[3] = 2;
  for(int i = 4; i <= n; i++)
    f[i] = f[i - 1] * f[i - 2] + f[i - 3];
  return f[n];
}

int OptimizeFibLikeSeq(int n){
  if(n <= 2)
    return 1;
  if(n == 3)
    return 2;
  int f, f1 = 1, f2 = 1, f3 = 2;
  long long inf = 1e9 + 7;
  for(int i = 4; i <= n; i++){
    f = ((((f3 % inf) * (f2 % inf)) % inf) + f1 % inf) % inf;
    f1 = f2;
    f2 = f3;
    f3 = f;
  }
  return f;
}


int main(){
  int n;
  cin >> n;

  // cout << FibLikeSeqRecursion(n);
  // cout << endl;
  // cout << FibLikeSeq(n);
  // cout << endl;
  cout << OptimizeFibLikeSeq(n);

  return 0;
}