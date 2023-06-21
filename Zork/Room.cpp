#include "Room.h"

Room::Room(const string& name = string(), const string& description = string()) :
	Entity(name, description, nullptr)
{
	Setup();
}

Room::~Room() {

}

void Room::Setup() {
	entityType = EntityType::ROOM;

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

string Room::GetNeighbors() {
	ostringstream oss;

	oss << "From " << name << " you can go to: ";
	if (ptrNeighborNorth != nullptr) { oss << "\n\t- North"; }
	if (ptrNeighborSouth != nullptr) { oss << "\n\t- South"; }
	if (ptrNeighborEast != nullptr) { oss << "\n\t- East"; }
	if (ptrNeighborWest != nullptr) { oss << "\n\t- West"; }

	return oss.str();
}

bool Room::CanMove(MoveOptions move) {
	return (move == MoveOptions::NORTH && ptrNeighborNorth != nullptr)
		|| (move == MoveOptions::SOUTH && ptrNeighborSouth != nullptr)
		|| (move == MoveOptions::EAST && ptrNeighborEast != nullptr)
		|| (move == MoveOptions::WEST && ptrNeighborWest != nullptr);
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

bool Room::CanContainEntities() const {
	return true;
}

string Room::GetInformation() const {
	ostringstream oss;

	oss << "Room " << name << ": " << description;
	if (contains.size() > 0) {
		oss << "\n\tContains entities:";
		for (Entity* e : contains) {
			oss << "\n\t- " << e->GetName();
		}
	}

	return oss.str();
}

string Room::GetContainsEntitiesInfo() const {
	return ""; // TODO
}

// Global enum class conversions
MoveOptions ParseMoveOption(string moveOption) {
	if (Equals(moveOption, "north") || Equals(moveOption, "n")) {
		return MoveOptions::NORTH;
	}
	else if (Equals(moveOption, "south") || Equals(moveOption, "s")) {
		return MoveOptions::SOUTH;
	}
	else if (Equals(moveOption, "east") || Equals(moveOption, "e")) {
		return MoveOptions::EAST;
	}
	else if (Equals(moveOption, "west") || Equals(moveOption, "w")) {
		return MoveOptions::WEST;
	}
	else {
		return MoveOptions::NORTH;
	}
}

string ToStringMoveOption(MoveOptions moveOption) {
	if (moveOption == MoveOptions::NORTH) {
		return "north";
	}
	else if (moveOption == MoveOptions::SOUTH) {
		return "south";
	}
	else if (moveOption == MoveOptions::EAST) {
		return "east";
	}
	else if (moveOption == MoveOptions::WEST) {
		return "west";
	}
	else {
		return "";
	}
}
