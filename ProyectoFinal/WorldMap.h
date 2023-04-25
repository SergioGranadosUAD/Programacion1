#include <iostream>
#include <vector>
#include <map>
#include "Room.h"
#include "Items.h"
#include "Player.h"

using std::vector;
using std::cout;
using std::endl;

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