#pragma once
#ifndef CHEST_H
#define CHEST_H

#include "Item.h"
#include "Creature.h"

class Chest : public Item
{
public:
	Chest(string name, string description, Entity* containedBy);
	~Chest();
	string PickContents(Creature* picker);

	bool CanContainEntities() const override;
	bool CanBePicked() const override;
	string GetInformation() const override;
};


#endif // !CHEST_H