#pragma once
#ifndef CHEST_H
#define CHEST_H

#include "Item.h"

class Chest : Item
{
	Chest(string name, string description, Entity* containedBy);
	~Chest();

	bool CanContainEntities() const override;
	bool CanBePicked() override;
};


#endif // !CHEST_H