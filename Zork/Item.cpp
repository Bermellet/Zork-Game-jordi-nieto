#include "Item.h"

Item::Item(string name, string description, Entity* containedBy, ItemType itemType) :
	Entity(name, description, containedBy)
{
	this->entityType = EntityType::ITEM;
	this->itemType = itemType;
}

Item::~Item() {

}

bool Item::CanBePicked() const {
	return true;
}

bool Item::IsContainer() const {
	return this->itemType == ItemType::CONTAINER;
}

string Item::Use(Player* player, World* world) {
	if (itemType == ItemType::ITEM) {
		if (name == "torch") {
			return "You use the torch. Now the path is a lot brighter.";
		}
		else if (name == "potion") {
			string creatureStatue = "creature statue";
			if (player->GetCurrentRoom()->ContainsEntity(creatureStatue)) {
				Entity* e = player->GetCurrentRoom()->FindEntity(creatureStatue);
				if (e->GetType() == EntityType::CREATURE) {
					Creature* creature = static_cast<Creature*>(e);
					Creature* phoenix = new Creature("phoenix", "A beautiful bird with bright colors. Its feathers seems alive, showing a fire-like pattern", creature->GetCurrentRoom());
					creature->GetCurrentRoom()->RemoveEntity(creature);
					delete(creature);
					
					// End game
					world->SetFinished(true);
					ostringstream oss;
					oss << "Your drop the potion's contents on the stone statue. Suddenly the statue begins to crack."
						<< "\nStarting from its head, the cracks begin to shine as the effect expands through the whole statue."
						<< "\nSuperficial stone pieces fall apart from the statue, showing a truly alive bird."
						<< "\n You found the " << phoenix->GetName() << " - " << phoenix->GetDescription()
						<< "\n\nThe creature slowly approaches you, half unsure, half thankful."
						<< "\nYou stretch you hand towards the bird. Its touch creates an impulse through all your body."
						<< "\n\n\tNow... Now you remember";
					return oss.str();
				}
			}

			// Item used
			player->RemoveEntity(this);
			delete(this);
		}
	}
}