#include "World.h"

World::World() {
	this->_finished = false;
	this->_gameOver = false;

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
	size_t i = 0;
	string action = actions[i];
	string status = "Sorry, I could not understand you";

	if (!IsValidCommand(action)) {
		status = "Unknown action. You can see the options with: help";
	}
	else {
		if (Equals(action, "help")) {
			status = BuildHelp();
		}
		// Verb actions
		else if (IsCommandActions(action) && actions.size() > i+1) {
			string next_action = actions[++i];

			if (Equals(action, "move") || Equals(action, "go")) {
				if (IsCommandMovement(next_action)) {
					status = player->Move(next_action);
				}
			}
			else if (Equals(action, "look")) {
				if (Equals(next_action, "room") || Equals(next_action, "around")) {
					status = player->GetCurrentRoom()->GetInformation();
				}
				else if (Equals(next_action, "path") || Equals(next_action, "paths")) {
					status = player->GetCurrentRoom()->GetNeighbors();
				}
				else if (Equals(next_action, "inventory") || Equals(next_action, "items")) {
					status = player->GetInventoryItemsNames();
				}
				// room objects
				else if (player->GetCurrentRoom()->ContainsEntity(next_action)) {
					Entity* e = (player->GetCurrentRoom()->FindEntity(next_action));
					status = e->GetInformation();
				}
				// inventory
				else if (player->ContainsEntity(next_action)) {
					Entity* e = (player->FindEntity(next_action));
					status = e->GetInformation();
				}
			}
			else if (Equals(action, "open")) {
				if (Equals(next_action, "inventory") || Equals(next_action, "items")) {
					status = player->GetInventoryItemsNames();
				}
				else if (Equals(next_action, "chest")) {
					if (player->GetCurrentRoom()->ContainsEntity(next_action)) {
						Entity* e = (player->GetCurrentRoom()->FindEntity(next_action));
						if (e->GetType() == EntityType::ITEM) {
							Item* item = static_cast<Item*>(e);
							if (item->itemType == ItemType::CONTAINER) {
								Chest* chest = static_cast<Chest*>(item);
								status = chest->GetInformation();
							}
						}
					}
					else {
						status = "The current room doesn't contain " + next_action;
					}
				}
			}
			else if (Equals(action, "use")) {
				if (player->ContainsEntity(next_action)) {
					Entity* e = (player->FindEntity(next_action));
					if (e->GetType() == EntityType::ITEM) {
						Item* item = static_cast<Item*>(e);
						status = item->Use(player, this);
					}
				}
				else {
					status = "Could not find the specified item: " + next_action;
				}
			}
			else if (Equals(action, "pick") || Equals(action, "take")) {
				if (Equals(next_action, "items")) {
					if (actions.size() > i + 2) {
						string action3 = actions[++i], action4 = actions[++i];
						if (Equals(action3, "from") && Equals(action4, "chest")) {
							if (player->GetCurrentRoom()->ContainsEntity(action4)) {
								Entity* e = (player->GetCurrentRoom()->FindEntity(action4));
								if (e->GetType() == EntityType::ITEM) {
									Item* item = static_cast<Item*>(e);
									if (item->itemType == ItemType::CONTAINER) {
										Chest* chest = static_cast<Chest*>(item);
										status = chest->PickContents(player);
									}
								}
							}
							else {
								status = "The current room doesn't contain " + action4;
							}
						}
					}
				}
				else if (player->GetCurrentRoom()->ContainsEntity(next_action)) {
					Entity* e = (player->GetCurrentRoom()->FindEntity(next_action));
					if (e->GetType() == EntityType::ITEM) {
						Item* item = static_cast<Item*>(e);
						player->Pick(item);
						status = "";
					}
					else {
						status = "Could not find the specified item: " + next_action;
					}
				}
			}
			else if (Equals(action, "drop")) {
				if (player->ContainsEntity(next_action)) {
					Entity* e = (player->FindEntity(next_action));
					if (e->GetType() == EntityType::ITEM) {
						Item* item = static_cast<Item*>(e);
						if (actions.size() > i + 2) {
							string action3 = actions[++i], action4 = actions[++i];
							if (Equals(action3, "in") && Equals(action4, "chest")) {
								if (player->GetCurrentRoom()->ContainsEntity(action4)) {
									Entity* e = (player->GetCurrentRoom()->FindEntity(action4));
									if (e->GetType() == EntityType::ITEM) {
										Item* item = static_cast<Item*>(e);
										if (item->itemType == ItemType::CONTAINER) {
											Chest* chest = static_cast<Chest*>(item);
											chest->AddEntity(item);
											status = "";
										}
									}
								}
								else {
									status = "The current room doesn't contain " + action4;
								}
							}
							else {
								player->Drop(item);
								status = "";
							}
						}
						else {
							player->Drop(item);
							status = "";
						}
					}
				}
				else {
					status = "Could not find the specified item: " + next_action;
				}
			}
		}

		// Entities
		else if (IsCommandMovement(action)) {
			status = player->Move(action);
		}
		else if (Equals(action, "room") || Equals(action, "around") || Equals(action, "look")) {
			status = player->GetCurrentRoom()->GetInformation();
		}
		else if (Equals(action, "path") || Equals(action, "paths")) {
			status = player->GetCurrentRoom()->GetNeighbors();
		}
		else if (Equals(action, "inventory") || Equals(action, "items")) {
			status = player->GetInventoryItemsNames();
		}
		// room objects
		else if (player->GetCurrentRoom()->ContainsEntity(action)) {
			Entity* e = (player->GetCurrentRoom()->FindEntity(action));
			status = e->GetInformation();
		}
		// inventory
		else if (player->ContainsEntity(action)) {
			Entity* e = (player->FindEntity(action));
			status = e->GetInformation();
		}
	}

	return status;
}

void World::SetupWorld() {
	// Actions list
	commandActions = {"help", "move", "go", "look", "open", "use", "pick", "take", "drop"};
	commandObjectives = {"room", "around", "path", "paths", "inventory", "items"};
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
	Creature* stoneCreature = new Creature("creature statue", "A strange statue of a creature resembling a big bird. You can feel the piercing gaze on its eyes", room8);
	
	// Items
	Chest* chest1 = new Chest("chest", "An ancient wooden chest. It's a miracle it has survived, given its poor condition", room4);
	Item* item1 = new Item("potion", "A potion with yellow glow. Its label is mangled but you can read something abou stone", chest1, ItemType::ITEM);
	Item* item2 = new Item("torch", "A burning torch. Useful to brighten up your path", room6, ItemType::ITEM);

	// Story?

	vector<string> v{ "around" };
	cout << "\n" << Run(v) << "\n";
}

string World::BuildHelp() {
	ostringstream oss;

	oss << "Commands that can be executed:";

	return oss.str();
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

void World::SetFinished(bool value) {
	_finished = value;
}

void World::SetGameOver(bool value) {
	_gameOver = value;
}

bool World::finished() const {
	return _finished;
}

bool World::gameOver() const {
	return _gameOver;
}