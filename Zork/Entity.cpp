#include "Entity.h"

Entity::Entity(const string& name = string(), const string& description = string(), Entity* containedBy = nullptr) :
	name(name), description(description), containedBy(containedBy)
{
	this->entityType = EntityType::ENTITY;

	if (containedBy != nullptr) {
		containedBy->contains.push_back(this);
	}
}

Entity::~Entity() {
	for (Entity* e : contains) {
		if (e != nullptr) {
			delete e;
		}
	}
}

void Entity::AddEntity(Entity* entity) {
	if (CanContainEntities()) {
		if (entity->containedBy != nullptr) {
			entity->containedBy->RemoveEntity(entity);
		}
		entity->containedBy = this;
		contains.push_back(entity);
	}
	else {
		cout << this->GetName() << " cannot hold entities!\n";
	}
}

void Entity::RemoveEntity(Entity* entity) {
	if (CanContainEntities()) {
		contains.erase(remove(contains.begin(), contains.end(), entity));
	}
	else {
		cout << this->GetName() << " cannot hold entities!\n";
	}
}

bool Entity::ContainsEntity(Entity* entity) const {
	if (CanContainEntities()) {
		list<Entity*>::const_iterator it = find(contains.begin(), contains.end(), entity);
		return it != contains.end();
	}
	else {
		cout << this->GetName() << " cannot hold entities!\n";
		return false;
	}
}

bool Entity::ContainsEntity(string& entity) const {
	if (CanContainEntities()) {
		list<Entity*>::const_iterator it = find_if(contains.begin(), contains.end(), [&entity](const Entity* obj) { return obj->GetName() == entity; });
		return it != contains.end();
	}
	else {
		cout << this->GetName() << " cannot hold entities!\n";
		return false;
	}
}

Entity* Entity::FindEntity(string& entity) const {
	if (CanContainEntities()) {
		list<Entity*>::const_iterator it = find_if(contains.begin(), contains.end(), [&entity](const Entity* obj) { return obj->GetName() == entity; });
		if (it != contains.end()) {
			return *it;
		}
	}
	else {
		cout << this->GetName() << " cannot hold entities!\n";
	}
	return nullptr;
}

EntityType Entity::GetType() const {
	return entityType;
}

string Entity::GetName() const {
	return name;
}

string Entity::GetDescription() const {
	return description;
}

bool Entity::CanContainEntities() const {
	return false;
}

string Entity::GetInformation() const {
	ostringstream oss;

	oss << "Entity " << name << ": " << description;
	if (containedBy != nullptr) {
		oss << "\n\tIs inside " << containedBy->GetName();
	}
	if (contains.size() > 0) {
		oss << "\n\tContains entities:";
		for (Entity* e : contains) {
			oss << "\n\t- " << e->GetName();
		}
	}

	return oss.str();
}

bool Entity::operator==(const Entity& e) const {
	return entityType == e.entityType && name == e.name && description == e.description;
}