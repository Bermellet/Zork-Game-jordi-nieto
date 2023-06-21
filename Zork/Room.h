#pragma once
#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"
#include "Utils.h"

enum class MoveOptions {
	NORTH,
	SOUTH,
	EAST,
	WEST
};
string ToStringMoveOption(MoveOptions moveOption);
MoveOptions ParseMoveOption(string moveOption);

class Room : public Entity
{
public:
	//Room();
	Room(const string& name, const string& description);
	~Room();
	void Setup();
	void SetNeighbors(Room* ptrNorth, Room* ptrSouth, Room* ptrEast, Room* ptrWest);
	bool CanMove(MoveOptions move);
	Room* Move(MoveOptions move);

	bool CanContainEntities() const override;
	string GetInformation() const override;
	string GetNeighbors() const;

private:
	Room* ptrNeighborNorth;
	Room* ptrNeighborSouth;
	Room* ptrNeighborEast;
	Room* ptrNeighborWest;
};

#endif // !ROOM_H