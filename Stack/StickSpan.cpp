#include<bits/stdc++.h>
using namespace std;

//Cách tay to O(n^2)
std::vector<int> StickSpan2(vector<int> arr){
  vector<int> result;
  for(int i = 0; i < arr.size(); i++){
    int j = i, count = 0;
    while(j >= 0 && arr[j--] <= arr[i])
      count++;
    result.push_back(count);
  }
  return result;
}

//Sử dụng Stack, độ phức tạp vẫn là O(n^2) nhưng sẽ nhanh hơn một chút vì sẽ không phải tính lại các cột trước đó nữa
vector<int> StickSpan(vector<int> arr){
  vector<int> result;
  stack<int> st;
  
  st.push(0);
  result.push_back(1);
  for(int i = 1; i < arr.size(); i++){
    while(!st.empty() && arr[i] >= arr[st.top()])
      st.pop();
    result.push_back((st.empty()) ? (i + 1) : (i - st.top()));
    st.push(i);
  }
  return result;
}



int main(){
  int n, v;
  cin >> n;
  vector<int> arr;

  while(n--){
    cin >> v;
    arr.push_back(v);
  }

  vector<int> r = StickSpan(arr);

  for(int i = 0; i < r.size(); i++)
    cout << r[i] << " ";
  
  return 0;
}