#include "Room.h"

/************************************
* @method:   CheckMovement
* @access:   public
* @return    bool
* @brief:    Esta funci�n recibe un string con una direcci�n y eval�a si es una direcci�n v�lida y es posible moverse en esa direcci�n.
* @details:  Sin detalles.
*************************************/
bool Room::CheckMovement(const string& dir) {
	if (dir == "derecha" && m_canMoveRight) {
		return true;
	}
	else if (dir == "izquierda" && m_canMoveLeft) {
		return true;
	}
	else if (dir == "arriba" && m_canMoveForward) {
		return true;
	}
	else if (dir == "abajo" && m_canMoveBackwards) {
		return true;
	}
	else {
		return false;
	}
}

/************************************
* @method:   UpdateDescription
* @access:   public
* @return    void
* @brief:    Funci�n que recibe un string con una descripci�n y actualiza la descripci�n del cuarto.
* @details:  Su principal uso es para mayor legibilidad en el c�digo.
*************************************/
void Room::UpdateDescription(const string& desc) {
	m_description = desc;
}