#include "Item.h"

Item::Item(string name, string description, Entity* containedBy, ItemType itemType) :
	Entity(name, description, containedBy)
{
	this->entityType = EntityType::ITEM;
	this->itemType = itemType;
}

Item::~Item() {

}

bool Item::CanBePicked() {
	return true;
}

bool Item::IsContainer() {
	return this->itemType == ItemType::CONTAINER;
}
