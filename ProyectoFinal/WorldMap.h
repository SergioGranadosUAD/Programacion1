#include <iostream>
#include <vector>
#include <map>
#include "Room.h"
#include "Items.h"
#include "Player.h"

using std::vector;
using std::cout;
using std::endl;

/************************************
* @class:    WorldMap
* @access:   public
* @brief:	 Esta clase contiene toda la información del juego y los métodos para que el resto de clases interactuen entre sí.
* @details:	 Se compone del tamaño del mundo en X y en Y, un objeto de clase Player que representa al jugador, una lista de objetos
*			 de clase Room que representa los cuartos que contiene el mundo y un mapa que representa los triggers que representan
*			 el progreso del juego. Además, contiene un enum que sirve para representar el estado en el que se encuentra el juego
*			 y si es necesario terminaro o no.
*************************************/
class WorldMap {
public:
	WorldMap(int sizeX, int sizeY, Player* hero, vector<Room*> rooms, map<string,bool> triggers);
	~WorldMap();

	enum GAME_STATE {
		NORMAL = 0,
		GAME_OVER = 1,
		WIN_CONDITION = 2
	};

	void PrintMap();
	void ValidatePlayerMovement(const string& dir);
	void InspectObject(const string& object);
	GAME_STATE CheckObjectInteraction(const string& object);
	GAME_STATE InteractWithItem(Items& item, Room* playerRoom);
	void ShowInventory();
	string PrintStartingText();
	
	int m_sizeX;
	int m_sizeY;
	Player* m_hero;
	vector<Room*> m_rooms;
	map<string, bool> m_triggers;

private:
	Room* GetRoomAtPos(const int& posX, const int& posY);
};