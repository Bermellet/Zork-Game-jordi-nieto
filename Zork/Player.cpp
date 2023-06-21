#include "Player.h"

Player::Player(string name, string description, Room* currentRoom) :
	Creature(name, description, currentRoom)
{
	this->entityType = EntityType::PLAYER;
}

bool Player::CanMove(MoveOptions move) {
	return currentRoom->CanMove(move);
}

string Player::Move(MoveOptions move) {
	currentRoom = currentRoom->Move(move);
	return currentRoom->GetInformation();
}

string Player::Move(string move) {
	MoveOptions moveOption = ParseMoveOption(move);
	if (this->CanMove(moveOption)) {
		return this->Move(moveOption);
	}
	else {
		return "You cannot move " + ToStringMoveOption(moveOption);
	}
}