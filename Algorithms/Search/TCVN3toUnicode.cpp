#include <iostream>
#include <string>
using namespace std;

//Chuyển đổi font TCVN3 sang font Unicode
//TCVN3 là bảng mã theo chuẩn cũ của Việt Nam, sử dụng 1 byte để mã hóa ký tự do đó số ký tự hạn chế. Một điểm hạn chế nữa của TCVN3 là khi gửi văn bản viết bằng TCVN3 sang máy khác không cài đặt font này thì không thể đọc được văn bản đó.
//Unicode là bảng mã chung của thế gới sử dụng 2 bytes để mã hóa và khắc phục được hạn chế của TCVN3.

//Tạo 2 bảng mã
int UNICODE[135] = { 193, 195, 7840, 7842, 200, 201, 7864, 7866, 7868, 204, 205, 296, 7880, 7882, 210, 211, 213, 7884, 7886, 217, 218, 360, 7908, 7910, 221, 7922, 7924, 7926, 7928, 258, 7854, 7856, 7858, 7860, 7862, 194, 7844, 7846, 7848, 7850, 7852, 202, 7870, 7872, 7874, 7876, 7878, 212, 7888, 7890, 7892, 7894, 7896, 416, 7898, 7900, 7902, 7904, 7906, 431, 7912, 7914, 7916, 7918, 7920, 272, 259, 226, 234, 244, 417, 432, 273, 224, 7843, 227, 225, 7841, 7857, 7859, 7861, 7855, 7863, 7847, 7849, 7851, 7845, 7853, 232, 7867, 7869, 233, 7865, 7873, 7875, 7877, 7871, 7879, 236, 7881, 297, 237, 7883, 242, 7887, 245, 243, 7885, 7891, 7893, 7895, 7889, 7897, 7901, 7903, 7905, 7899, 7907, 249, 7911, 361, 250, 7909, 7915, 7917, 7919, 7913, 7921, 7923, 7927, 7929, 253, 7925 };

int TCVN3[135] = {
  65, 65, 65, 65, 69, 69, 69, 69, 69, 73, 73, 73, 73, 73, 79, 79, 79, 79, 79, 85, 85, 85, 85, 85, 89, 89, 89, 89, 89, 161, 161, 161, 161, 161, 161, 162, 162, 162, 162, 162, 162, 163, 163, 163, 163, 163, 163, 164, 164, 164, 164, 164, 164, 165, 165, 165, 165, 165, 165, 166, 166, 166, 166, 166, 166, 167, 168, 169, 170, 171, 172, 173, 174, 181, 182, 183, 184, 185, 187, 188, 189, 190, 198, 199, 200, 201, 202, 203, 204, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 220, 221, 222, 223, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254 };

//Tìm kiếm vị trí ký tự a trên mảng TCVN3 => ký tự chuyển sang UNICODE dựa vào mảng UNICODe
//Do mảng TCVN3 đã được sắp xếp nên ta có thể áp dụng giải thuật tìm kiếm nhị phân O(logn)
int index, tcvn3Len;
int FindRecursion(int code, int l, int r) {
	int m = (l + r) / 2;
	if (l <= r) {
		if (TCVN3[m] == code)
			return m;
		if (TCVN3[m] < code)
			return FindRecursion(code, l, m - 1);
		if (TCVN3[m] > code)
			return FindRecursion(code, m + 1, r);
	}
	return -1;
}
int Find(int code, int l, int r) {
	while (l <= r) {
		int m = (l + r) / 2;
		if (TCVN3[m] == code)
			return m;
		if (TCVN3[m] < code)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}

//O(nlogn)
string Convert(string text) {
	int index, len = text.length();
	string uniText = text;
	for (int i = 0; i < len; i++) {
		index = Find(text[i], i, 134);
		if (index != -1)
			uniText[i] = wchar_t(UNICODE[index]);
	}
	return uniText;
}

int main() {
  std::setlocale(LC_ALL, "vi_VN.utf8"); // or "en_US.utf8", or any other .utf8
  std::mbstate_t state = std::mbstate_t(); // initial state
	string text;
	getline(cin, text);
  
  //cout << text;
	cout << endl;

	cout << Convert(text);

	return 0;
}