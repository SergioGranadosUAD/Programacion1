#include "Player.h"

void Player::movePlayer(const string& dir) {
	if (dir == "derecha") {
		posX += 1;
	}
	else if (dir == "izquierda") {
		posX -= 1;
	}
	else if (dir == "arriba") {
		posY -= 1;
	}
	else if (dir == "abajo") {
		posY += 1;
	}
}