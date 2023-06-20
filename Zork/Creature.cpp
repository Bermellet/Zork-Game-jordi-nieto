#include "Creature.h"

Creature::Creature(string name, string description, Room* currentRoom) :
	Entity(name, description, currentRoom)
{
	this->currentRoom = currentRoom;
	this->max_hp = 100;
	this->hp = max_hp;
	this->type = EntityType::CREATURE;
}

Creature::~Creature() {
	for (Entity* e: inventory) {
		if (e != nullptr) {
			delete e;
		}
	}
}

void Creature::Pick(Item* item) {
	item->containedBy = this; // TODO: check if was in another container?
	inventory.push_back(item);
	cout << "\n" << item->GetName() << "has been added to your inventory.\n";
}

void Creature::Drop(Item* item) {
	item->containedBy = currentRoom;
	currentRoom->contains.push_back(item);
	inventory.erase(remove(inventory.begin(), inventory.end(), item));
	cout << "\n" << item->GetName() << "dropped to the current room.\n";
}

bool Creature::isAlive() {
	return hp > 0;
}

vector<string> Creature::getInventoryItemsNames() {
	vector<string> result;

	for (list<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
		result.push_back((*it)->GetName());
	}

	return result;
}

Item* Creature::getInventoryItem(string name) {

	for (list<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
		Item* item = (*it);
		if (Equals(item->GetName(), name)) {
			return item;
		}
	}

	return nullptr;
}
