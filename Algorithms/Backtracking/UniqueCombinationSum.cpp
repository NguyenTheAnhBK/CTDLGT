#include<bits/stdc++.h>
using namespace std;

//Tương tự bài Comibnation Sum nhưng lúc này tập con {a, b} và {b, a} được coi là như nhau
int arr[14], cnt = 0;
vector<int> x;

//Các phần tử được phép lặp lại
void Try1(int arr[], int l, int n, int subSum, int sum){
  if(subSum == sum){
    cnt++;
    for(int i = 0; i < x.size(); i++)
      cout << x[i] << " ";
    cout << endl;
    return;
  }
  for(int i = l; i < n; i++){
    if(subSum + arr[i] > sum)
      continue;
    
    if(i && arr[i] == arr[i - 1] && i > l)
      continue;
    
    x.push_back(arr[i]);
    Try1(arr, i, n, subSum + arr[i], sum);
    x.pop_back();
  }
}
int UniqueCombinationSum1(int arr[], int n, int sum){
  sort(arr, arr + n);
  Try1(arr, 0, n, 0, sum);

  return cnt;
}

//Unique Combination Sum
//Để xử lý tập con {a, b} và {b, a} được coi là tập con giống nhau
//Ta sẽ đi sắp xếp mảng trước, khi đó những phần tử nào giống nhau ta sẽ xét một lần thôi.
//Mỗi phần tử không được phép lặp lại
void Try2(int arr[], int l, int n, int subSum, int sum){
  if(subSum == sum)
  {
    cnt++;
    for(int i = 0; i < x.size(); i++)
      cout << x[i] << " ";
    cout << endl;
    return;
  }
  for(int i = l; i < n; i++){
    if(subSum + arr[i] > sum)
      continue;
    if(i && arr[i] == arr[i - 1] && i > l)
      continue;
    x.push_back(arr[i]);
    Try2(arr, i + 1, n, subSum + arr[i], sum);
    x.pop_back();
  }
}
int UniqueCombinationSum2(int arr[], int n, int sum){
  sort(arr, arr + n);
  Try2(arr, 0, n, 0, sum);

  return cnt;
}

int main(){
  int n, sum;
  cin >> n >> sum;
  for(int i = 0; i < n; i++)
    cin >> arr[i];

  cout << UniqueCombinationSum1(arr, n, sum);
  //cout << UniqueCombinationSum2(arr, n, sum);
  return 0;
}