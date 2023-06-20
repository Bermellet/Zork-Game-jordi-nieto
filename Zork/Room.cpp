#include "Room.h"

Room::Room(const string& name = string(), const string& description = string()) :
	Entity(name, description, nullptr)
{
	Setup();
}

Room::~Room() {

}

void Room::Setup() {
	type = EntityType::ROOM;

	ptrNeighborNorth = nullptr;
	ptrNeighborSouth = nullptr;
	ptrNeighborEast = nullptr;
	ptrNeighborWest = nullptr;
}

void Room::SetNeighbors(Room* ptrNorth, Room* ptrSouth, Room* ptrEast, Room* ptrWest) {
	ptrNeighborNorth = ptrNorth;
	ptrNeighborSouth = ptrSouth;
	ptrNeighborEast = ptrEast;
	ptrNeighborWest = ptrWest;
}

void Room::OutputNeighbors() {
	cout << "From " << name << " you can go to: ";
	if (ptrNeighborNorth != nullptr) { cout << "\n\t- North"; }
	if (ptrNeighborSouth != nullptr) { cout << "\n\t- South"; }
	if (ptrNeighborEast != nullptr) { cout << "\n\t- East"; }
	if (ptrNeighborWest != nullptr) { cout << "\n\t- West"; }
	cout << endl;
}

bool Room::CanMove(MoveOptions move) {
	if (move == MoveOptions::NORTH && ptrNeighborNorth != nullptr) {
		return true;
	}
	if (move == MoveOptions::SOUTH && ptrNeighborSouth != nullptr) {
		return true;
	}
	if (move == MoveOptions::EAST && ptrNeighborEast != nullptr) {
		return true;
	}
	if (move == MoveOptions::WEST && ptrNeighborWest != nullptr) {
		return true;
	}
	return false;
}

Room* Room::Move(MoveOptions move) {
	if (move == MoveOptions::NORTH) {
		return ptrNeighborNorth;
	}
	if (move == MoveOptions::SOUTH) {
		return ptrNeighborSouth;
	}
	if (move == MoveOptions::EAST) {
		return ptrNeighborEast;
	}
	if (move == MoveOptions::WEST) {
		return ptrNeighborWest;
	}
	return nullptr;
}