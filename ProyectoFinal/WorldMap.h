#include <iostream>
#include <vector>
#include "Room.h"

using std::vector;

class WorldMap {
public:
	void AddRoom(int posX, int posY);
	void PrintMap();
private:
	int sizeX;
	int sizeY;

	vector<Room> rooms;
	

};