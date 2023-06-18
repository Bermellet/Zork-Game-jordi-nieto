#pragma once
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

#include "Entity.h"

class Room : public Entity
{
public:
	//Room();
	Room(const string& name = string(), const string& description = string());
	~Room();
	void Setup();
	void SetNeighbors(Room* ptrNorth, Room* ptrSouth, Room* ptrEast, Room* ptrWest);
	void OutputNeighbors();
public:
	Room* ptrNeighborNorth;
	Room* ptrNeighborSouth;
	Room* ptrNeighborEast;
	Room* ptrNeighborWest;
};

#endif // !ROOM_H