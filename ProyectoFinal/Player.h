#include <iostream>
#include <map>
#include <string>

using std::string;
using std::map;

class Player {
public:
	void movePlayer(const string& dir);

	int posX;
	int posY;
	map<string, bool> inventory;
private:
	
};