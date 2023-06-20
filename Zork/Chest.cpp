#include "Chest.h"

Chest::Chest(string name, string description, Entity* containedBy) :
	Item(name, description, containedBy, ItemType::CONTAINER)
{

}

Chest::~Chest() {

}

bool Chest::CanContainEntities() const {
	return true;
}

bool Chest::CanBePicked() {
	return false;
}