#include<iostream>
using namespace std;

//Backtracking
int arr[17], n;
int sum = 0, subSum = 0, maxMul = -1e9, g = 0;
void Try(int k){
  for(int i = 0; i <= 1; i++){
    subSum += arr[k] * i;
    g += i;

    if(k == n - 1){
      if(g && g != n && subSum * (sum - subSum) > maxMul)
        maxMul = subSum * (sum - subSum);
    }
    else{
      Try(k + 1);
    }
      
    g -= i;
    subSum -= arr[k] * i;
  }
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    sum += arr[i];
  }

  Try(0);
  cout << maxMul;

  return 0;
}