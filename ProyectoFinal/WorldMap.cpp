#include "WorldMap.h"

void WorldMap::AddRoom(int posX, int posY, string desc, bool cmL, bool cmR, bool cmF, bool cmB, bool isExpl, vector<Items> items) {
	rooms.push_back(Room{ posX, posY, desc, cmL, cmR, cmB, cmF, isExpl, items });
}

void WorldMap::PrintMap() {
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			for (Room r : rooms) {
				if (r.posX == i && r.posY == j) {
					cout << "# ";
				}
				else {
					cout << ". ";
				}
			}
		}
		cout << endl;
	}
}