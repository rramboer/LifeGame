#pragma once
#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Generation {
public:
	Generation() : SIZE(5), numCells((int)pow(SIZE, 2)) { }

	Generation(int size_in) : SIZE(size_in), numCells((int)pow(SIZE, 2)) { // FIXME: Not actually random
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				int random_i = rand() % (SIZE); // random integer [ 0 , size - 1 ]
				int random_j = rand() % (SIZE);
				vector<int> random = { random_i, random_j };
				cells.push_back(random);
			}
		}
	}

	Generation(vector<vector<int>>& livingCells_in) {
		cells = livingCells_in;
		SIZE = cells.size();
		numCells = (int)pow(SIZE, 2);
	}

	Generation nextGeneration() {
		// empty cell gets life if 2-3 neighbors
		// living cell dies if no neighbors or more than 4 neighbors

		for (int i = 0; i < SIZE; ++i) {
			int numLife = countNeighborLife(cells[i]);
			if (numLife != 0 && numLife != 4) {
				add(cells[i], nextGen);
			}
		}
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				int countLife = 0;
				vector<int> point = { i, j };
				if (!has(cells, point)) {
					countLife = countNeighborLife(point);
					if (countLife == 2 || countLife == 3) {
						add(point, nextGen);
					}
				}
			}
		}
		return nextGen;
	}

	int getNumCells() const {
		return numCells;
	}

	int getCell(int& i1, int i2) const {
		return cells[i1][i2];
	}

	int getSIZE() const {
		return SIZE;
	}

private:
	int SIZE;
	int numCells;
	vector<vector<int>> cells;
	vector<vector<int>> nextGen;

	int countNeighborLife(vector<int>& cell) { // FIXME
		int lifeCount = 0;

		if (isAlive(cell[0], cell[1] - 1)) { // x, y - 1
			lifeCount++;
		}
		if (isAlive(cell[0], cell[1] + 1)) { //x, y + 1
			lifeCount++;
		}
		if (isAlive(cell[0] - 1, cell[1])) { // x - 1, y
			lifeCount++;
		}
		if (isAlive(cell[0] + 1, cell[1])) { // x + 1, y
			lifeCount++;
		}
		if (isAlive(cell[0] + 1, cell[1] + 1)) { // x + 1, y + 1
			lifeCount++;
		}
		if (isAlive(cell[0] - 1, cell[1] - 1)) { // x - 1, y - 1
			lifeCount++;
		}
		return lifeCount;
	}

	bool isAlive(int x, int y) const {
		vector<int> point = { x, y };
		if (find(cells.begin(), cells.end(), point) != cells.end()) {
			return true;
		}
		return false;
	}

	void add(vector<int>& coord, vector<vector<int>>& arr) { // adds to vector 
		if (!(has(arr, coord))) {
			if (coord[0] < SIZE && coord[1] < SIZE) {
				arr.push_back(coord);
			}
		}
	}

	bool has(vector<vector<int>>& vec, vector<int>& point) { // checks invariant: no duplicates
		return (find(vec.begin(), vec.end(), point) != vec.end());
	}
};

ostream& operator<<(ostream& os, Generation& g) {
	for (int i = 0; i < g.getSIZE(); ++i) {
		os << "{ " << g.getCell(i, 0) << " , " << g.getCell(i, 1) << " }" << endl;
	}
	return os;
}
