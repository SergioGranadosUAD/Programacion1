#include <iostream>
#include <vector>
#include <string>
#include "Items.h"

using std::vector;
using std::string;

/************************************
* @class:    Room
* @access:   public
* @brief:    Esta clase representa un cuarto que forma parte del mapa del mundo (WorldMap).
* @details:  Cuenta con la posición por coordenadas en X y en Y, la descripción del cuarto, booleanos para verificar las direcciones en las que
*			 se pueden move el jugador, y un vector con objetos de tipo Items que representa los objetos del cuarto con los que se puede interactuar.
*************************************/
class Room {
public:
	//Room() {};
	//~Room() {};
	bool CheckMovement(const string& dir);
	void UpdateDescription(const string& desc);

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
