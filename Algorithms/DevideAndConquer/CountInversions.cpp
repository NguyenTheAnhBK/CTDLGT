#include<iostream>
using namespace std;

//https://codelearn.io/learningtask/index/thuat-toan-nang-cao?taskid=514641
//Test case: 
//Input:
// 20
// 82 12 38 10 15 54 51 71 95 12 1 21 90 10 89 97 42 1 84 92
// Output:
// 78

//Tay to
int n, arr[1000], temp[1000];

//O(n^2)
int CountInversions1(){
  int count = 0;
  for(int i = 0; i < n - 1; i++)
    for(int j = i + 1; j < n; j++)
      if(arr[j] < arr[i])
        count++;
  
  return count;
}
//O(nlogn)
//Ý tưởng giống merge sort: tư tưởng của bài toán này là đi đếm số lần merger của thuật toán merge sort
//giả sử, mảng l = [ai], r = [bj] mục tiêu của ta là merge l và r thì khi đó ai > bj (i luôn nhỏ hơn j vì ta tách thành thành mảng trái và mảng phải mà) ta sẽ tăng count lên là được
int Merge(int l, int m, int r){
  int i, j, k;
  int count = 0;

  //Merge 2 mảng có thứ tự thành mảng có thứ tự
  i = l, j = m + 1, k = l;
  while(i <= m && j <= r){
    if(arr[i] > arr[j]){
      temp[k++] = arr[j++];
      //Do mảng L đã có thứ tự nên khi L[i] > R[j] sẽ có tất cả (m - i + 1) cặp phần tử inversions
      count += m - i + 1;
    }
    else
      temp[k++] = arr[i++];
  } 
  //Đưa nốt phần tử còn thừa trong mảng L hoặc R
  while(i <= m)
    temp[k++] = arr[i++];
  while(j <= r)
    temp[k++] = arr[j++];

  for(i = l; i <= r; i++)
    arr[i] = temp[i];  

  return count;
}

int MergeSort(int l, int r){
  int count = 0;
  if(l < r){
    int m = (r - l)/2 + l;
    count += MergeSort(l, m);
    count += MergeSort(m + 1, r);
    count += Merge(l, m, r);
  }
  return count;
}

int CountInversions(){
  return MergeSort(0, n - 1);
}


int main(){
  cin >> n; 
  for(int i = 0; i < n; i++)
    cin >> arr[i];

  //cout << CountInversions1();
  cout << CountInversions() << endl;

  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";

  return 0;
}


//Submit
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int temp[1000];
//int Merge(std::vector<int> &arr, int l, int m, int r) {
//	int i, j, k;
//	int count = 0;
//
//	//Merge 2 mảng có thứ tự thành mảng có thứ tự
//	i = l, j = m + 1, k = l;
//	while (i <= m && j <= r) {
//		if (arr[i] > arr[j]) {
//			temp[k++] = arr[j++];
//			//Do mảng L đã có thứ tự nên khi L[i] > R[j] sẽ có tất cả (m - i + 1) cặp phần tử inversions
//			count += m - i + 1;
//		}
//		else
//			temp[k++] = arr[i++];
//	}
//	//Đưa nốt phần tử còn thừa trong mảng L hoặc R
//	while (i <= m)
//		temp[k++] = arr[i++];
//	while (j <= r)
//		temp[k++] = arr[j++];
//
//	for (i = l; i <= r; i++)
//		arr[i] = temp[i];
//
//	return count;
//}
//
//int MergeSort(std::vector<int> &arr, int l, int r) {
//	int count = 0;
//	if (l < r) {
//		int m = (r - l) / 2 + l;
//		count += MergeSort(arr, l, m);
//		count += MergeSort(arr, m + 1, r);
//		count += Merge(arr, l, m, r);
//	}
//	return count;
//}
//
//int countInversions(std::vector<int> arr) {
//	return MergeSort(arr, 0, arr.size() - 1);
//}
//
//int main() {
//	vector<int> arr = { 82,12,38,10,15,54,51,71,95,12,1,21,90,10,89,97,42,1,84,92 };
//
//	cout << countInversions(arr) << endl;
//
//	for (int i = 0; i < arr.size(); i++)
//		cout << arr[i] << " ";
//
//
//	return 0;
//}