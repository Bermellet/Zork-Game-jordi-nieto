#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <algorithm>

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

	void AddEntity(Entity* entity);
	void RemoveEntity(Entity* entity);
	bool ContainsEntity(Entity* entity) const;
	bool ContainsEntity(string& entity) const;
	Entity* FindEntity(string& entity) const;

	EntityType GetType() const;
	string GetName() const;
	string GetDescription() const;
	virtual bool CanContainEntities() const;
	virtual string GetInformation() const;

	bool operator==(const Entity& e) const;

protected:
	EntityType entityType;
	string name;
	string description;

	list<Entity*> contains;
	Entity* containedBy;
};

#endif // !ENTITY_H