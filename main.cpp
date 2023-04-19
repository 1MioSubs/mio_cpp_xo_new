#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

int arrBoard[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

void board();
void testVin();

int main () {
	srand(time(0));

	board();

	//cout << "Hello World" << endl;

	return 0;
}

void board() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) cout << '\t';

			if (arrBoard[i][j] == 96) cout << 'X';
			else if (arrBoard[i][j] == 00) cout << 'O';
			else cout << arrBoard[i][j];

			if (j == 2) cout << endl;
			else if (j != 2) cout << '-';
		}
	}
	testVin();
}

void testVin() {
	if (
		arrBoard[0][0] == 96 && arrBoard[1][1] == 96 && arrBoard[2][2] == 96 ||
		arrBoard[0][2] == 96 && arrBoard[1][1] == 96 && arrBoard[2][0] == 96 ||
		arrBoard[0][0] == 96 && arrBoard[0][1] == 96 && arrBoard[0][2] == 96 ||
		arrBoard[1][0] == 96 && arrBoard[1][1] == 96 && arrBoard[1][2] == 96 ||
		arrBoard[2][0] == 96 && arrBoard[2][1] == 96 && arrBoard[2][2] == 96 ||
		arrBoard[0][0] == 96 && arrBoard[1][0] == 96 && arrBoard[2][0] == 96 ||
		arrBoard[0][1] == 96 && arrBoard[1][1] == 96 && arrBoard[2][1] == 96 ||
		arrBoard[0][2] == 96 && arrBoard[1][2] == 96 && arrBoard[2][2] == 96
		)
	{
		cout << 'X';
	}
	else if (
		arrBoard[0][0] == 00 && arrBoard[1][1] == 00 && arrBoard[2][2] == 00 ||
		arrBoard[0][2] == 00 && arrBoard[1][1] == 00 && arrBoard[2][0] == 00 ||
		arrBoard[0][0] == 00 && arrBoard[0][1] == 00 && arrBoard[0][2] == 00 ||
		arrBoard[1][0] == 00 && arrBoard[1][1] == 00 && arrBoard[1][2] == 00 ||
		arrBoard[2][0] == 00 && arrBoard[2][1] == 00 && arrBoard[2][2] == 00 ||
		arrBoard[0][0] == 00 && arrBoard[1][0] == 00 && arrBoard[2][0] == 00 ||
		arrBoard[0][1] == 00 && arrBoard[1][1] == 00 && arrBoard[2][1] == 00 ||
		arrBoard[0][2] == 00 && arrBoard[1][2] == 00 && arrBoard[2][2] == 00
		)
	{
		cout << 'O';
	}
}

