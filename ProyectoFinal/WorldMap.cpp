#include "WorldMap.h"

WorldMap::WorldMap(int sizeX, int sizeY, Player* hero, vector<Room*> rooms, map<string, bool> triggers):
m_sizeX(sizeX), m_sizeY(sizeY), m_hero(hero), m_rooms(rooms), m_triggers(triggers) {

}

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
			InteractWithItem(item);
			itemFound = true;
		}
	}
	if (!itemFound) {
		cout << "No se ha encontrado ese objeto." << endl;
	}
	cout << endl;
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

WorldMap::GAME_STATE WorldMap::InteractWithItem(Items& item) {
	switch (item.m_interactionType) {
	case item.PICKUP:

		return NORMAL;
		break;

	case item.SLOT_MACHINE:

		return NORMAL;
		break;

	case item.TRANSFORMER_LEVER:
		m_triggers["transformerLeverEnabled"] = true;
		item.m_isAvailable = false;
		cout << "Bajas la palanca y puedes notar que el transformador cercano se encendio, abriendo su compuerta." << endl;

		Room* updatedRoom = GetRoomAtPos(4, 2);
		updatedRoom->m_roomItems[1].m_description = "Al observar detenidamente este transformador puedes notar que al prender el transformador se abrio una compuerta en la que parece haber una llave.\nA pesar de esto parece una muy mala idea tratar de agarrarla sin tener alguna clase de proteccion.";

		return NORMAL;
		break;

	case item.TRANSFORMER:
		if (m_triggers["transformerLeverEnabled"] && m_hero->FindItemInInventory("Guantes de electricista")) {
			item.m_isAvailable = false;
			m_hero->UpdatePlayerInventory("Llave de diamantes");
			cout << "" << endl;
		}
		else if (m_triggers["transformerLeverEnabled"]) {
			item.m_isAvailable = false;
			cout << "" << endl;
			return GAME_OVER;
		}
		else {
			cout << "No puedes hacer nada con el transformador mientras se encuentre apagado." << endl;
		}
		
		return NORMAL;
		break;

	case item.LEVER_I:
		m_triggers["leverIEnabled"] = true;
		item.m_isAvailable = false;
		if (m_triggers["leverIEnabled"] && m_triggers["leverIIEnabled"] && m_triggers["leverIIIEnabled"]) {
			Room* updatedRoom = GetRoomAtPos(4, 2);
			updatedRoom->m_canMoveForward = true;
			updatedRoom->m_description = "En este cuarto encuentras otra palanca en en centro del muro. Parece ser que el sonido fuerte provenia de la escotilla de arriba, la cual ahora se encuentra abierta. Puedo volver por donde vine o subir a la escotilla que se acaba de abrir.";
			cout << "Al bajar la palanca puedes escuchar un 'click' bastante fuerte en otro cuarto." << endl;
		}
		else {
			cout << "Bajas la palanca pero no parece que algo haya sucedido. Probablemente haya mas palancas numeradas que deba de bajar." << endl;
		}
		return NORMAL;
		break;

	case item.LEVER_II:
		m_triggers["leverIIEnabled"] = true;
		item.m_isAvailable = false;
		if (m_triggers["leverIEnabled"] && m_triggers["leverIIEnabled"] && m_triggers["leverIIIEnabled"]) {
			Room* updatedRoom = GetRoomAtPos(4, 2);
			updatedRoom->m_canMoveForward = true;
			updatedRoom->m_description = "En este cuarto encuentras otra palanca en en centro del muro. Parece ser que el sonido fuerte provenia de la escotilla de arriba, la cual ahora se encuentra abierta. Puedo volver por donde vine o subir a la escotilla que se acaba de abrir.";
			cout << "Al bajar la palanca puedes escuchar un 'click' bastante fuerte en otro cuarto." << endl;
		}
		else {
			cout << "Bajas la palanca pero no parece que algo haya sucedido. Probablemente haya mas palancas numeradas que deba de bajar." << endl;
		}
		return NORMAL;
		break;

	case item.LEVER_III:
		m_triggers["leverIIIEnabled"] = true;
		item.m_isAvailable = false;
		if (m_triggers["leverIEnabled"] && m_triggers["leverIIEnabled"] && m_triggers["leverIIIEnabled"]) {
			Room* updatedRoom = GetRoomAtPos(4, 2);
			updatedRoom->m_canMoveForward = true;
			updatedRoom->m_description = "En este cuarto encuentras otra palanca en en centro del muro. Parece ser que el sonido fuerte provenia de la escotilla de arriba, la cual ahora se encuentra abierta. Puedo volver por donde vine o subir a la escotilla que se acaba de abrir.";
			cout << "Al bajar la palanca puedes escuchar un 'click' bastante fuerte en otro cuarto." << endl;
		}
		else {
			cout << "Bajas la palanca pero no parece que algo haya sucedido. Probablemente haya mas palancas numeradas que deba de bajar." << endl;
		}
		return NORMAL;
		break;

	case item.PEDESTAL_CLUBS_KEY:
		item.m_isAvailable = false;
		m_hero->UpdatePlayerInventory("Llave de treboles");
		cout << "Agarras la llave de treboles que se encuentra en el pedestal." << endl;
		return NORMAL;
		break;

	case item.GAS_LEVER:
		m_triggers["gasLeverEnabled"] = true;
		item.m_isAvailable = false;
		cout << "Bajas la palanca y puedes escuchar como disminuye la presion del gas en las tuberias." << endl;
		return NORMAL;
		break;

	case item.PIPE:
		if (m_hero->FindItemInInventory("Valvula de gas") && m_triggers["gasLeverEnabled"]) {
			m_hero->UpdatePlayerInventory("Valvula de gas");
			m_hero->UpdatePlayerInventory("Llave de picas");
			cout << "Intentas poner la valvula de gas y abrir el flujo. Momentos despues sientes un ligero golpe en la cabeza y te das cuenta de que una llave de picas cayo de un ducto en el techo directamente sobre ti. Te preguntas lo peligroso que hubiera sido si no hubieras disminuido el suministro de gas." << endl;

		}
		else if (m_hero->FindItemInInventory("Valvula de gas")) {
			cout << "A pesar de lo peligroso que parece, decides poner la valvula de gas y abrir el flujo. Momentos despues sientes un fuerte impacto en tu cabeza y tu vision se desvanece a negro." << endl;
			return GAME_OVER;
		}
		else {
			cout << "Te hace falta una valvula de gas para interactuar con la tuberia." << endl;
		}
		return NORMAL;
		break;

	case item.GIANT_POT:
		if (m_hero->FindItemInInventory("Martillo")) {
			item.m_isAvailable = false;
			m_hero->UpdatePlayerInventory("Martillo");
			m_hero->UpdatePlayerInventory("Nota de caja fuerte");
			cout << "Usaste el martillo para romper el jarron gigante, revelando una nota que contiene el codigo de una caja fuerte, decides agarrarlo." << endl;
		}
		else {
			cout << "Te hace falta algo para romper el jarron." << endl;
		}
		return NORMAL;
		break;

	case item.STARTING_PEDESTAL:
		bool hasInteracted = false;
		if (m_hero->FindItemInInventory("Llave de diamantes")) {
			m_hero->UpdatePlayerInventory("Llave de diamantes");
			m_triggers["diamondsKeyPlaced"] = true;
			cout << "Pusiste la llave de diamantes en su lugar." << endl;
			hasInteracted = true;
		}
		if (m_hero->FindItemInInventory("Llave de corazones")) {
			m_hero->UpdatePlayerInventory("Llave de corazones");
			m_triggers["heartsKeyPlaced"] = true;
			cout << "Pusiste la llave de corazones en su lugar." << endl;
			hasInteracted = true;
		}
		if (m_hero->FindItemInInventory("Llave de treboles")) {
			m_hero->UpdatePlayerInventory("Llave de treboles");
			m_triggers["clubsKeyPlaced"] = true;
			cout << "Pusiste la llave de treboles en su lugar." << endl;
			hasInteracted = true;
		}
		if (m_hero->FindItemInInventory("Llave de picas")) {
			m_hero->UpdatePlayerInventory("Llave de picas");
			m_triggers["spadesKeyPlaced"] = true;
			cout << "Pusiste la llave de picas en su lugar." << endl;
			hasInteracted = true;
		}

		if (m_triggers["diamondsKeyPlaced"] && m_triggers["heartsKeyPlaced"] && m_triggers["clubsKeyPlaced"] && m_triggers["spadesKeyPlaced"]) {
			return WIN_CONDITION;
		}

		if (!hasInteracted) {
			cout << "No tienes nada que hacer con el pedestal." << endl;
		}
		return NORMAL;
		break;
	}
}