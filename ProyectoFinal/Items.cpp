#include "Items.h"

/************************************
* @method:   Items()
* @access:   public
* @return    Items
* @brief:    Constructor de la clase Items().
* @details:  Uno de los valores se recibe como entero pero se castea a un enum interno para mejor legibilidad.
*************************************/
Items::Items(string name, string description, bool isAvailable, int interactionType):
	m_name(name), m_description(description), m_isAvailable(isAvailable), m_interactionType(static_cast<INTERACTION_TYPE>(interactionType)) {
}

/************************************
* @method:   Operator==
* @access:   public
* @return    void
* @brief:    Sobrecarga del operador == que evalua si un string es igual que el miembro m_name de la clase.
* @details:  Sin detalles.
*************************************/
bool operator== (const string& name, const Items& item) {
	if (name == item.m_name) {
		return true;
	}
	else {
		return false;
	}
}

/************************************
* @method:   Operator==
* @access:   public
* @return    void
* @brief:    Sobrecarga del operador == que evalua si un string es igual que el miembro m_name de la clase.
* @details:  Sin detalles.
*************************************/
bool operator== (const Items& item, const string& name) {
	if (name == item.m_name) {
		return true;
	}
	else {
		return false;
	}
}

/************************************
* @method:   Operator!=
* @access:   public
* @return    void
* @brief:    Sobrecarga del operador == que evalua si un string es diferente a el miembro m_name de la clase.
* @details:  Sin detalles.
*************************************/
bool operator!= (const string& name, const Items& item) {
	if (name != item.m_name) {
		return true;
	}
	else {
		return false;
	}
}

/************************************
* @method:   Operator!=
* @access:   public
* @return    void
* @brief:    Sobrecarga del operador == que evalua si un string es diferente a el miembro m_name de la clase.
* @details:  Sin detalles.
*************************************/
bool operator!= (const Items& item, const string& name) {
	if (name != item.m_name) {
		return true;
	}
	else {
		return false;
	}
}

/************************************
* @method:   Operator<<
* @access:   public
* @return    void
* @brief:    Sobrecarga del operador << que imprime solo el miembro m_name de la clase.
* @details:  Sin detalles.
*************************************/
ostream& operator<<(ostream& os, const Items& item) {
	os << item.m_name;
	return os;
}