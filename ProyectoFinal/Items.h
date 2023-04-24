#pragma once

#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Items {
public:
	Items(string name, string description, bool isAvailable, int interactionType);

	friend bool operator== (const string& name, const Items& item);
	friend bool operator== (const Items& item, const string& name);
	friend bool operator!= (const string& name, const Items& item);
	friend bool operator!= (const Items& item, const string& name);
	friend ostream& operator<<(ostream& os, const Items& item);

	enum INTERACTION_TYPE {
		PICKUP = 0,
		SLOT_MACHINE = 1,
		TRANSFORMER_LEVER = 2,
		TRANSFORMER = 3,
		SAFE = 4,
		LEVER_I = 5,
		LEVER_II = 6,
		LEVER_III = 7,
		PEDESTAL_SPADE_KEY = 8,
		GAS_LEVER = 9,
		PIPE = 10,
		STARTING_PEDESTAL = 11
	};

	string m_name;
	string m_description;
	bool m_isAvailable;
	INTERACTION_TYPE m_interactionType;
private:
	
};