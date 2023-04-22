#include <iostream>
#include <vector>
#include <string>
#include "Items.h"

using std::vector;
using std::string;

class Room {
public:
	//Room() {};
	//~Room() {};
	int m_posX;
	int posY;
	string description;
	bool canMoveRight;
	bool canMoveLeft;
	bool canMoveForward;
	bool canMoveBackwards;
	bool isExplored;
	vector<Items> roomItems;

	bool checkMovement(string direction);
private:
};
