#include "Entity.h"

Entity::Entity(const string& name = string(), const string& description = string(), Entity* containedBy = nullptr) :
	name(name), description(description), containedBy(containedBy)
{
	this->type = EntityType::ENTITY;

	if (containedBy != nullptr) {
		containedBy->contains.push_back(this);
	}
}

Entity::~Entity() {
	for (Entity* e : contains) {
		delete e;
	}
}

EntityType Entity::GetType() const {
	return type;
}

string Entity::GetName() const {
	return name;
}

string Entity::GetDescription() const {
	return description;
}