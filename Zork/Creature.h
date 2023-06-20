#pragma once
#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <vector>
#include <string>

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

	vector<string> getInventoryItemsNames();
	Item* getInventoryItem(string name);

protected:
	Room* currentRoom;
	list<Item*> inventory;

	int hp;
	int max_hp;

};

#endif // !CREATURE_H