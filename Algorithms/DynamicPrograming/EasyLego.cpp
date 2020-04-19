#include<iostream>
using namespace std;

//https://codelearn.io/learningtask/index/thuat-toan-nang-cao?taskid=137914
//Số cách chọn để có hình có kích thước n x m từ {1x1, 1x2, 1x3, 1x4} (chỉ xếp theo chiều ngang) = (số cách chọn để xếp được hình 1xm) ^ n 
//VD: số cách chọn hình 2x3 = (số cách chọn hình có kích thước 1 x 3) ^ 2 = 4^2 = 16
//Như vậy bài toán đơn giản chỉ là bài toán tìm tổng con trong mảng {1, 2, 3, 4} sao cho bằng m, bài này đã làm rất chi tiết trong bài CombinationSum phần Backtracking hoặc bài Cashier trong phần thuật toán tham lam Greedy
//Ta sẽ đi giải bài này theo quy hoạch động, lưu ý: được phép lấy 3 mảnh 1x1 để tạo thành hình 1x3
//{1 mảnh 1x1, 1 mảnh 1x2} và {1 mảnh 1x2, 1 mảnh 1x1} được coi là hai cách chọn khác nhau

//Ta có công thức quy hoạch động như sau: C[k] = C[k - ai] + 1 với 
//ai = {1, 2, 3, 4}

int a[] = {1, 2, 3, 4}, C[100005];
int EasyLego(int n, int m){
  C[0] = 1;
  C[1] = 1;
  C[2] = 2;
  C[3] = 4;
  C[4] = 8;
  C[5] = 15;
  for(int i = 2; i <= m; i++){
    
  }
}

int main(){
  return 0;
}