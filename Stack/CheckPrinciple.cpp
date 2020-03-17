#include <iostream>
using namespace std;

char stack[100];
int top = -1;

void Push(char elem){
  stack[++top] = elem;
}
char Pop(){
  return stack[top--];
}
bool IsEmpty(){
  return top == -1;
}

bool CheckPrinciple(char* input){
  for(int i = 0; char c = input[i]; i++){
    switch(c){
      case '{':
      case '(':
      case '[':
        Push(c); break;
      
      case ']':
      case ')':
      case '}':
        if(IsEmpty())
          return false;
        char t = Pop();
        if(c == ']' & t != '[' 
          || c == ')' & t != '(' 
          || c == '}' & t != '{')
          return false;
        break;
    }
  }
  return true;
}

int main(){
  char input[] = "int main() { cout << 'a' << endl; }";
  cout << (CheckPrinciple(input) ? "Yes" : "No");

  return 0;
}