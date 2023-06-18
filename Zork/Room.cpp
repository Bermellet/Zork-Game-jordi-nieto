#include "Room.h"

Room::Room(const string& name /*= string()*/, const string& description /*= string()*/) :
Entity(name, description) {
	Setup();
}

Room::~Room() {

}

void Room::Setup() {
	type = ROOM;

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
