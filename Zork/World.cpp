#include "World.h"

World::World() {
	SetupWorld();
}

World::~World() {

}

string World::Run(vector<string>& actions) {
	if (Equals(actions.front(), "north")) {
		if (player->CanMove(MoveOptions::NORTH)) {
			player->Move(MoveOptions::NORTH);
		}
		else {
			return "You cannot move North";
		}
	}
	else if (Equals(actions.front(), "south")) {
		if (player->CanMove(MoveOptions::SOUTH)) {
			player->Move(MoveOptions::SOUTH);
		}
		else {
			return "You cannot move South";
		}
	}
	else if (Equals(actions.front(), "east")) {
		if (player->CanMove(MoveOptions::EAST)) {
			player->Move(MoveOptions::EAST);
		}
		else {
			return "You cannot move East";
		}
	}
	else if (Equals(actions.front(), "west")) {
		if (player->CanMove(MoveOptions::WEST)) {
			player->Move(MoveOptions::WEST);
		}
		else {
			return "You cannot move West";
		}
	}

	actions.erase(actions.begin());
	return "";
}

void World::SetupWorld() {
	// Rooms
	Room* room1 = new Room("Forest clearing", "");
	Room* room2 = new Room("Flower path", "");
	Room* room3 = new Room("Rocky cliff", "");
	Room* room4 = new Room("Old campsite", "");
	Room* room5 = new Room("Forest", "");
	Room* room6 = new Room("Cave entrance", "");
	Room* room7 = new Room("Stalactites room", "");
	Room* room8 = new Room("Boss room", "");

	room1->SetNeighbors(nullptr, room2, nullptr, nullptr);
	room2->SetNeighbors(room1, room5, nullptr, room3);
	room3->SetNeighbors(nullptr, room4, room2, nullptr);
	room4->SetNeighbors(room3, nullptr, room5, nullptr);
	room5->SetNeighbors(room2, nullptr, room6, room4);
	room6->SetNeighbors(nullptr, nullptr, room7, room5);
	room7->SetNeighbors(nullptr, room8, nullptr, room6);
	room8->SetNeighbors(room7, nullptr, nullptr, nullptr);

	entities.push_back(room1);
	entities.push_back(room2);
	entities.push_back(room3);
	entities.push_back(room4);
	entities.push_back(room5);
	entities.push_back(room6);
	entities.push_back(room7);
	entities.push_back(room8);

	// Player
	player = new Player(room1);

	// Items

}