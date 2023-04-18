#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main () {
	srand(time(0));
	string text_in, mes;
	cout << "Hello World" << endl;

	return 0;
}


//Старый код
/*

#include <iostream>
#include <typeinfo.h>
#include <stdlib.h>
#include <ctime>
#include <string>
using namespace std;

int arrBoard[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int arrVinStep[8][6] = {{0, 0, 0, 1, 0, 2}, {1, 0, 1, 1, 1, 2}, {2, 0, 2, 1, 2, 2},
						{0, 0, 1, 0, 2, 0}, {0, 1, 1, 1, 2, 1}, {0, 2, 1, 2, 2, 2},
						{0, 0, 1, 1, 2, 2}, {0, 2, 1, 1, 2, 0}};

int step=0, set, testStep=0, vinStep, protectStep=0;
int i=0, j=0, gameKol=0, stepNumY, difGame;
int intAtoi, gamerOrPcGame=0, numStepp;
int name1count, name2count, nameBufcount;
string cindata, name1, name2, nameBuf, namePcStepTest;

void gamerOrPc();
void nameGamerAndPc();
void board();
void testVin();
void gameStepSet();
void nextFuncGame();

int main () {
	srand(time(0));
	difGame=0;
	gamerOrPc();
	return 0;
}

void gamerOrPc() {
	system("CLS");
	cout << "1 --- (gamer and gamer) or 2 --- (game and pc) or 3 --- (pc and pc)" << endl;
	getline(cin, cindata);
	if (cindata == "1" || cindata == "2" || cindata == "3") {
		intAtoi = atoi(cindata.c_str());
		gamerOrPcGame=intAtoi;
		nameGamerAndPc();
	} else {
		gamerOrPc();
	}
}

void nameGamerAndPc() {
	if (gamerOrPcGame==1) {
		cout << "name gamer 1 --- ";
		getline(cin, name1);
		cout << "name gamer 2 --- ";
		getline(cin, name2);
		cout << name1 << " -- Gamer1 -- (X) || " << name2 << " -- Gamer2 -- (0)" << endl;
		step = 1;
		name1count=0;
		name2count=0;
		board();
	} else if (gamerOrPcGame==2) {
		cout << "name gamer 1 --- ";
		getline(cin, name1);
		cout << "level PC 1 or 2 or 3" << endl;
		getline(cin, cindata);
		if (cindata == "1") {
			name2 = "PC-L-1";
		} else if (cindata == "2") {
			name2 = "PC-L-2";
		}  else if (cindata == "3") {
			name2 = "PC-L-3";
		} else {
			nameGamerAndPc();
		}
		cout << name1 << " -- Gamer1 -- (X) || " << name2 << " -- Gamer2 -- (0)" << endl;
		step = 1;
		name1count=0;
		name2count=0;
		board();
	} else if (gamerOrPcGame==3) {
		cout << "Select level PC-1 -- 1 or 2 or 3" << endl;
		getline(cin, cindata);
		if (cindata == "1") {
			name1 = "PC-L-1";
		} else if (cindata == "2") {
			name1 = "PC-L-2";
		}  else if (cindata == "3") {
			name1 = "PC-L-3";
		} else {
			nameGamerAndPc();
		}
		cout << "Select level PC-2 -- 1 or 2 or 3" << endl;
		getline(cin, cindata);
		if (cindata == "1") {
			name2 = "PC-L-1";
		} else if (cindata == "2") {
			name2 = "PC-L-2";
		}  else if (cindata == "3") {
			name2 = "PC-L-3";
		} else {
			nameGamerAndPc();
		}
		cout << name1 << " -- Gamer1 -- (X) || " << name2 << " -- Gamer2 -- (0)" << endl;
		step = 1;
		name1count=0;
		name2count=0;
		board();
	}
}

void board() {
	if (step==1) {
		cout << "---  " << name1 << " step" << "  ---" << endl;
	} else if (step==2) {
		cout << "---  " << name2 << " step" << "  ---" << endl;
	}
	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			if (arrBoard[i][j] == 96) {
				if (j == 2) {
					cout << "X" << endl;
				} else {
					cout << "X" << "-";
				}
			} else if (arrBoard[i][j] == 00) {
				if (j == 2) {
					cout << "O" << endl;
				} else {
					cout << "O" << "-";
				}
			} else {
				if (j == 2) {
					cout << arrBoard[i][j] << endl;
				} else {
					cout << arrBoard[i][j] <<"-";
				}
			}
		}
	}
	testVin();
}

void testVin() {
	for (i=0; i<8; i++) {
		if (arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] == 96 && arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] == 96 && arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] == 96) {
			cout << name1 << "---Vin" << endl;
			name1count=name1count+1;
			nextFuncGame();
		} else if (arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] == 00 && arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] == 00 && arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] == 00) {
			cout << name2 << "---Vin" << endl;
			name2count=name2count+1;
			nextFuncGame();
		}
	}
	testStep++;
	if (testStep==10) {
		nextFuncGame();
	} else {
		gameStepSet();
	}

}

void gameStepSet() {

	if (step == 1) {
		namePcStepTest = name1;
		vinStep = 96;
		protectStep = 00;
	} else if (step == 2) {
		namePcStepTest = name2;
		vinStep = 00;
		protectStep = 96;
	}


	if (namePcStepTest == "PC-L-1" || namePcStepTest == "PC-L-2" || namePcStepTest == "PC-L-3") {
		set=0;
		for (i=0; i<3; i++) {
			for (j=0; j<3; j++) {
				if (arrBoard[i][j] != 96 && arrBoard[i][j] != 00) {
					set++;
				}
			}
		}

		if (namePcStepTest=="PC-L-1") {
			numStepp = rand() % 9 + 1;
			for (i=0; i<3; i++) {
				for (j=0; j<3; j++) {
					if (arrBoard[i][j] == numStepp) {
						arrBoard[i][j] = vinStep;
						if (step == 1) {
							step = 2;
						} else if (step == 2) {
							step = 1;
						}
						board();
					}
				}
			}
			gameStepSet();
		} else if (namePcStepTest=="PC-L-2" || namePcStepTest=="PC-L-3") {
			//vin serch
			for (i=0; i<8; i++) {
				if (((arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] != 96 && arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] != 00) && arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] == vinStep && arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] == vinStep) || (arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] == vinStep && (arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] != 96 && arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] != 00) && arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] == vinStep) || (arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] == vinStep && arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] == vinStep && (arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] != 96 && arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] != 00))) {
					if (arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] != 96 && arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] != 00) {
						arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] = vinStep;
					} else if (arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] != 96 && arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] != 00) {
						arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] = vinStep;
					} else if (arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] != 96 && arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] != 00) {
						arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] = vinStep;
					}
					if (step == 1) {
						step = 2;
					} else if (step == 2) {
						step = 1;
					}
					board();
				}
			}
			//vin serch
			//protect serch protectStep
			for (i=0; i<8; i++) {
				if (((arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] != 96 && arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] != 00) && arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] == protectStep && arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] == protectStep) || (arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] == protectStep && (arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] != 96 && arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] != 00) && arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] == protectStep) || (arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] == protectStep && arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] == protectStep && (arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] != 96 && arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] != 00))) {
					if (arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] != 96 && arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] != 00) {
						arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] = vinStep;
					} else if (arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] != 96 && arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] != 00) {
						arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] = vinStep;
					} else if (arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] != 96 && arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] != 00) {
						arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] = vinStep;
					}
					if (step == 1) {
						step = 2;
					} else if (step == 2) {
						step = 1;
					}
					board();
				}
			}
			//protect serch

			//stepPC

			if (namePcStepTest=="PC-L-3") {
				if (set == 9) {
					arrBoard[1][1] = vinStep;
					if (step == 1) {
						step = 2;
					} else if (step == 2) {
						step = 1;
					}
					board();
				} else if (set == 8) {
					stepNumY = rand() % 4 + 1;
					if (stepNumY == 1) {
						if (arrBoard[0][0] == 1) {
							arrBoard[0][0] = vinStep;
							if (step == 1) {
								step = 2;
							} else if (step == 2) {
								step = 1;
							}
							board();
						}
						gameStepSet();
					}  else if (stepNumY == 2) {
						if (arrBoard[0][2] == 3) {
							arrBoard[0][2] = vinStep;
							if (step == 1) {
								step = 2;
							} else if (step == 2) {
								step = 1;
							}
							board();
						}
						gameStepSet();
					} else if (stepNumY == 3) {
						if (arrBoard[2][0] == 7) {
							arrBoard[2][0] = vinStep;
							if (step == 1) {
								step = 2;
							} else if (step == 2) {
								step = 1;
							}
							board();
						}
						gameStepSet();
					} else if (stepNumY == 4) {
						if (arrBoard[2][2] == 9) {
							arrBoard[2][2] = vinStep;
							if (step == 1) {
								step = 2;
							} else if (step == 2) {
								step = 1;
							}
							board();
						}
						gameStepSet();
					}
				} else if (set < 8) {
					for (i=0; i<8; i++) {
						if (((arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] != 96 && arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] != 00) && (arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] != 96 && arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] != 00) && arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] == vinStep) || (arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] == vinStep && (arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] != 96 && arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] != 00) && (arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] != 96 && arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] != 00)) || ((arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] != 96 && arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] != 00) && arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] == vinStep && (arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] != 96 && arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] != 00))) {
							numStepp = rand() % 2 + 1;
							if (arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] == vinStep) {
								if (numStepp == 1) {
									arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] = vinStep;
								} else {
									arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] = vinStep;
								}
							} else if (arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] == vinStep) {
								if (numStepp == 1) {
									arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] = vinStep;
								} else {
									arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] = vinStep;
								}
							} else if (arrBoard[arrVinStep[i][4]][arrVinStep[i][5]] == vinStep) {
								if (numStepp == 1) {
									arrBoard[arrVinStep[i][0]][arrVinStep[i][1]] = vinStep;
								} else {
									arrBoard[arrVinStep[i][2]][arrVinStep[i][3]] = vinStep;
								}
							}
							if (step == 1) {
								step = 2;
							} else if (step == 2) {
								step = 1;
							}
							board();
						}
					}
					numStepp = rand() % 9 + 1;
					for (i=0; i<3; i++) {
						for (j=0; j<3; j++) {
							if (arrBoard[i][j] == numStepp) {
								arrBoard[i][j] = vinStep;
								if (step == 1) {
									step = 2;
								} else if (step == 2) {
									step = 1;
								}
								board();
							}
						}
					}
					gameStepSet();
				}
			} else if (namePcStepTest=="PC-L-2") {
				if (set == 9) {
					arrBoard[1][1] = vinStep;
					if (step == 1) {
						step = 2;
					} else if (step == 2) {
						step = 1;
					}
					board();
				}

				numStepp = rand() % 9 + 1;
				for (i=0; i<3; i++) {
					for (j=0; j<3; j++) {
						if (arrBoard[i][j] == numStepp) {
							arrBoard[i][j] = vinStep;
							if (step == 1) {
								step = 2;
							} else if (step == 2) {
								step = 1;
							}
							board();
						}
					}
				}
				gameStepSet();
			}

			//stepPC
		}

	} else {
		cout << namePcStepTest << " step -- ";
		getline(cin, cindata);
		if (cindata == "1" || cindata == "2" || cindata == "3" || cindata == "4" || cindata == "5" || cindata == "6" || cindata == "7" || cindata == "8" || cindata == "9") {
			intAtoi = atoi(cindata.c_str());
			for (i=0; i<3; i++) {
				for (j=0; j<3; j++) {
					if (arrBoard[i][j] == intAtoi) {
						arrBoard[i][j] = vinStep;
						if (step == 1) {
							step = 2;
						} else if (step == 2) {
							step = 1;
						}
					}
				}
			}
			board();
		} else {
			cout << "incorect step pls agen" << endl;
			gameStepSet();
		}
	}
}

void nextFuncGame() {
	gameKol=gameKol+1;
	cout << name1 << "--(" << name1count << ") --- " << name2 << "--(" << name2count << ")" << " col game-" <<  gameKol << endl;
	if (gameKol<difGame) {
		cindata="1";
	} else {
		cout << "1 -- Continue or 2 -- new game" << endl;
		getline(cin, cindata);
	}


	if (cindata == "1" || cindata == "2") {
		if (cindata == "1") {
			set=0;
			for (i=0; i<3; i++) {
				for (j=0; j<3; j++) {
					set++;
					arrBoard[i][j] = set;
				}
			}
			nameBufcount=name2count;
			name2count=name1count;
			name1count=nameBufcount;
			nameBuf=name2;
			name2=name1;
			name1=nameBuf;
			step=1;
			testStep=0;
			board();
		} else {
			set=0;
			for (i=0; i<3; i++) {
				for (j=0; j<3; j++) {
					set++;
					arrBoard[i][j] = set;
				}
			}
			testStep=0;
			gameKol=0;
			name2count=0;
			name1count=0;
			name2="";
			name1="";
			gamerOrPc();
		}
	} else {
		nextFuncGame();
	}
}




*/