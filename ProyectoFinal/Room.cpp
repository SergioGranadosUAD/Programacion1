#include "Room.h"

/************************************
* @method:   CheckMovement
* @access:   public
* @return    bool
* @brief:    Esta función recibe un string con una dirección y evalúa si es una dirección válida y es posible moverse en esa dirección.
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
* @brief:    Función que recibe un string con una descripción y actualiza la descripción del cuarto.
* @details:  Su principal uso es para mayor legibilidad en el código.
*************************************/
void Room::UpdateDescription(const string& desc) {
	m_description = desc;
}