#include<iostream>
#include<vector>
using namespace std;

//Combination Sum
//{a, b} và {b, a} được coi là 2 cách khác nhau
//Test case: 
//4 5
//2 2 4 3

int arr[20], n, count = 0;

//Mỗi phần tử trong mảng có thể lấy số lần tùy ý (giống bài cái túi với số lần lấy tùy ý)
void Try1(int subSum, int sum, vector<int> &x){
  if(subSum == sum){
    count++;
    for(int i = 0; i < x.size(); i++)
      cout << x[i] << " ";
    cout << endl;
    return;
  }
  for(int i = 0; i < n; i++){
    if(subSum + arr[i] > sum)
      continue;
    
    x.push_back(arr[i]);
    Try1(subSum + arr[i], sum, x);
    x.pop_back();
  }
}

//Mỗi phần tử trong mảng chỉ được lấy một lần
//Cách 1:
void Try2(int l, int subSum, int sum, vector<int> &x){
  if(subSum == sum)
  {
    count++;
    for(int i = 0; i < x.size(); i++)
      cout << x[i] << " ";
    cout << endl;
    return;
  }
  for(int i = l; i < n; i++){
    if(subSum + arr[i] > sum)
      continue;

    x.push_back(arr[i]);
    Try2(i + 1, subSum + arr[i], sum, x);
    x.pop_back();
  }
}
//Cách 2:
int subSum = 0;
void Try2(int k, int sum){
  for(int i = 0; i <= 1; i++){
    subSum += arr[k] * i;
    if(k == n - 1)
    {
      if(subSum == sum)
        count++;
      return;
    }
    else
      Try2(k + 1, sum);
    subSum -= arr[k] * i;
  }
}

int main(){
  int sum;
  cin >> n >> sum;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  
  vector<int> x;
  //Try1(0, sum, x);
  //Try2(0, 0, sum, x);
  Try2(0, sum);
  cout << count << endl;

  return 0;
}