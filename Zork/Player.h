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
	string Move(MoveOptions move);
	string Move(string move);

private:

};


#endif // !PLAYER_H