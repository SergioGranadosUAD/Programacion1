#include <iostream>
#include <fstream>
#include <string>

#include "WorldMap.h"
#include "Player.h"
#include "json.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::to_string;

using json = nlohmann::json;

void NewGame();
void SaveGame();
void LoadGame();
void ExitGame();
void StartGame();
Room constructRoom(const json& data, const string& i);
Items constructItem(const json& data, const string& actualRoom, const string& itemIterator);

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
			NewGame();
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

void NewGame() {
	string inputFileName = "NewGame.json";
	ifstream inputFile { inputFileName };
	if (!inputFile) {
		//error("No se pudo abrir el archivo de entrada.");
	}

	json data = json::parse(inputFile);
	
	int worldMapSizeX = data["worldMap"]["sizeX"];
	int worldMapSizeY = data["worldMap"]["sizeY"];

	vector<Room> gameRooms;
	
	int roomIterator = 1;
	while (data["worldMap"]["rooms"].contains("room" + to_string(roomIterator))) {
		gameRooms.push_back(constructRoom(data, to_string(roomIterator)));
		++roomIterator;
	}

	WorldMap wm = WorldMap{ worldMapSizeX, worldMapSizeY, gameRooms };
	cout << "worldmap generated successfully" << endl;
	wm.PrintMap();
	
}

void SaveGame() {

}

void LoadGame() {

}

void ExitGame() {

}

void StartGame() {

}

void ToLowerString(string& s) {
	for (char& c : s) {
		c = tolower(c);
	}
}

Room constructRoom(const json& data, const string& i) {
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

	return Room{roomPosX, roomPosY, roomDescription, roomCanMoveRight, roomCanMoveLeft, roomCanMoveForward,
	roomCanMoveBackwards, roomIsExplored, roomItems};
}

Items constructItem(const json& data, const string& actualRoom, const string& itemIterator) {
	string actualItem = "item" + itemIterator;

	string itemName = data["worldMap"]["rooms"][actualRoom]["items"][actualItem]["name"];
	string itemDescription = data["worldMap"]["rooms"][actualRoom]["items"][actualItem]["description"];
	bool itemIsAvaiable = data["worldMap"]["rooms"][actualRoom]["items"][actualItem]["isAvailable"];
	return Items{itemName, itemDescription, itemIsAvaiable};
}
