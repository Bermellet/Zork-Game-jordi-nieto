#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <list>

using namespace std;

enum class EntityType {
	ENTITY,
	ROOM,
	CREATURE,
	PLAYER,
	ITEM
};

class Entity {
public:
	Entity(const string& name, const string& description, Entity* containedBy);
	~Entity();

	EntityType GetType() const;
	string GetName() const;
	string GetDescription() const;

public:
	list<Entity*> contains;
	Entity* containedBy;

protected:
	EntityType type;
	string name;
	string description;
};

#endif // !ENTITY_H