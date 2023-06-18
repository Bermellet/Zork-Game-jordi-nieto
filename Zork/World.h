#pragma once
#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <string>
#include <list>

#include "Entity.h"
#include "Player.h"

using namespace std;

class World
{
public:
	World();
	~World();
	void Run();

private:
	void SetupWorld();

private:
	list<Entity*> entities;
	Player* player;
};

#endif // !WORLD_H