#pragma once

#include <string>

using std::string;

class Items {
public:
	Items(string name, string description, bool isAvailable, int interactionType);
	enum INTERACTION_TYPE {
		FIXED = 0,
		PICKUP = 1
	};
	string m_name;
	string m_description;
	bool m_isAvailable;
	INTERACTION_TYPE m_interactionType;
private:
	
};