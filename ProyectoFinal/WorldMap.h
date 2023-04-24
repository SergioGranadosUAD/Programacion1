#include <iostream>
#include <vector>
#include "Room.h"
#include "Items.h"
#include "Player.h"

using std::vector;
using std::cout;
using std::endl;

class WorldMap {
public:
	//WorldMap(int sizeX, int sizeY, Player* hero, vector<Room*> rooms);
	~WorldMap();
	void PrintMap();
	void ValidatePlayerMovement(const string& dir);
	void InspectObject(const string& object);
	void CheckObjectInteraction(const string& object);
	void ShowInventory();
	string PrintStartingText();
	

	int m_sizeX;
	int m_sizeY;
	Player* m_hero;

	vector<Room*> m_rooms;

private:
	Room* GetRoomAtPos(const int& posX, const int& posY);
};