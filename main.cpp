#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;
//int arrBoard[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
int arrBoard[3][3] = { {96, 96, 96}, {4, 96, 6}, {00, 8, 9} };
int test_vin_g_o = 0, test_vin_g_x = 0;
int test_vin_v_o = 0, test_vin_v_x = 0;
int test_vin_x_o = 0, test_vin_x_x = 0;

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
	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arrBoard[i][j] == 96) test_vin_g_x++;
			else test_vin_g_x = 0;

			if (arrBoard[i][j] == 00) test_vin_g_o++;
			else test_vin_g_o = 0;

			if (arrBoard[j][i] == 96) test_vin_g_x++;
			else test_vin_v_x = 0;

			if (arrBoard[j][i] == 00) test_vin_g_o++;
			else test_vin_v_o = 0;

			if (test_vin_g_x == 3 || test_vin_g_o == 3 || test_vin_v_x == 3 || test_vin_v_o == 3) {
				if (test_vin_g_x == 3) cout << 'X';
				else if (test_vin_g_o == 3) cout << 'O';
				else if (test_vin_v_x == 3) cout << 'X';
				else if (test_vin_v_o == 3) cout << 'O';
				break;
			} 
		}
	}*/
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
	test_vin_g_o = 0, test_vin_g_x = 0, test_vin_v_o = 0, test_vin_v_x = 0;
	cout << '\t' << " --- good";
}

