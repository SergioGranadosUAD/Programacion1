#include <iostream>
#include <vector>
#include <string>
#include "Items.h"

using std::vector;
using std::string;

class Room {
public:
private:
	int posX;
	int posY;
	bool canMoveRight;
	bool canMoveLeft;
	bool canMoveBackwards;
	bool canMoveForward;
	bool isExplored;
	vector<Items> roomItems;
};
