#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <string>

#include "Entity.h"
#include "Player.h"
#include "World.h"

enum class ItemType {
	ITEM,
	CONTAINER
};

class Item : public Entity
{
public:
	Item(string name, string description, Entity* containedBy, ItemType itemType);
	~Item();
	string Use(Player* player, World* world);
	
	virtual bool CanBePicked() const;

public:
	ItemType itemType;
	
private:
	bool IsContainer() const;
};


#endif // !ITEM_H