#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <vector>
#include <ctime>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::endl;
using std::reverse;

int faslfjlks(){
	cout << "аоывлдав";
}

int numCheck(int num) { 
	while (cin.fail() || num < 0) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка вводе данных. Попробуйте снова: ";
		cin >> num;
	}
	return num;
}

int maxIterations(vector<vector<int>>& colors, int i, int j) {
	if (colors[i][j] == 0) {
		return 0;
	}
	int count = 1;
	int colsLength = colors[0].size();
	int rowLength = colors.size();

	if (i - 1 >= 0 && colors[i][j] == colors[i - 1][j]) {
		colors[i][j] = 0;
		count += maxIterations(colors, i - 1, j);
	}
	if (i + 1 < rowLength && colors[i][j] == colors[i + 1][j]) {
		colors[i][j] = 0;
		count += maxIterations(colors, i + 1, j);
	}
	if (j + 1 < colsLength && colors[i][j] == colors[i][j + 1]) {
		colors[i][j] = 0;
		count += maxIterations(colors, i, j + 1);
	}
	if (j - 1 >= 0 && colors[i][j] == colors[i][j - 1]) {
		colors[i][j] = 0;
		count += maxIterations(colors, i, j - 1);
	}
	return count;
}

int main()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int rows = 0;
	int cols = 0;
	int countColors = 7;
	time_t time(time_t * timer);
	srand(time(NULL));

	vector <int> iterations;
	for (int i = 0; i < 7; i++) {
		iterations.push_back(0);
	}

	cout << "Введите количество строк: ";
	cin >> rows;
	rows = numCheck(rows);

	cout << "Введите количество столбцов: ";
	cin >> cols;
	cols = numCheck(cols);

	vector <vector<int>> matrix;

	for (int i = 0; i < rows; i++) {
		vector <int> row;
		for (int j = 0; j < cols; j++) {
			row.push_back(rand()%7+1);
		}
		matrix.push_back(row);
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j];
			cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] == 0) {
				continue;
			}
			int v = matrix[i][j];
			int z = maxIterations(matrix, i, j);
			if (iterations[v - 1] < z) {
				iterations[v - 1] = z;
			}
		}
	}

	vector <int> reverseVector;
	reverseVector = iterations;
	sort(reverseVector.begin(), reverseVector.end());
	reverse(reverseVector.begin(), reverseVector.end());

	for (int i = 0; i < iterations.size(); i++) {
		if (reverseVector[0] == iterations[i]) {
			cout << "Число с наибольшим совпадением: " << i + 1 << ". Число совпадений: " << reverseVector[0] << endl;
		}
	}

	system("pause");
	return 0;
}