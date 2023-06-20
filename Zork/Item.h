#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <string>

#include "Entity.h"

enum class ItemType {
	ITEM,
	CONTAINER
};

class Item : public Entity
{
public:
	Item(string name, string description, Entity* containedBy, ItemType itemType);
	~Item();
	
	virtual bool CanBePicked();

public:
	ItemType itemType;
	
private:
	bool IsContainer();
};


#endif // !ITEM_H