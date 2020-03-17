#include<iostream>
using namespace std;

int stack[100];
int top = -1;

void Push(int elem){
  stack[++top] = elem;
}
int Pop(){
  return stack[top--];
}
bool IsEmpty(){
  return top==-1;
}

void Convert(int dicimal, int base){
  cout << dicimal << "(10): ";
  do{
    Push(dicimal % base);
    dicimal /= base;
  }while(dicimal);
  
  while(!IsEmpty()){
    int elem = Pop();
    if(elem < 10)
      cout << elem;
    else
      cout << char(elem + 55);
  }
  cout << "(" << base << ")" << endl;
}

int main(){
  Convert(25, 2);
}