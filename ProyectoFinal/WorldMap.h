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
	//WorldMap(int sizeX, int sizeY, Player hero, vector<Room> rooms);
	~WorldMap();
	void PrintMap();

	int m_sizeX;
	int m_sizeY;
	Player* hero;

	vector<Room*> rooms;

private:
	
};