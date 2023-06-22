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

	void SetFinished(bool value);
	void SetGameOver(bool value);
	bool finished() const;
	bool gameOver() const;

private:
	void SetupWorld();
	string BuildHelp();
	bool IsValidCommand(string& command);
	bool IsCommandActions(string& command);
	bool IsCommandObjectives(string& command);
	bool IsCommandMovement(string& command);
private:
	list<Entity*> entities;
	Player* player;
	// Actions list
	set<string> commandActions;
	set<string> commandObjectives;
	set<string> commandMovements;

	bool _finished;
	bool _gameOver;
};

#endif // !WORLD_H