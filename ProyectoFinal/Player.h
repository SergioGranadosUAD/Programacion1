#include <iostream>
#include <map>
#include <string>

using std::string;
using std::map;

class Player {
public:
	void addItem();
	bool getItem();

private:
	map<string, bool> inventory;
	int posX;
	int posY;
};