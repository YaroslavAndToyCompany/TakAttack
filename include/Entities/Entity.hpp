#include "Components/InputComponent.hpp"
#include <entt/entt.hpp>
#include "Managers/ResourceManager.hpp"

namespace Entity {
	entt::entity CreatePlayer(ResourceManager& resManager, entt::registry& registry);
}

namespace Entity 
{
	entt::entity CreateArtillery(ResourceManager& resManager, entt::registry& registry);
} 




