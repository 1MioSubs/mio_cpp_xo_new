#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

int arrBoard[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
int gamerOrPcGame = 0, num_pc_game = 0, visual_game = 1;
string cinText = "";
int cinTextInt = 0;
string name_one = "", name_two = "";
int pc_one_level = 0, pc_two_level = 0, pc_main_level = 0;

void board ();
void testVin ();
void gamerOrPc ();
void nameGamerAndPc();
void selPcLevel();
void setNumGame();

int main () {
	setlocale(LC_ALL, "RU");
	srand(time(0));

	//stoi(cinText);
	
	//gamerOrPc();

	//cout << "Hello World" << endl;

	return 0;
}

void board () {
	system("CLS");
	if (gamerOrPcGame == 1) {
		cout << name_one << " - Против - " << name_two << endl;
	}
	else if (gamerOrPcGame == 2) {
		cout << name_one << " - Против - " << name_two << " - Сложность - " << pc_main_level << endl;
	}
	else if (gamerOrPcGame == 3) {
		cout << name_one << " - МОШЬ - "; 
		cout << pc_one_level << " - Против - ";
		cout << name_two << " - МОШЬ - ";
		cout << pc_two_level << " - Осталось игр - ";
		cout << num_pc_game << endl;
	}
	if (visual_game == 1) {
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
	}
	testVin();
}

void testVin () {
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

void gamerOrPc () {
	system("CLS");
	cout << "1 --- (gamer and gamer)\n2 --- (game and pc)\n3 --- (pc and pc)" << endl;
	cout << "Выберите вариант: ";
	cin >> cinTextInt;
	if (cinTextInt == 1 || cinTextInt == 2 || cinTextInt == 3) {
		nameGamerAndPc();
	}
	else {
		gamerOrPc();
	}
}

void nameGamerAndPc () {
	if (gamerOrPcGame == 1) {
		cout << "name gamer 1 --- ";
		cin >> name_one;
		cout << "name gamer 2 --- ";
		cin >> name_two;
		cout << name_one << " - Против - " << name_two << endl;
		visual_game = 1;
		board();
	}
	else if (gamerOrPcGame == 2) {
		cout << "name gamer 1 --- ";
		cin >> name_one;
		name_two = "PC";
		cout << name_one << " - Против - " << name_two << endl;
		visual_game = 1;
		selPcLevel();
	}
	else if (gamerOrPcGame == 3) {
		name_one = "PC-1";
		name_two = "PC-2";
		cout << name_one << " - Против - " << name_two << endl;
		visual_game = 1;
		selPcLevel();
	}
}

void selPcLevel () {
	if (gamerOrPcGame == 2) {
		cout << "Выбирете уровень сожности от 1 до 3: ";
		cin >> cinTextInt;
		if (cinTextInt == 1 || cinTextInt == 2 || cinTextInt == 3) {
			cout << "Уровень - " << name_two << " - " << pc_main_level << endl;
			board();
		}
		else {
			selPcLevel();
		}
	}
	else if (gamerOrPcGame == 3) {
		cout << "Выбирете уровень сожности PC-1 от 1 до 3: ";
		cin >> cinTextInt;
		if (cinTextInt == 1 || cinTextInt == 2 || cinTextInt == 3) {
			cout << "Уровень - " << name_one << " - " << pc_one_level << endl;
		}
		else {
			selPcLevel();
		}

		cout << "Выбирете уровень сожности PC-2 от 1 до 3: ";
		cin >> cinTextInt;
		if (cinTextInt == 1 || cinTextInt == 2 || cinTextInt == 3) {
			cout << "Уровень - " << name_two << " - " << pc_two_level << endl;
		}
		else {
			selPcLevel();
		}
	}
}

void setNumGame () {
	if (gamerOrPcGame == 2) {
		cout << "Введите количество игр для пк/пк(Целое число): ";
		cin >> cinTextInt;
		if (!cin.fail()) {
			cout << "Введено целое число: " << cinTextInt << endl;
			num_pc_game = cinTextInt;
			visual_game = 0;
			board();
		}
		else {
			cout << "Введена кракозябра" << endl;
			setNumGame();
		}

	}
}