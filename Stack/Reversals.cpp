#include<bits/stdc++.h>
using namespace std;

//Đếm số lần biến đổi nhỏ nhất để biểu thức ở dạng đúng
//{{{}}{}}
int Reversals(string exp){
  int len = exp.length();
  if(len&1)
    return -1;
  stack<int> st;
  for(int i = 0; i < len; i++){
    if(exp[i] == '}'){
      if(!st.empty() && st.top() == '{'){
        st.pop();
        continue;
      }
    }
    st.push(exp[i]);
  }

  //Đếm: }{{{ => cần ít nhất 3 biến đổi 
  int count = 0;
  while(!st.empty()){
    char t1 = st.top();
    st.pop();
    char t2 = st.top();
    st.pop();

    if(t1 != t2)
      count++;
    count++;
  }

  return count;
}

int main(){
  string exp;
  cin >> exp;
  
  cout << Reversals(exp);

  return 0;
}