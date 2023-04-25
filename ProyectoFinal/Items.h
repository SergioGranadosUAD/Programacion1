#pragma once

#include <iostream>
#include <string>

using std::string;
using std::ostream;

/************************************
* @class:    Items
* @access:   public
* @brief:    Esta clase pertenece a un objeto Item que representa un elemento que se encuentra en la clase Room, con el cual se puede interactuar.
* @details:  Cuenta con nombre, descripción, un booleano que indica si se puede interactuar con el objeto o no y el enum correspondiente al tipo
*			 de acción que se puede realizar con este.
*************************************/
class Items {
public:
	Items(string name, string description, bool isAvailable, int interactionType);

	//Enumerador que dicta el tipo de acción que llevará a cabo un objeto al interactuar con este.
	enum INTERACTION_TYPE {
		PICKUP_COIN = 0,
		PICKUP_GLOVES = 1,
		PICKUP_HAMMER = 2,
		PICKUP_VALVE = 3,
		SLOT_MACHINE = 4,
		TRANSFORMER_LEVER = 5,
		TRANSFORMER = 6,
		SAFE = 7,
		LEVER_I = 8,
		LEVER_II = 9,
		LEVER_III = 10,
		PEDESTAL_CLUBS_KEY = 11,
		GAS_LEVER = 12,
		PIPE = 13,
		GIANT_POT = 14,
		STARTING_PEDESTAL = 15
	};

	friend bool operator== (const string& name, const Items& item);
	friend bool operator== (const Items& item, const string& name);
	friend bool operator!= (const string& name, const Items& item);
	friend bool operator!= (const Items& item, const string& name);
	friend ostream& operator<<(ostream& os, const Items& item);

	string m_name;
	string m_description;
	bool m_isAvailable;
	INTERACTION_TYPE m_interactionType;
private:
	
};