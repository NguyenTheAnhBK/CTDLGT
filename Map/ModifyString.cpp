#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

//https://codelearn.io/learningtask/index/thu-vien-chuan-cpp?taskid=46614

//Sử dụng mảng thì khó sắp xếp
int c[128], o[128];
void ModifyString1(string s){
  for(int i = 0; i < s.length(); i++)
  {
    c[int(s[i])]++;
    o[int(s[i])] = (int)s[i];
  }

  //Sắp xếp
  int index;
  for(int i = 32; i < 127; i++){
    index = i;
    for(int j = i + 1; j < 128; j++)
      if(c[j] > c[index])
        index = j;

    swap(c[i], c[index]);
    swap(o[i], o[index]);
  }
  
  int i = 32;
  while(o[i])
    cout << char(o[i++]);
}

//Sử dụng map
map<char, int> mp;
void ModifyString2(string s){
  for(int i = 0; i < s.length(); i++)
    mp[s[i]]++;
  
  vector<pair<char, int>> v(mp.begin(), mp.end());
  int index;
  for(int i = 0; i < v.size(); i++){
    index = i;
    for(int j = i + 1; j < v.size(); j++)
      if(v[j].second > v[index].second 
        || (v[j].second == v[index].second && v[j].first < v[index].first))
        index = j;
    swap(v[i], v[index]);
  }

  for(int i = 0; i < v.size(); i++)
    cout << v[i].first;
} 

int main(){
  string s;
  cin >> s;

  ModifyString1(s);
  cout << endl;
  ModifyString2(s);

  return 0;
}