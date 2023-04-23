#include "Items.h"

Items::Items(string name, string description, bool isAvailable, int interactionType):
	m_name(name), m_description(description), m_isAvailable(isAvailable), m_interactionType(static_cast<INTERACTION_TYPE>(interactionType)) {
}