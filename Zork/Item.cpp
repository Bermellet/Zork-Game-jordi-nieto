#include "Item.h"

Item::Item(string name, string description, Entity* containedBy, ItemType itemType) :
	Entity(name, description, containedBy)
{
	this->entityType = EntityType::ITEM;
	this->itemType = itemType;
}

Item::~Item() {

}

bool Item::CanBePicked() const {
	return true;
}

bool Item::IsContainer() const {
	return this->itemType == ItemType::CONTAINER;
}
