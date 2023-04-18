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
	void PrintMap();

	int sizeX;
	int sizeY;

	vector<Room> rooms;

private:
	
};