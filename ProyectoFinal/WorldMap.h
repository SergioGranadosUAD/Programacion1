#include <iostream>
#include <vector>
#include "Room.h"
#include "Items.h"

using std::vector;
using std::cout;
using std::endl;

class WorldMap {
public:
	//WorldMap() {};
	//~WorldMap() {};
	void AddRoom(int posX, int posY, string desc, bool cmL, bool cmR, bool cmF, bool cmB, bool isExpl, vector<Items> items);
	void PrintMap();


private:
	int sizeX;
	int sizeY;

	vector<Room> rooms;
};