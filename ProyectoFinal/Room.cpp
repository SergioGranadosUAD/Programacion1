#include "Room.h"

bool Room::checkMovement(const string& dir) {
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