#include "Items.h"

Items::Items(string name, string description, bool isAvailable, int interactionType):
	m_name(name), m_description(description), m_isAvailable(isAvailable), m_interactionType(static_cast<INTERACTION_TYPE>(interactionType)) {
}

bool operator== (const string& name, const Items& item) {
	if (name == item.m_name) {
		return true;
	}
	else {
		return false;
	}
}

bool operator== (const Items& item, const string& name) {
	if (name == item.m_name) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!= (const string& name, const Items& item) {
	if (name != item.m_name) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!= (const Items& item, const string& name) {
	if (name != item.m_name) {
		return true;
	}
	else {
		return false;
	}
}

ostream& operator<<(ostream& os, const Items& item) {
	os << item.m_name;
	return os;
}