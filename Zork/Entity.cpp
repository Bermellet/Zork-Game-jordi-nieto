#include "Entity.h"

Entity::Entity(const string& name /*= string()*/, const string& description /*= string()*/) :
	name(name), description(description) {
	type = ITEM;
}

Entity::~Entity() {

}
