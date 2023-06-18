#include "Player.h"

Player::Player() {
	currentRoom = nullptr;
}

Player::Player(Room* room) {
	currentRoom = room;
}

Player::~Player() {

}

bool Player::CanMove(MoveOptions move) {
	return currentRoom->CanMove(move);
}

void Player::Move(MoveOptions move) {
	currentRoom = currentRoom->Move(move);
}