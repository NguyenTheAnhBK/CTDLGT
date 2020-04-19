#include<iostream>
using namespace std;

//https://codelearn.io/learningtask/index/thu-vien-chuan-cpp?taskid=46633
//Cho số nguyên dương n, hãy viết hàm trả về số nhị phân từ 1 đến n
string queue[1000];
int back = -1, last = 0;
void EnQueue(string v){
  queue[++back] = v;
}
string DeQueue(){
  return queue[last++];
}
bool IsEmpty(){
  return last > back;
}

void GenerateBinary(int n){
  EnQueue("1");
  while(!IsEmpty() && n--){
    string v = DeQueue();
    cout << v << " ";
    for(int i = 0; i <= 1; i++)
      EnQueue(v + char(i + 48));
  }
}

int main(){
  int n;
  cin >> n;

  GenerateBinary(n);

  return 0;
}