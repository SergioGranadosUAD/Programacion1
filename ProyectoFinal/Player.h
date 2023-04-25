#include <iostream>
#include <map>
#include <string>

using std::string;
using std::map;

/************************************
* @class :   Player
* @access:   public
* @brief:    Clase que representa al personaje que controlamos en el juego.
* @details:  Cuenta con su posición por medio de coordenadas en X y en Y, así como un mapa que representa un inventario simple por medio de booleanos.
*************************************/
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