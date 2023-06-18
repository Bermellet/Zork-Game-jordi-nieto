#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <string>

using namespace std;

enum class EntityType {
	ROOM,
	PLAYER,
	ITEM
};

class Entity {
public:
	Entity(const string& name = string(), const string& description = string());
	~Entity();

public:
	EntityType type;
	string name;
	string description;
};

#endif // !ENTITY_H