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
	
	virtual bool CanBePicked() const;

public:
	ItemType itemType;
	
private:
	bool IsContainer() const;
};


#endif // !ITEM_H