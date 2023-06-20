#include "Player.h"

Player::Player(string name, string description, Room* currentRoom) :
	Creature(name, description, currentRoom)
{
	this->entityType = EntityType::PLAYER;
}

bool Player::CanMove(MoveOptions move) {
	return currentRoom->CanMove(move);
}

void Player::Move(MoveOptions move) {
	currentRoom = currentRoom->Move(move);
}