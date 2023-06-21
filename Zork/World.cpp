#include "World.h"

World::World() {
	this->finished = false;
	this->gameOver = false;

	SetupWorld();
}

World::~World() {
	// Free memory
	for (Entity* entity : entities) {
		if (entity != nullptr) {
			delete entity;
		}
	}
	if (player != nullptr) {
		delete player;
	}
}

string World::Run(vector<string>& actions) {
	// TODO: Refactor duplicate code
	string status = "Sorry, I could not understand you";

	//for (string action : actions) {
	/*for (int i = 0; i < actions.size(); i++) {
		string action = actions[i];*/

	//vector<string>::iterator it = actions.begin();
	size_t i = 0;
	string action = actions[i];

		if (!IsValidCommand(action)) {
			status = "Unknown action. You can see the options with: help";
		}
		else {
			if (Equals(action, "help")) {

			}
			// Verb actions
			else if (IsCommandActions(action)) {
				if (actions.size() > i) {
					string next_action = actions[++i];

					if (Equals(action, "move") || Equals(action, "go")) {
						if (IsCommandMovement(next_action)) {
							status = player->Move(next_action);
						}
					}
					else if (Equals(action, "look")) {
						if (Equals(next_action, "room") || Equals(next_action, "around")) {
							status = player->GetCurrentRoom()->GetContainsEntitiesInfo();
						}
						else if (Equals(next_action, "path") || Equals(next_action, "paths")) {
							status = player->GetCurrentRoom()->GetNeighbors();
						}
						else if (Equals(next_action, "inventory") || Equals(next_action, "items")) {
							status = player->GetInventoryItemsNames();
						}
						/*else if (itemname) {
							ITEM_DETAILS
						}*/
					}
					else if (Equals(action, "open")) {
						if (Equals(next_action, "inventory") || Equals(next_action, "items")) {
							status = player->GetInventoryItemsNames();
						}
						else if (Equals(next_action, "chest")) {
							// TODO
						}
					}
					else if (Equals(action, "use")) {
						// TODO: item
					}
					else if (Equals(action, "pick") || Equals(action, "take")) {
						// TODO: item
					}
					else if (Equals(action, "drop")) {
						// TODO: item
					}
				}
			}

			// Entities
			else if (Equals(action, "room") || Equals(action, "around")) {
				status = player->GetCurrentRoom()->GetContainsEntitiesInfo();
			}
			else if (Equals(action, "path") || Equals(action, "paths")) {
				status = player->GetCurrentRoom()->GetNeighbors();
			}
			else if (Equals(action, "inventory") || Equals(action, "items")) {
				status = player->GetInventoryItemsNames();
			}
			/*else if (itemname) {
				ITEM_DETAILS
			}*/
			else if (IsCommandMovement(action)) {
				status = player->Move(action);
			}
		}
	//}

	//actions.erase(actions.begin());
	return status;
}

void World::SetupWorld() {
	// Actions list
	commandActions = {"help", "move", "go", "look", "open", "use", "pick", "take", "drop"};
	commandObjectives = {"room", "around", "path", "paths" "inventory", "items"};
	commandMovements = {"north", "south", "east", "west", "n", "s", "e", "w"};

	// Rooms
	Room* room1 = new Room("Forest clearing", "A sunny clearing covered by trees. You can see a path leading south");
	Room* room2 = new Room("Flower path", "Colorful flowers grow around the path you are following. A crossing divides it into different routes");
	Room* room3 = new Room("Rocky cliff", "Many rockslides have build a precipice that cannot be traversed. You can see a path leading south");
	Room* room4 = new Room("Old campsite", "Camping tents are visibly torn apart, its contents unusable. A chest has survived whatever happened here");
	Room* room5 = new Room("Forest", "Enormous pine trees seem to reach up the sky. There is a cave on the east");
	Room* room6 = new Room("Cave entrance", "The cave is very dark. Luckily, there is a lit torch on the wall");
	Room* room7 = new Room("Stalactites room", "The cave keeps descending into a room full of stalactites. Its humidity reflect dim reflections");
	Room* room8 = new Room("Boss room", "The cave widens into an area full of green moss. Its fluorescent glow constrasts with a stone animal in the center of the room");

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

	// Player & Creatures
	player = new Player("Player", "This is you", room1);
	Creature* stoneCreature = new Creature("Creature statue", "A strange statue of a creature resembling a big bird. You can feel the piercing gaze on its eyes", room8);
	
	// Items
	Chest* chest1 = new Chest("Chest", "An ancient wooden chest. It's a miracle it has survived, given its poor condition", room4);
	Item* item1 = new Item("Yellow potion", "A potion with yellow glow. Its label is mangled but you can read something abou stone", chest1, ItemType::ITEM);
	Item* item2 = new Item("Lit torch", "A burning torch. Useful to brighten up your path", room6, ItemType::ITEM);

	// Story?

}

bool World::IsValidCommand(string& command) {
	return IsCommandActions(command)
		|| IsCommandObjectives(command)
		|| IsCommandMovement(command);
}

bool World::IsCommandActions(string& command) {
	return commandActions.find(command) != commandActions.end();
}

bool World::IsCommandObjectives(string& command) {
	return commandObjectives.find(command) != commandObjectives.end();
}

bool World::IsCommandMovement(string& command) {
	return commandMovements.find(command) != commandMovements.end();
}
