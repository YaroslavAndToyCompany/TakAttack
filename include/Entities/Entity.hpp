#include "Components/InputComponent.hpp"
#include <entt/entt.hpp>
#include "Managers/ResourceManager.hpp"
#include "Components/TagComponent.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/CastleUIComponent.hpp"

namespace Entity {
	entt::entity CreatePlayer(ResourceManager& resManager, entt::registry& registry);
}

namespace Entity 
{
	entt::entity CreateArtillery(ResourceManager& resManager, entt::registry& registry);
} 




