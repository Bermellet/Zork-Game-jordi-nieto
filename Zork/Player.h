#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Room.h"

class Player
{
public:
	Player();
	~Player();

private:
	Room* currentRoom;

};


#endif // !PLAYER_H