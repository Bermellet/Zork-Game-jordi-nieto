#include "Creature.h"

Creature::Creature(string name, string description, Room* currentRoom) :
	Entity(name, description, currentRoom)
{
	this->currentRoom = currentRoom;
	this->max_hp = 100;
	this->hp = max_hp;
	this->entityType = EntityType::CREATURE;
}

Creature::~Creature() {
	for (Entity* e: contains) {
		if (e != nullptr) {
			delete e;
		}
	}
}

void Creature::Pick(Item* item) {
	AddEntity(item);
	cout << "\n" << item->GetName() << " has been added to your inventory.\n";
}

void Creature::Drop(Item* item) {
	currentRoom->AddEntity(item);
	cout << "\n" << item->GetName() << " dropped to the current room.\n";
}

bool Creature::isAlive() {
	return hp > 0;
}

bool Creature::CanContainEntities() const {
	return true;
}

vector<string> Creature::getInventoryItemsNames() {
	vector<string> result;

	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); it++) {
		Entity* entity = (*it);
		if (entity->GetType() == EntityType::ITEM) {
			result.push_back(entity->GetName());
		}
	}

	return result;
}

Item* Creature::getInventoryItem(string name) {

	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); it++) {
		Entity* entity = (*it);
		if (entity->GetType() == EntityType::ITEM) {
			if (Equals(entity->GetName(), name)) {
				return (Item*)entity;
			}
		}
	}

	return nullptr;
}
