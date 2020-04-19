#include<bits/stdc++.h>
using namespace std;

//Xét theo giá trị đồ chơi tăng dần
int NumberOfToys(vector<int> arr, int k){
  //Sắp xếp giá trị đồ chơi tăng dần
  for(int i = 0; i < arr.size() - 1; i++){
    int index = i;
    for(int j = i + 1; j < arr.size(); j++)
      if(arr[j] < arr[index])
        index = j;
      
    swap(arr[index], arr[i]);
  }

  int i = 0;
  while(k >= 0){
    k -= arr[i++];
  }
  return i - 1;
}

int main(){
  int n, k, v;
  cin >> n >> k;

  vector<int> arr;
  for(int i = 0; i < n; i++){
    cin >> v;
    arr.push_back(v);
  }

  cout << NumberOfToys(arr, k);
  
  return 0;
}