#include <iostream>
#include <vector>
#include <string>
#include "Items.h"

using std::vector;
using std::string;

class Room {
public:
	bool checkMovement(string direction);

	int posX;
	int posY;

private:
	string description;
	bool canMoveRight;
	bool canMoveLeft;
	bool canMoveForward;
	bool canMoveBackwards;
	bool isExplored;
	vector<Items> roomItems;
};
