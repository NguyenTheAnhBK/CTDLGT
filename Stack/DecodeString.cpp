#include<bits/stdc++.h>
using namespace std;

//https://codelearn.io/learningtask/index/thu-vien-chuan-cpp?taskid=49009

string DecodeString(string s){
  stack<char> st;
  string out = "";
  for(int i = 0; i < s.length(); i++){
    if(s[i] == ']'){
      while(!st.empty() && st.top() != '['){
        out = st.top() + out;
        st.pop();
      }
      st.pop();
      int n = st.top() - '0' - 1;
      string temp = out;
      while(n--)
        out += temp;
      st.pop();
    }
    else
      st.push(s[i]);
  }

  return out;
}

int main(){
  string s;
  cin >> s;

  cout << DecodeString(s);

  return 0;
}