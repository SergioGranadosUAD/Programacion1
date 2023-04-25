#include "Player.h"

void Player::MovePlayer(const string& dir) {
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

void Player::UpdatePlayerInventory(const string& item) {
	if (inventory[item]) {
		inventory[item] = false;
	}
	else {
		inventory[item] = true;
	}
}

bool Player::FindItemInInventory(const string& item) {
	return inventory.find(item)->second;
}