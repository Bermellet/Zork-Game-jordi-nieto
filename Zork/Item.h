#pragma once
#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"

enum class ItemType {
	ITEM,
	CONTAINER
};

class Item : public Entity
{
public:
	Item(string name, string description, Entity* containedBy, ItemType itemType);
	string Use();
	
	ItemType GetItemType() const;
	virtual bool CanBePicked() const;

protected:
	ItemType itemType;

};


#endif // !ITEM_H