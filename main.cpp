#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

int arrBoard[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
int gamerOrPcGame;
string cinText;

void board();
void testVin();
void gamerOrPc();

int main () {
	setlocale(LC_ALL, "RU");
	srand(time(0));

	gamerOrPc();

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

void gamerOrPc() {
	system("CLS");
	cout << "1 --- (gamer and gamer)\n2 --- (game and pc)\n3 --- (pc and pc)" << endl;
	cout << "Выберите вариант: ";
	cin >> cinText;
	if (cinText == "1" || cinText == "2" || cinText == "3") {
		gamerOrPcGame = stoi(cinText);
	}
	else {
		gamerOrPc();
	}
}