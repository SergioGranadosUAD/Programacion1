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
	bool CheckMovement(const string& dir);

	int m_posX;
	int m_posY;
	string m_description;
	bool m_canMoveRight;
	bool m_canMoveLeft;
	bool m_canMoveForward;
	bool m_canMoveBackwards;
	bool m_isExplored;
	vector<Items> m_roomItems;

	
private:
};
