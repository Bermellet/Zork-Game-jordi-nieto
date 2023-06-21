#pragma once
#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <list>
#include <vector>
#include <set>

#include "Utils.h"
#include "Entity.h"
#include "Player.h"
#include "Chest.h"

using namespace std;

class World
{
public:
	World();
	~World();
	string Run(vector<string>& actions);

private:
	void SetupWorld();
	void Look();
	void Move();

	bool IsValidCommand(string& command);
	bool IsCommandActions(string& command);
	bool IsCommandObjectives(string& command);
	bool IsCommandMovement(string& command);

public:
	bool finished;
	bool gameOver;

private:
	list<Entity*> entities;
	Player* player;
	// Actions list
	set<string> commandActions;
	set<string> commandObjectives;
	set<string> commandMovements;
};

#endif // !WORLD_H