#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Room.h"

class Player : public Creature
{
public:
	Player(string name, string description, Room* currentRoom);

	bool CanMove(MoveOptions move);
	void Move(MoveOptions move);

private:

};


#endif // !PLAYER_H