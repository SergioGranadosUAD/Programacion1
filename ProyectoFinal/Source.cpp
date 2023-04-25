#include <iostream>
#include <fstream>
#include <sstream>
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
using std::istringstream;

using json = nlohmann::json;

WorldMap* NewGame(const string& loadMode);
void SaveGame(const WorldMap* wm);
void StartGame(WorldMap* worldMap);

Room* ConstructRoom(const json& data, const string& i);
Items ConstructItem(const json& data, const string& actualRoom, const string& itemIterator);
Player* ConstructPlayer(const json& data);
map<string, bool> ConstructTriggers(const json& data);

void SaveRooms(json& saveData, const WorldMap* wm);
void SaveItems(json& saveData, const WorldMap* wm, const string& actualRoom, const Room*& room);
void SavePlayer(json& saveData, const WorldMap* wm);
void SaveTriggers(json& saveData, const WorldMap* wm);

void ToLowerString(string& s);

int main() {
	bool salida = true;

	while (salida) {
		cout << "Bienvenido a este juego de aventura de texto sencillo." << endl << endl;
		cout << "Escriba 'Iniciar' para empezar una nueva partida." << endl;
		cout << "Escriba 'Continuar' para cargar una partida anteriormente guardada." << endl;
		cout << "Escriba 'Salir' para terminar el programa." << endl;

		string seleccion = "";
		cout << "> ";
		cin >> seleccion;
		ToLowerString(seleccion);

		if (seleccion == "iniciar") {
			StartGame(NewGame("NewGame.json"));
		}
		else if (seleccion == "continuar") {
			StartGame(NewGame("SavedGame.json"));
		}
		else if (seleccion == "salir") {
			cout << "Se ha terminado el programa." << endl;
			salida = false;
		}
		else {
			cout << "Se introdujo una palabra no reconocida." << endl;
		}

		system("cls");
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}

	return 0;
}

/************************************
* @method:   NewGame
* @access:   public
* @return    WorldMap*
* @brief:    Funcion que se encarga de leer los datos del juego y guardar los datos de este en el heap.
* @details:  Se encuentra dividida en varias funciones para mayor legibilidad.
*************************************/
WorldMap* NewGame(const string& loadMode) {
	string inputFileName = loadMode;
	ifstream inputFile { inputFileName };
	if (!inputFile) {
		//error("No se pudo abrir el archivo de entrada.");
	}

	json data = json::parse(inputFile);
	
	int worldMapSizeX = data["worldMap"]["sizeX"];
	int worldMapSizeY = data["worldMap"]["sizeY"];

	Player* worldMapPlayer = ConstructPlayer(data);

	vector<Room*> gameRooms;
	
	int roomIterator = 1;
	while (data["worldMap"]["rooms"].contains("room" + to_string(roomIterator))) {
		gameRooms.push_back(ConstructRoom(data, to_string(roomIterator)));
		++roomIterator;
	}

	map<string, bool> triggers = ConstructTriggers(data);

	WorldMap* wm = new WorldMap { worldMapSizeX, worldMapSizeY, worldMapPlayer, gameRooms, triggers };
	
	return wm;
}

/************************************
* @method:   SaveGame
* @access:   public
* @return    void
* @brief:    Contrario a NewGame, crea un documento en JSON ocupando los datos del juego.
* @details:  Debido a las limitaciones de la librería de JSON el documento se encuentra en desorden pero es funcional.
*************************************/
void SaveGame(const WorldMap* wm) {
	string outputFileName = "SavedGame.json";
	ofstream outputFile{ outputFileName };

	if (!outputFile) {
		//error("No se pudo abrir el archivo de entrada.");
	}

	json saveData;

	saveData["worldMap"]["sizeX"] = wm->m_sizeX;
	saveData["worldMap"]["sizeY"] = wm->m_sizeY;

	SaveRooms(saveData, wm);
	SavePlayer(saveData, wm);
	SaveTriggers(saveData, wm);

	outputFile << std::setw(4) << saveData;

	cout << "El juego se ha guardado satisfactoriamente!" << endl;
}

/************************************
* @method:   StartGame
* @access:   public
* @return    void
* @brief:    Funcion que contiene el loop principal del juego, ocupando el objecto WorldMap obtenido de la funcion NewGame().
* @details:  Sin detalles.
*************************************/
void StartGame(WorldMap* worldMap) {
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	system("cls");

	bool loop = true;
	string input = "";
	istringstream iss;
	string comando = "";
	int inputCount = 0;

	cout << "\033[32m";
	cout << "Escriba 'Ayuda' para ver los comandos disponibles." << endl;
	cout << worldMap->PrintStartingText() << endl;
	cout << "\033[0m";

	//Loop principal del juego
	while (loop) {
		istringstream().swap(iss);
		input = "";
		cout << "> ";
		getline(cin, input);
		ToLowerString(input);
		iss.str(input);
		comando = string();
		inputCount = 0;

		while (iss >> comando) {
			++inputCount;
		}

		iss.clear();
		iss.str(input);

		iss >> comando;
		cout << "\033[32m";

		if (comando == "mover") {
			if (inputCount > 1) {
				iss >> comando;
				ToLowerString(comando);
				worldMap->ValidatePlayerMovement(comando);
			}
			else {
				cout << "Moverse a donde?" << endl;
			}
			
		}

		else if (comando == "inspeccionar") {
			if (inputCount > 1) {
				iss >> comando;
				ToLowerString(comando);
				worldMap->InspectObject(comando);
			}
			else {
				cout << "Inspeccionar que?" << endl;
			}
		}

		//Dependiendo del valor de retorno de esta opcion puede terminar el loop del juego.
		//Cuando se requiere más de una palabra se lee el resto del string stream, y se manda la segunda palabra para evaluacion dependiendo del contexto.
		else if (comando == "interactuar") {
			if (inputCount > 1) {
				iss >> comando;
				ToLowerString(comando);
				WorldMap::GAME_STATE gameState = worldMap->CheckObjectInteraction(comando);

				if (gameState == WorldMap::GAME_OVER) {
					cout << "Has muerto." << endl;
					cout << "GAME OVER." << endl;
					loop = false;
				}
				else if (gameState == WorldMap::WIN_CONDITION) {
					cout << "YOU WIN." << endl;
					loop = false;
				}
			}
			else {
				cout << "Interactuar con que?" << endl;
			}
		}

		else if (comando == "ayuda") {
			cout << "Comandos disponibles: " << endl;
			cout << "Mover <Arriba/Abajo/Derecha/Izquierda>, Inspeccionar <Objeto/Cuarto>, Interactuar <Objeto>, Inventario, Imprimir mapa, Guardar, Ayuda, Salir." << endl << endl;
		}

		else if (comando == "imprimir") {
			if (inputCount > 1) {
				iss >> comando;
				ToLowerString(comando);
				if (comando == "mapa") {
					worldMap->PrintMap();
				}
				else {
					cout << "Solo se puede imprimir el mapa." << endl;
				}
			}
			else {
				cout << "Imprimir que?" << endl;
			}
		}

		else if (comando == "inventario") {
			worldMap->ShowInventory();
		}

		else if (comando == "guardar") {
			SaveGame(worldMap);
		}

		else if (comando == "salir") {
			cout << "Esta seguro de que desea salir de la partida? Se perdera el progreso no guardado" << endl
				<< ". Escriba 'Si' para proceder, en caso contrario escriba cualquier otra cosa para seguir con el juego." << endl;
			string respuesta = "";
			cin >> respuesta;
			ToLowerString(respuesta);
			if (respuesta == "si") {
				loop = false;
			}
			else {
				cout << "Se ha elegido resumir el juego." << endl;
			}
		}
		else {
			cout << "Se introdujo un comando no reconocido." << endl;
		}
		cout << "\033[0m";
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	cout << "Se ha terminado la partida." << endl;
	cout << "Presione enter para continuar. " << endl;
	cin.get();
	delete worldMap;
	system("cls");
}

/************************************
* @method:   ToLowerString
* @access:   public
* @return    void
* @brief:    Función que recibe un string y convierte todos sus caracteres en minusculas.
* @details:  Se hace el reemplazo directo del string por medio de una referencia.
*************************************/
void ToLowerString(string& s) {
	for (char& c : s) {
		c = tolower(c);
	}
}

/************************************
* @method:   ConstructRoom
* @access:   public
* @return    Room*
* @brief:    Funcion que lee el documento de json, creando un objeto de tipo Room para su uso por la funcion NewGame().
* @details:  Estas función a su vez invoca la función ConstructItem() para poblar un vector que forma parte del objeto.
*************************************/
Room* ConstructRoom(const json& data, const string& i) {
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
		roomItems.push_back(ConstructItem(data, actualRoom, to_string(itemIterator)));
		++itemIterator;
	}

	return new Room{roomPosX, roomPosY, roomDescription, roomCanMoveRight, roomCanMoveLeft, roomCanMoveForward,
	roomCanMoveBackwards, roomIsExplored, roomItems};
}

/************************************
* @method:   ConstructItem
* @access:   public
* @return    Items
* @brief:    Función que lee el documento de json y crea un objeto de tipo Items que será almacenado en un vector del objeto Room.
* @details:  Sin detalles.
*************************************/
Items ConstructItem(const json& data, const string& actualRoom, const string& itemIterator) {
	string actualItem = "item" + itemIterator;

	string itemName = data["worldMap"]["rooms"][actualRoom]["items"][actualItem]["name"];
	string itemDescription = data["worldMap"]["rooms"][actualRoom]["items"][actualItem]["description"];
	bool itemIsAvaiable = data["worldMap"]["rooms"][actualRoom]["items"][actualItem]["isAvailable"];
	int itemInteractionType = data["worldMap"]["rooms"][actualRoom]["items"][actualItem]["interactionType"];
	return Items{itemName, itemDescription, itemIsAvaiable, itemInteractionType};
}

/************************************
* @method:   ConstructPlayer
* @access:   public
* @return    Player*
* @brief:    Función que lee el documento de json y crea un objeto de tipo Player para su uso por la función de NewGame().
* @details:  Sin detalles.
*************************************/
Player* ConstructPlayer(const json& data) {
	int playerPosX = data["player"]["posX"];
	int playerPosY = data["player"]["posY"];

	map<string, bool> playerInventory;

	for (auto& it : data["player"]["inventory"].items()) {
		playerInventory[it.key()] = it.value();
	}

	return new Player{ playerPosX, playerPosY, playerInventory };
}

/************************************
* @method:   ConstructTriggers
* @access:   public
* @return    map<string, bool>
* @brief:    Funcion que lee el documento de json y regresa un mapa de strings y booleanos que será usado por la función de NewGame() para crear el mapa del mundo.
* @details:  Sin detalles.
*************************************/
map<string, bool> ConstructTriggers(const json& data) {
	map<string, bool> worldMapTriggers;

	for (auto& it : data["worldMap"]["triggers"].items()) {
		worldMapTriggers[it.key()] = it.value();
	}

	return worldMapTriggers;
}

/************************************
* @method:   SaveRooms
* @access:   public
* @return    void
* @brief:    Funcion que lee los cuartos contenidos en worldMap y guarda la información de estos en un objeto de tipo json.
* @details:  Se guarda la información directamente por medio de una referencia.
*************************************/
void SaveRooms(json& saveData, const WorldMap* wm) {
	int roomIterator = 1;
	for (const Room* r : wm->m_rooms) {
		string actualRoom = "room" + to_string(roomIterator);
		saveData["worldMap"]["rooms"][actualRoom]["posX"] = r->m_posX;
		saveData["worldMap"]["rooms"][actualRoom]["posY"] = r->m_posY;
		saveData["worldMap"]["rooms"][actualRoom]["description"] = r->m_description;
		saveData["worldMap"]["rooms"][actualRoom]["canMoveRight"] = r->m_canMoveRight;
		saveData["worldMap"]["rooms"][actualRoom]["canMoveLeft"] = r->m_canMoveLeft;
		saveData["worldMap"]["rooms"][actualRoom]["canMoveForward"] = r->m_canMoveForward;
		saveData["worldMap"]["rooms"][actualRoom]["canMoveBackwards"] = r->m_canMoveBackwards;
		saveData["worldMap"]["rooms"][actualRoom]["isExplored"] = r->m_isExplored;

		SaveItems(saveData, wm, actualRoom, r);
		++roomIterator;
	}
}

/************************************
* @method:   Items
* @access:   public
* @return    void
* @brief:    Funcion que lee los items que forman parte de los cuartos y guarda la información de estos en un objeto de tipo json.
* @details:  Se guarda la información directamente por medio de una referencia.
*************************************/
void SaveItems(json& saveData, const WorldMap* wm, const string& actualRoom, const Room*& room) {
	int itemIterator = 1;
	for (const Items& i : room->m_roomItems) {
		string actualItem = "item" + to_string(itemIterator);
		saveData["worldMap"]["rooms"][actualRoom]["items"][actualItem]["name"] = i.m_name;
		saveData["worldMap"]["rooms"][actualRoom]["items"][actualItem]["description"] = i.m_description;
		saveData["worldMap"]["rooms"][actualRoom]["items"][actualItem]["isAvailable"] = i.m_isAvailable;
		saveData["worldMap"]["rooms"][actualRoom]["items"][actualItem]["interactionType"] = static_cast<int>(i.m_interactionType);
		++itemIterator;
	}
}

/************************************
* @method:   SaveRooms
* @access:   public
* @return    void
* @brief:    Funcion que lee la información del jugador contenida en worldMap y guarda la información de este en un objeto de tipo json.
* @details:  Se guarda la información directamente por medio de una referencia.
*************************************/
void SavePlayer(json& saveData, const WorldMap* wm) {
	saveData["player"]["posX"] = wm->m_hero->posX;
	saveData["player"]["posY"] = wm->m_hero->posY;


	for (const auto& pair : wm->m_hero->inventory) {
		saveData["player"]["inventory"][pair.first] = pair.second;
	}
}

/************************************
* @method:   SaveTriggers
* @access:   public
* @return    void
* @brief:    Funcion que lee los el mapa que guarda los triggers de worldMap y guarda la información de estos en un objeto de tipo json.
* @details:  Se guarda la información directamente por medio de una referencia.
*************************************/
void SaveTriggers(json& saveData, const WorldMap* wm) {
	for (const auto& pair : wm->m_triggers) {
		saveData["worldMap"]["triggers"][pair.first] = pair.second;
	}
}
