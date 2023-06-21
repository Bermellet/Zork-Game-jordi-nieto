#include "Chest.h"

Chest::Chest(string name, string description, Entity* containedBy) :
	Item(name, description, containedBy, ItemType::CONTAINER)
{

}

Chest::~Chest() {

}

string Chest::PickContents(Creature* picker) {
	list<Entity*>::iterator it = contains.begin();
	while (it != contains.end()) {
		if ((*it)->GetType() == EntityType::ITEM) {
			Item* item = static_cast<Item*>((*it));
			++it;
			if (item->CanBePicked()) {
				picker->Pick(item);
			}
		}
		else { ++it; }
	}

	if (contains.size() == 0) {
		return name + " is now empty";
	}
	else {
		return name + " still has some entities that could not be picked";
	}
}

bool Chest::CanContainEntities() const {
	return true;
}

bool Chest::CanBePicked() const {
	return false;
}

string Chest::GetInformation() const {
	ostringstream oss;

	oss << "\n" << name << "\n--------------------\n" << description << "\n";
	if (contains.size() > 0) {
		bool first = true;
		for (Entity* e : contains) {
			if (e->GetType() == EntityType::ITEM) {
				if (first) {
					first = !first;
					oss << "\nContains items:";
				}
				oss << "\n\t- " << e->GetName();
			}
		}
		if (!first) {
			oss << "\n";
		}

		first = true;
		for (Entity* e : contains) {
			if (e->GetType() == EntityType::CREATURE) {
				if (first) {
					first = !first;
					oss << "\nContains creatures:";
				}
				oss << "\n\t- " << e->GetName();
			}
		}
		if (!first) {
			oss << "\n";
		}
	}
	return oss.str();
}