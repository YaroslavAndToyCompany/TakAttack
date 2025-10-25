#include "Entities/Entity.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/CastleUIComponent.hpp"
entt::entity Entity::CreatePlayer(ResourceManager& resManager, entt::registry& registry)
{
	auto entity = registry.create(); // create entity
	registry.emplace<InputComponent>(entity); // add component to entity
	registry.emplace<TransformComponent>(entity, sf::Vector2f(90.0f, -50.0f), sf::Vector2f(0.1f, 0.1f)); // DONT TOUCH THIS PIECE OF SHIT
	registry.emplace<SpriteComponent>(entity, "Castle", resManager);
	registry.emplace<CastleUIComponent>(entity);
	return entity;
}

entt::entity Entity::CreateArtillery(ResourceManager& resManager, entt::registry& registry)
{
	auto entity = registry.create();
	registry.emplace<TransformComponent>(entity, sf::Vector2f(82.0f, 32.0f), sf::Vector2f(0.05f, 0.05f)); // DONT TOUCH THIS PIECE OF SHIT
	registry.emplace<SpriteComponent>(entity, "Artillery", resManager);
	registry.emplace<CastleUIComponent>(entity);
	return entity;
}
