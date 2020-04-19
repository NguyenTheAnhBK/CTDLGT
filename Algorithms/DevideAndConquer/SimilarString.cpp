#include<iostream>
#include<string>
using namespace std;

bool Try(std::string a, int la, int ra, std::string b, int lb, int rb){
  if(la <= ra && lb <= rb){
    bool isSame = true;
    
    for(int i = la, j = lb; i <= ra && j <= rb; i++, j++)
      if(a[i] != b[j])
      {
        isSame = false;
        break;
      }
    if(isSame)
      return true;
      
    if(((ra - la) & 1) && ((rb - lb) & 1))
    {
      int ma = (la + ra)/2, mb = (lb + rb)/2;
      return (Try(a, la, ma, b, lb, mb) && Try(a, ma + 1, ra, b, mb + 1, rb)) 
      || (Try(a, la, ma, b, mb + 1, rb) && Try(a, ma + 1, ra, b, lb, mb));
    }
  }
  return false;
}

bool SimilarStrings(std::string a, std::string b)
{
  int la = a.length() - 1, lb = b.length() - 1;
  return Try(a, 0, la, b, 0, lb);
}

int main(){
  string a, b;
  cin >> a >> b;

  cout << SimilarStrings(a, b);

  return 0;
}