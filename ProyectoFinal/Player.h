#include <iostream>
#include <map>
#include <string>

using std::string;
using std::map;

class Player {
public:
	int posX;
	int posY;
	map<string, bool> inventory;

	void addItem();
	bool getItem();

private:
	
};