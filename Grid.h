#pragma once
#include <iostream>
#include <string>
using namespace std;

/*
	ROOM FOR SCALING
*/
class Grid {
public:

	Grid() {
		gridSize = 5;
		gridIndex = getGridIndex();
	}

	Grid(int size_in) {
		gridSize = size_in;
		gridIndex = getGridIndex();
	}

	int getGridIndex() {
		switch (gridSize) {
		case 5:
			gridIndex = 5 + 2 * 3; // 11
			return gridIndex;
		case 6:
			gridIndex = 6 + 2 * 4; // 14
			return gridIndex;
		case 7:
			gridIndex = 7 + 2 * 5; // 17
			return gridIndex;
		case 8:
			gridIndex = 8 + 2 * 6; // 20
			return gridIndex;
		case 9:
			gridIndex = 9 + 2 * 7; // 23
			return gridIndex;
		case 10:
			gridIndex = 10 + 2 * 8; // 26
			return gridIndex;
		case 11:
			gridIndex = 11 + 2 * 9; // 29
			return gridIndex;
		case 12:
			gridIndex = 12 + 2 * 10; // 32
			return gridIndex;
		case 13:
			gridIndex = 13 + 2 * 11; // 35
			return gridIndex;
		case 14:
			gridIndex = 14 + 2 * 12; // 38
			return gridIndex;
		case 15:
			gridIndex = 15 + 2 * 13; // 41
			return gridIndex;
		default:
			break;
		}
		gridIndex = 5 + 2 * 3; // should never get here
		return gridIndex;
	}

	string& getGrid(int index) {
		switch (gridSize) {
		case 5:
			return grid_5[index];
		case 6:
			return grid_6[index];
		case 7:
			return grid_7[index];
		case 8:
			return grid_8[index];
		case 9:
			return grid_9[index];
		case 10:
			return grid_10[index];
		case 11:
			return grid_11[index];
		case 12:
			return grid_12[index];
		case 13:
			return grid_13[index];
		case 14:
			return grid_14[index];
		case 15:
			return grid_15[index];
		default:
			break;
		}
		return grid_5[index]; // should never get here
	}

	string grid_5[11] = {
		"                 ___",
		"             ___/ 4 \\___",
		"         ___/ 3 \\_4_/ 4 \\___",
		"     ___/ 2 \\_4_/ 3 \\_3_/ 4 \\___",
		" ___/ 1 \\_4_/ 2 \\_3_/ 3 \\_2_/ 4 \\___",
		"/ 0 \\_4_/ 1 \\_3_/ 2 \\_2_/ 3 \\_1_/ 4 \\",
		"\\_4_/ 0 \\_3_/ 1 \\_2_/ 2 \\_1_/ 3 \\_0_/ ",
		"    \\_3_/ 0 \\_2_/ 1 \\_1_/ 2 \\_0_/",
		"        \\_2_/ 0 \\_1_/ 1 \\_0_/",
		"            \\_1_/ 0 \\_0_/",
		"                \\_0_/"
	};

	string grid_6[14] = {};

	string grid_7[17] = {};

	string grid_8[20] = {};

	string grid_9[23] = {};

	string grid_10[26] = {};

	string grid_11[29] = {};

	string grid_12[32] = {};

	string grid_13[35] = {};

	string grid_14[38] = {};

	string grid_15[41] = {};

private:
	int gridIndex; // number of rows needed to print grid
	int gridSize; // size of the board
};

ostream& operator<<(ostream& os, Grid& g) {
	for (int i = 0; i < (g.getGridIndex()); ++i) {
		os << g.getGrid(i) << endl;
	}
	return os;
}