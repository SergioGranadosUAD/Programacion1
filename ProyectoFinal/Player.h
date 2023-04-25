#include <iostream>
#include <map>
#include <string>

using std::string;
using std::map;

class Player {
public:
	void MovePlayer(const string& dir);
	void UpdatePlayerInventory(const string& item);
	bool FindItemInInventory(const string& item);

	int posX;
	int posY;
	map<string, bool> inventory;
private:
	
};