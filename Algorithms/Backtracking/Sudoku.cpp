#include <bits/stdc++.h>
using namespace std;

//Sudoku
//testcase:
// 000000070
// 000000080
// 000000000
// 100000000
// 002000000
// 000000000
// 000000000
// 050000000
// 000000006

bool Feasible(std::vector<std::string> matrix, int r, int c, int k) {
	if (matrix[r][c] != '0')
		return false;

	for (int i = 0; i < 9; i++)
		if (matrix[i][c] == k + '0')
			return false;

	for (int j = 0; j < 9; j++)
		if (matrix[r][j] == k + '0')
			return false;

	int dr = (r / 3) * 3, dc = (c / 3) * 3;
	for (int i = dr; i < dr + 3; i++)
		for (int j = dc; j < dc + 3; j++)
			if (matrix[i][j] == k + '0')
				return false;

	return true;
}
bool Fill(std::vector<std::string> matrix, int &r, int &c) {
	for (r = 0; r < 9; r++) {
		for (c = 0; c < 9; c++)
			if (matrix[r][c] == '0')
				return false;
	}
	return true;
}
bool Try(std::vector<std::string> &matrix) {
	int r, c;
	if (Fill(matrix, r, c))
		return true;
	for (int k = 1; k <= 9; k++) {
		if (Feasible(matrix, r, c, k)) {
			matrix[r][c] = char(k + '0');
			if (Try(matrix))
				return true;
			matrix[r][c] = '0';
		}
	}
	return false;
}
std::vector<std::string> sudokuSolve(std::vector<std::string> matrix)
{
	Try(matrix);
	return matrix;
}

int main() {
	vector<string> matrix(9);
	for (int i = 0; i < 9; i++)
		cin >> matrix[i];

	vector<string> res = sudokuSolve(matrix);

	for (int i = 0; i < 9; i++)
		cout << res[i] << endl;


	return 0;
}