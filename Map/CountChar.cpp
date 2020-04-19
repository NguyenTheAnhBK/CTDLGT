#include<iostream>
#include<map>
#include<string>
using namespace std;

//Sử dụng mảng
int c[128];
void CountChar1(string s){
  for(int i = 0; i < s.length(); i++)
    c[s[i]]++;
  
  for(int i = 97; i < 124; i++)
    if(c[i])
      cout << char(i) << "-" << c[i] << " "; 
}

//Sử dụng Map
map<char, int> mp;
void CountChar2(string s){
  for(int i = 0; i < s.length(); i++)
    mp[s[i]]++;
  
  for(auto i = mp.begin(); i != mp.end(); i++)
    cout << i->first << "-" << i->second << " ";
}

int main(){
  string s;
  cin >> s;

  CountChar1(s);
  cout << endl;
  CountChar2(s);
  return 0;
}