#include "WorldMap.h"

void WorldMap::PrintMap() {
	cout << "\033[0m\t. 1 2 3 4 5 6 7" << endl;
	for (int i = 0; i < sizeY; ++i) {
		cout << "\t\033[0m" << i+1 << " ";
		for (int j = 0; j < sizeX; ++j) {
			bool roomFound = false;
			for (Room r : rooms) {
				if (r.posX == j && r.posY == i) {
					roomFound = true;
				}
				else {
					
				}
			}

			if (roomFound) {
				cout << "\033[32m# ";
			}
			else {
				cout << "\033[33m. ";
			}
		}
		cout << endl;
	}
	cout << endl << "\033[31mCoordenadas actuales: " << endl;
	cout << "\033[32m# simboliza un cuarto explorado." << endl;
	cout << "@ simboliza el cuarto en el que se encuentra el jugador" << endl << endl;
}