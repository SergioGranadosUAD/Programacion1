#include "WorldMap.h"

/*WorldMap::~WorldMap() {

}*/

WorldMap::~WorldMap() {
	for (Room* r : m_rooms) {
		delete r;
	}
	delete m_hero;
}

void WorldMap::PrintMap() {
	cout << "\033[0m\t. 0 1 2 3 4 5 6" << endl;
	for (int i = 0; i < m_sizeY; ++i) {
		cout << "\t\033[0m" << i << " ";
		for (int j = 0; j < m_sizeX; ++j) {
			bool roomFound = false;
			bool playerFound = false;
			for (Room* r : m_rooms) {
				if (r->m_posX == j && r->m_posY == i && r->m_isExplored) {
					roomFound = true;
					if (m_hero->posX == j && m_hero->posY == i) {
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
	cout << endl << "\033[31mCoordenadas actuales: (" << m_hero->posX << "," << m_hero->posY << ")" << endl;
	cout << "\033[32m# simboliza un cuarto explorado." << endl;
	cout << "@ simboliza el cuarto en el que se encuentra el jugador\033[0m" << endl << endl;
}

void WorldMap::ValidatePlayerMovement(const string& dir){
	if (dir == "derecha" || dir == "izquierda" || dir == "arriba" || dir == "abajo") {
		Room* playerRoom = GetRoomAtPos(m_hero->posX, m_hero->posY);

		if (playerRoom->CheckMovement(dir)) {
			m_hero->MovePlayer(dir);
			playerRoom = GetRoomAtPos(m_hero->posX, m_hero->posY);
			if (!playerRoom->m_isExplored) {
				playerRoom->m_isExplored = true;
			}
			cout << playerRoom->m_description << endl << endl;
		}
		else {
			cout << "No se puede mover en ese sentido." << endl;
		}
	}
	else {
		cout << "No se ha introducido una direccion correcta." << endl;
	}
	
}

Room* WorldMap::GetRoomAtPos(const int& posX, const int& posY) {
	for (Room* r : m_rooms) {
		if (r->m_posX == posX && r->m_posY == posY) {
			return r;
		}
	}
}

string WorldMap::PrintStartingText() {
	Room* playerRoom = GetRoomAtPos(m_hero->posX, m_hero->posY);
	return playerRoom->m_description;
}

void WorldMap::InspectObject(const string& object) {
	Room* playerRoom = GetRoomAtPos(m_hero->posX, m_hero->posY);
	if (object == "cuarto") {
		if (playerRoom->m_roomItems[0] != "empty") {
			cout << "Al observar detenidamente el cuarto has podido encontrar los siguientes objetos: ";
			for (const Items& item : playerRoom->m_roomItems) {
				if (item.m_isAvailable) {
					cout << item << ", ";
				}
			}
		}
		else {
			cout << "Al observar detenidamente el cuarto no pudiste encontrar ningun objeto relevante.";
		}
	}
	else {
		bool itemFound = false;
		for (const Items& item : playerRoom->m_roomItems) {
			if (object == item) {
				cout << item.m_description;
				itemFound = true;
			}
		}
		if (!itemFound) {
			cout << "No se ha encontrado ese objeto.";
		}
	}
	cout << endl << endl;
}

void WorldMap::CheckObjectInteraction(const string& object) {
	Room* playerRoom = GetRoomAtPos(m_hero->posX, m_hero->posY);
	string returnedItem = "";
	bool itemFound = false;
	for (Items& item : playerRoom->m_roomItems) {
		if(item == object){
			//returnedItem
			itemFound = true;
		}
	}
	if (!itemFound) {
		cout << "No se ha encontrado ese objeto.";
	}

	if (returnedItem != "") {
		m_hero->UpdatePlayerInventory(returnedItem);
	}
	cout << endl << endl;
}
void WorldMap::ShowInventory() {
	cout << "Tengo los siguientes objetos en mi inventario: ";
	for (const auto& item : m_hero->inventory) {
		if (item.second) {
			cout << item.first << ", ";
		}
	}
	cout << endl << endl;
}