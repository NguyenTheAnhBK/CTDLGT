#include<bits/stdc++.h>
using namespace std;

//https://codelearn.io/learningtask/index/thu-vien-chuan-cpp?taskid=49012
//Xóa lần lượt từng phần tử của mảng sao cho arr[i] < arr[i + 1] thì được phép xóa arr[i]
vector<int> RemoveElements(vector<int> arr, int k) {
	stack<int> st;
	vector<int> result;
	int size = arr.size();
	for (int i = 0; i < size - 1; i++) {
		st.push(arr[i]);

		while (!st.empty() && st.top() < arr[i + 1] && k) {
			st.pop();
			k--;
		}
	}
	st.push(arr[size - 1]);
	stack<int> st2;
	while (!st.empty())
	{
		st2.push(st.top());
		st.pop();
	}
	while (!st2.empty())
	{
		result.push_back(st2.top());
		st2.pop();
	}

	return result;
}

int main() {
	int n, v, k;
	cin >> n >> k;
	vector<int> arr;
	while (n--) {
		cin >> v;
		arr.push_back(v);
	}

	vector<int> r = RemoveElements(arr, k);

	for (int i = 0; i < r.size(); i++)
		cout << r[i] << " ";

	return 0;
}