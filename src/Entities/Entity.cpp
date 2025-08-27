#include "Entities/Entity.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/SpriteComponent.hpp"
entt::entity Entity::CreatePlayer(entt::registry& registry)
{
	auto entity = registry.create(); // create entity
	registry.emplace<InputComponent>(entity); // add component to entity
	registry.emplace<TransformComponent>(entity);
	registry.emplace<SpriteComponent>(entity, "Castle");
	return entity;
}
