#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

int arrBoard[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
int gamerOrPcGame = 0, num_pc_game = 0, visual_game = 1;
string cinText = "";
int cinTextInt = 0, cinConvertToInt = 0;
string name_one = "", name_two = "";
int pc_one_level = 0, pc_two_level = 0, pc_main_level = 0;
int len_game = 0, game_play = 1;
int x = 1, o = 2;

void board ();
void testVin ();
void gamerOrPc ();
void nameGamerAndPc();
void selPcLevel();
void setNumGame();
void setVisualBoard();
void setStep(int, int);
void setGamerStep(int, int);
void gamerStep();
void pcStep();
void endGame(int);
void testBreak();

int main () {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	
	gamerOrPc();

	//cout << "Hello World" << endl;

	return 0;
}

void board () {
//	system("CLS");
	len_game++;
	if (gamerOrPcGame == 1) {
		cout << name_one << " - ������ - ";
		cout << name_two << " - ���� ����� - ";
		cout << game_play << " - ��� ����� - ";
		cout << len_game << endl;
	}
	else if (gamerOrPcGame == 2) {
		cout << name_one << " - ������ - ";
		cout << name_two << " - ��������� - ";
		cout << pc_main_level << " - ���� ����� - ";
		cout << game_play << " - ��� ����� - ";
		cout << len_game << endl;
	}
	else if (gamerOrPcGame == 3) {
		cout << name_one << " - ���� - "; 
		cout << pc_one_level << " - ������ - ";
		cout << name_two << " - ���� - ";
		cout << pc_two_level << " - �������� ��� - ";
		cout << num_pc_game << " - ���� ����� - ";
		cout << game_play << " - ��� ����� - ";
		cout << len_game << endl;
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
		endGame(x);
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
		endGame(o);
	} 
	else if (len_game > 9) {
		endGame(3);	
	}
	else {
		cout << "���������� ���� ������ � �������� ��� ���" << endl;
		gamerStep();	
	}
}

void gamerOrPc () {
	system("CLS");
	cout << "1 --- (gamer and gamer)\n2 --- (game and pc)\n3 --- (pc and pc)" << endl;
	cout << "�������� �������: " << endl;
	cin >> cinText;
	if (cinText == "1" || cinText == "2" || cinText == "3") {
		gamerOrPcGame = 1;//stoi(cinText);
		nameGamerAndPc();
		//cout << gamerOrPcGame;
		//gamerOrPc();
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
		//cout << name_one << " - ������ - " << name_two << endl;
		visual_game = 1;
		board();
	}
	else if (gamerOrPcGame == 2) {
		cout << "name gamer 1 --- ";
		cin >> name_one;
		name_two = "PC";
		//cout << name_one << " - ������ - " << name_two << endl;
		visual_game = 1;
		selPcLevel();
	}
	else if (gamerOrPcGame == 3) {
		name_one = "PC-1";
		name_two = "PC-2";
		//cout << name_one << " - ������ - " << name_two << endl;
		visual_game = 1;
		selPcLevel();
	}
}

void selPcLevel () {
	if (gamerOrPcGame == 2) {
		cout << "�������� ������� �������� �� 1 �� 3: ";
		cin >> cinText;
		if (cinText == "1" || cinText == "2" || cinText == "3") {
			pc_main_level = stoi(cinText);
			cout << "������� - " << name_two << " - " << pc_main_level << endl;
			board();
		}
		else {
			selPcLevel();
		}
	}
	else if (gamerOrPcGame == 3) {
		cout << "�������� ������� �������� PC-1 �� 1 �� 3: ";
		cin >> cinText;
		if (cinText == "1" || cinText == "2" || cinText == "3") {
			pc_one_level = stoi(cinText);
			cout << "������� - " << name_one << " - " << pc_one_level << endl;
		}
		else {
			selPcLevel();
		}

		cout << "�������� ������� �������� PC-2 �� 1 �� 3: ";
		cin >> cinText;
		if (cinText == "1" || cinText == "2" || cinText == "3") {
			pc_two_level = stoi(cinText);
			cout << "������� - " << name_two << " - " << pc_two_level << endl;
		}
		else {
			selPcLevel();
		}

		setNumGame();
	}
}

void setNumGame () {
	cout << "������� ���������� ��� ��� ��/��(����� �����): ";
	cin >> cinTextInt;
	if (!cin.fail()) {
		num_pc_game = cinTextInt;
		visual_game = 1;
		setVisualBoard();
	}
	else {
		setNumGame();
	}	
}

void setVisualBoard () {
	cout << "�������� ������������ ��� ��� (1/0): ";
	cin >> cinTextInt;
	if (!cin.fail()) {
		if (cinTextInt == 1 || cinTextInt == 0) {
			visual_game = cinTextInt;
			board();
		}
		else {
			setVisualBoard();
		}
	}
	else {
		setVisualBoard();
	}

}

void setStep (int g, int step) {
	
}

void setGamerStep (int g, int pcOrUser) {
	if (name_one == "PC" && pcOrUser == 1) {
		cout << "test pc 1" << endl;
		testBreak();
	} else if (name_two == "PC" && pcOrUser == 2) {
		cout << "test pc 2" << endl;
		testBreak();
	} else {
		cout << "��� ��� �� (1 - 9) - ";
		cin >> cinText;
		cinConvertToInt = stoi(cinText);
		if (0 < cinConvertToInt < 10) {
			if (arrBoard[0][0] == cinConvertToInt) arrBoard[0][0] = g;
			else if (arrBoard[0][1] == cinConvertToInt) arrBoard[0][1] = g;
			else if (arrBoard[0][2] == cinConvertToInt) arrBoard[0][2] = g;
			else if (arrBoard[1][0] == cinConvertToInt) arrBoard[1][0] = g;
			else if (arrBoard[1][1] == cinConvertToInt) arrBoard[1][1] = g;
			else if (arrBoard[1][2] == cinConvertToInt) arrBoard[1][2] = g;
			else if (arrBoard[2][0] == cinConvertToInt) arrBoard[2][0] = g;
			else if (arrBoard[2][1] == cinConvertToInt) arrBoard[2][1] = g;
			else if (arrBoard[2][2] == cinConvertToInt) arrBoard[2][2] = g;
			else {
				cout << "����� ������ ��� ������ ��� �� ����������. ���������� ��� ���: " << endl;
				setGamerStep(g, pcOrUser);
			}
			board();
		}
		else {
			setGamerStep(g, pcOrUser);
		}
	}
}

void gamerStep () {
	if (len_game%2 == 1) {
		if (game_play%2 == 1) {
			cout << "��� ������ - " << name_one << endl;
			setGamerStep(96, 1);
		}
		else {
			cout << "��� ������ - " << name_two << endl;
			setGamerStep(96, 2);
		}
	} 
	else {
		if (game_play%2 == 0) {
			cout << "��� ������ - " << name_one << endl;
			setGamerStep(00, 1);
		}
		else {
			cout << "��� ������ - " << name_two << endl;
			setGamerStep(00, 2);
		}
	}	
}

void endGame (int vin) {
	game_play++;
	if (vin == 1) {
		cout << "�������� - X";	
	} 
	else if (vin == 2) {
		cout << "�������� - O";
	} 
	else {
		cout << "�����";
	}
}

void testBreak () {
	cout << "test break stop func =)" << endl;
}


















