#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Room.h"

class Player
{
public:
	Player();
	Player(Room* room);
	~Player();

	bool CanMove(MoveOptions move);
	void Move(MoveOptions move);

private:
	Room* currentRoom;

};


#endif // !PLAYER_H