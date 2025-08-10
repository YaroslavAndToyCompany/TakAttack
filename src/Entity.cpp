#include "Entity.h"

entt::entity Entity::CreatePlayer(entt::registry& registry)
{
	auto entity = registry.create(); // create entity
	registry.emplace<InputComponent>(entity); // add component to entity
	return entity;
}
