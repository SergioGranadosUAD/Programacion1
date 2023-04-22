#include "WorldMap.h"

/*WorldMap::~WorldMap() {

}*/

WorldMap::~WorldMap() {
	for (Room* r : rooms) {
		delete r;
	}
	delete hero;
}

void WorldMap::PrintMap() {
	cout << "\033[0m\t. 1 2 3 4 5 6 7" << endl;
	for (int i = 0; i < m_sizeY; ++i) {
		cout << "\t\033[0m" << i+1 << " ";
		for (int j = 0; j < m_sizeX; ++j) {
			bool roomFound = false;
			bool playerFound = false;
			for (Room* r : rooms) {
				if (r->m_posX == j && r->posY == i) {
					roomFound = true;
					if (hero->posX == j && hero->posY == i) {
						playerFound = true;
					}
				}
			}

			if (roomFound && playerFound) {
				cout << "\033[32m@ ";
			} else if (roomFound) {
				cout << "\033[32m# ";
			}
			else {
				cout << "\033[33m. ";
			}
		}
		cout << endl;
	}
	cout << endl << "\033[31mCoordenadas actuales: (" << hero->posX << "," << hero->posY << ")" << endl;
	cout << "\033[32m# simboliza un cuarto explorado." << endl;
	cout << "@ simboliza el cuarto en el que se encuentra el jugador" << endl << endl;
}