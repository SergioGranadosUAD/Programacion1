#include <iostream>
#include <fstream>
#include <string>

#include "WorldMap.h"
#include "json.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::to_string;

using json = nlohmann::json;

WorldMap* NewGame();
void SaveGame();
void LoadGame();
void ExitGame();
void StartGame(WorldMap* worldMap);
Room* constructRoom(const json& data, const string& i);
Items constructItem(const json& data, const string& actualRoom, const string& itemIterator);
Player* constructPlayer(const json& data);

void ToLowerString(string& s);

int main() {
	bool salida = true;
	cout << "Bienvenido a este juego de aventura de texto sencillo." << endl;
	cout << "Escriba 'Iniciar' para empezar una nueva partida." << endl;
	cout << "Escriba 'Continuar' para cargar una partida anteriormente guardada." << endl;
	cout << "Escriba 'Salir' para terminar el programa." << endl;

	while (salida) {
		string seleccion = "";
		cout << "> ";
		cin >> seleccion;
		ToLowerString(seleccion);

		if (seleccion == "iniciar") {
			StartGame(NewGame());
		}
		else if (seleccion == "continuar") {
			cout << "Continuar" << endl;
		}
		else if (seleccion == "salir") {
			cout << "Se ha terminado el programa." << endl;
			salida = false;
		}
		else {
			cout << "Se introdujo una palabra no reconocida." << endl;
		}

		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}

	return 0;
}

WorldMap* NewGame() {
	string inputFileName = "NewGame.json";
	ifstream inputFile { inputFileName };
	if (!inputFile) {
		//error("No se pudo abrir el archivo de entrada.");
	}

	json data = json::parse(inputFile);
	
	int worldMapSizeX = data["worldMap"]["sizeX"];
	int worldMapSizeY = data["worldMap"]["sizeY"];

	Player* worldMapPlayer = constructPlayer(data);

	vector<Room*> gameRooms;
	
	int roomIterator = 1;
	while (data["worldMap"]["rooms"].contains("room" + to_string(roomIterator))) {
		gameRooms.push_back(constructRoom(data, to_string(roomIterator)));
		++roomIterator;
	}

	WorldMap* wm = new WorldMap { worldMapSizeX, worldMapSizeY, worldMapPlayer, gameRooms };
	
	return wm;
}

void SaveGame() {

}

void LoadGame() {

}

void ExitGame() {

}

void StartGame(WorldMap* worldMap) {
	worldMap->PrintMap();
}

void ToLowerString(string& s) {
	for (char& c : s) {
		c = tolower(c);
	}
}

Room* constructRoom(const json& data, const string& i) {
	string actualRoom = "room" + i;

	int roomPosX = data["worldMap"]["rooms"][actualRoom]["posX"];
	int roomPosY = data["worldMap"]["rooms"][actualRoom]["posY"];
	string roomDescription = data["worldMap"]["rooms"][actualRoom]["description"];
	bool roomCanMoveRight = data["worldMap"]["rooms"][actualRoom]["canMoveRight"];
	bool roomCanMoveLeft = data["worldMap"]["rooms"][actualRoom]["canMoveLeft"];
	bool roomCanMoveForward = data["worldMap"]["rooms"][actualRoom]["canMoveForward"];
	bool roomCanMoveBackwards = data["worldMap"]["rooms"][actualRoom]["canMoveBackwards"];
	bool roomIsExplored = data["worldMap"]["rooms"][actualRoom]["isExplored"];
	
	vector<Items> roomItems;
	int itemIterator = 1;
	while (data["worldMap"]["rooms"][actualRoom]["items"].contains("item" + to_string(itemIterator))) {
		roomItems.push_back(constructItem(data, actualRoom, to_string(itemIterator)));
		++itemIterator;
	}

	return new Room{roomPosX, roomPosY, roomDescription, roomCanMoveRight, roomCanMoveLeft, roomCanMoveForward,
	roomCanMoveBackwards, roomIsExplored, roomItems};
}

Items constructItem(const json& data, const string& actualRoom, const string& itemIterator) {
	string actualItem = "item" + itemIterator;

	string itemName = data["worldMap"]["rooms"][actualRoom]["items"][actualItem]["name"];
	string itemDescription = data["worldMap"]["rooms"][actualRoom]["items"][actualItem]["description"];
	bool itemIsAvaiable = data["worldMap"]["rooms"][actualRoom]["items"][actualItem]["isAvailable"];
	return Items{itemName, itemDescription, itemIsAvaiable};
}

Player* constructPlayer(const json& data) {
	int playerPosX = data["player"]["posX"];
	int playerPosY = data["player"]["posY"];

	map<string, bool> playerInventory;
	playerInventory["item1"] = data["player"]["inventory"]["item1"];
	playerInventory["item2"] = data["player"]["inventory"]["item2"];
	playerInventory["item3"] = data["player"]["inventory"]["item3"];

	return new Player{ playerPosX, playerPosY, playerInventory };
}
