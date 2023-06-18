#pragma once
#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <list>
#include <vector>

#include "Entity.h"
#include "Player.h"
#include "Utils.h"

using namespace std;

class World
{
public:
	World();
	~World();
	string Run(vector<string>& actions);

private:
	void SetupWorld();

private:
	list<Entity*> entities;
	Player* player;
};

#endif // !WORLD_H