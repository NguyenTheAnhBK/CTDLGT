#include<iostream>
using namespace std;

//https://codelearn.io/learningtask/index/thuat-toan-nang-cao?taskid=133665
// int n, x[6];
// bool visited[6];
// void Try(int k){
//   for(int i = 1; i <= n; i++){
//     if(!visited[i]){
//       x[k] = i;
//       visited[i] = true;
//       if(k == n)
//       {
//         for(int i = 1; i <= n; i++)
//           cout << x[i];
//         cout << endl;
//       }
//       else
//         Try(k + 1);
//       visited[i] = false;
//     }
//   }
// }

//Tìm hoán vị thứ t
int n, m, x[6], t = 0;
bool visited[6];
void Try(int k) {
	if (k == n + 1)
	{
		t++;
		if (t == m)
		{
			for (int i = 1; i <= n; i++)
				cout << x[i];
			return;
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				x[k] = i;
				visited[i] = true;
				Try(k + 1);
				visited[i] = false;
			}
		}
	}
	
}

int main() {
	cin >> n >> m;

	Try(1);
	cout << t;
	return 0;
}