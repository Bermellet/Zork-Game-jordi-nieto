#include "Creature.h"

Creature::Creature(string name, string description, Room* currentRoom) :
	Entity(name, description, currentRoom)
{
	this->currentRoom = currentRoom;
	this->max_hp = 100;
	this->hp = max_hp;
	this->entityType = EntityType::CREATURE;
}

void Creature::Pick(Item* item) {
	if (item->CanBePicked()) {
		AddEntity(item);
		cout << "\n" << item->GetName() << " has been added to your inventory\n";
	}
	else {
		cout << "\n" << item->GetName() << " cannot be picked up\n";
	}
}

void Creature::Drop(Item* item) {
	currentRoom->AddEntity(item);
	cout << "\n" << item->GetName() << " dropped to the current room\n";
}

bool Creature::isAlive() {
	return hp > 0;
}

bool Creature::CanContainEntities() const {
	return true;
}

string Creature::GetInventoryItemsNames() {
	ostringstream oss;

	bool first = true;
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); it++) {
		Entity* entity = (*it);
		if (entity->GetType() == EntityType::ITEM) {
			if (first) {
				first = !first;
				oss << "The items on " << name << "'s inventory are:";
			}
			oss << "\n\t- " << entity->GetName();
		}
	}
	if (first) {
		oss << name << "'s inventory is empty";
	}

	return oss.str();
}

Item* Creature::GetInventoryItem(string name) {

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

Room* Creature::GetCurrentRoom() {
	return currentRoom;
}