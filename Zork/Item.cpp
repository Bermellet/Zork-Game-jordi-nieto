#include "Item.h"

Item::Item(string name, string description, Entity* containedBy, ItemType itemType) :
	Entity(name, description, containedBy)
{
	this->entityType = EntityType::ITEM;
	this->itemType = itemType;
}

Item::~Item() {

}

ItemType Item::GetItemType() const {
	return this->itemType;
}

bool Item::CanBePicked() const {
	return true;
}

string Item::Use() {
	if (itemType == ItemType::ITEM) {
		if (name == "torch") {
			return "You use the torch. Now the path is a lot brighter.";
		}
		else if (name == "potion") {
			delete(this);
			return "You open the potion, ready to use it.";
		}
	}
	return "You cannot use this object";
}