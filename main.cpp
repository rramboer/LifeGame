#include "Generation.h"
#include "Grid.h"
using namespace std;

void format(int size);

void calculate(int s);

int main() {
	
	static int SIZE_BOARD = 0;
	cout << "Enter the size of the board (5 - 15):   ";
	while (true) {
		cin >> SIZE_BOARD;
		if (!cin.fail()) {
			if (SIZE_BOARD > 4 && SIZE_BOARD < 16) {
				break;
			}
			else {
				cout << "\nSize must be between 5 and 15. Try again:   ";
			}
		}
		if (cin.fail()) {
			cout << "\nSize must be an integer. Try again:   ";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	}

	format(SIZE_BOARD);

	calculate(SIZE_BOARD);

	return 0;
}

void calculate(int s) {
	Generation current(s);
	Generation nextGen = current;

	for (int i = 0; i < 5; ++i) {
		cout << nextGen << endl;
		current = nextGen;
		nextGen = current.nextGeneration();
	}
}

void format(int size) {
	Grid grid(size);
	cout << grid << endl;
	cout << "{ x , y }" << endl << "_________" << endl << endl;
}
