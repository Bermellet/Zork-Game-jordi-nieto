#pragma once
#ifndef CREATURE_H
#define CREATURE_H

#include <vector>

#include "Entity.h"
#include "Room.h"
#include "Item.h"
#include "Utils.h"

using namespace std;

class Creature : public Entity
{
public:
	Creature(string name, string description, Room* currentRoom);
	~Creature();
	void Pick(Item* item);
	void Drop(Item* item);
	bool isAlive();
	bool CanContainEntities() const override;

	string GetInventoryItemsNames();
	Item* GetInventoryItem(string name);
	Room* GetCurrentRoom();

protected:
	Room* currentRoom;

	int hp;
	int max_hp;

};

#endif // !CREATURE_H