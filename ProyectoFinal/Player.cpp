#include "Player.h"

/************************************
* @method:   MovePlayer
* @access:   public
* @return    void
* @brief:	 Este método mueve al jugador en el mapa del mundo dependiendo la dirección que se le indique.
* @details:	 La validación de movimiento se hace en otro método.
*************************************/
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

/************************************
* @method:   UpdatePlayerInventory
* @access:   public
* @return    void
* @brief:	 Este método recibe el nombre de un item en el inventario y voltea su valor.
* @details:	 Permite activar y desactivar items del inventario.
*************************************/
void Player::UpdatePlayerInventory(const string& item) {
	if (inventory[item]) {
		inventory[item] = false;
	}
	else {
		inventory[item] = true;
	}
}

/************************************
* @method:   FindItemInInventory
* @access:   public
* @return    bool
* @brief:	 Este método busca un item en el inventario por su nombre y devuelve su valor.
* @details:	 Sirve para facilitar la lectura del código.
*************************************/
bool Player::FindItemInInventory(const string& item) {
	return inventory.find(item)->second;
}