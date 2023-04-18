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
	int posX;
	int posY;
	map<string, bool> inventory;
};