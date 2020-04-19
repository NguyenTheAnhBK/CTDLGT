#include<bits/stdc++.h>
using namespace std;

//Encode string
//Mã hóa theo số lần xuất hiện một ký tự liên tiếp trong chuỗi

string EncodeString(string s){
  stack<char> st;
  string result;
  st.push(s[0]);
  s += '@';
  for(int i = 1; i < s.length(); i++){
    if(s[i] != st.top()){
      result += st.top();
      result += char(st.size() + '0');
      while(!st.empty())
        st.pop();
    }
    st.push(s[i]);
  }
  return result;
}

int main(){
  string s;
  cin >> s;

  cout << EncodeString(s);

  return 0;
}