#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <array>
#include <memory>
#include "UI/View.hpp"
#include "UI/Widgets/CheckBox.hpp"
#include "Managers/ResourceManager.hpp"

class Debug {
public:
    Debug(const Debug&) = delete;
    Debug& operator=(const Debug&) = delete;

    static void Init(ResourceManager& resourceManager);
    static Debug& GetInstance();

    void AddText(const std::string& text);
    void AddText(const int& number);

    template<typename T>
    void AddText(const sf::Vector2<T>& vec);

    void OnMove();

    void AddCheckBox(ResourceManager& resManager, bool state = false, const std::string& text = "Text");
    void ToggleActive() { m_isActive = !m_isActive; }
    void ToggleMoving() { m_isMoving = !m_isMoving; }
    
    bool IsCursorSetted() { return m_isCursorSetted; }

    void UpdateCursor(const sf::Vector2f& mousePos, sf::RenderWindow& window);

    void HandleEvents(sf::Event& event, sf::RenderWindow& window);
    void Update(sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);

private:
    enum class ResizeSideType {
        Top, Bottom, Left, Right, Count
    };

    Debug(ResourceManager& resourceManager);
    void CreatePanel(const sf::Vector2f& size, int leftMargin, int topMargin);
    void CreateResizeHandlers(sf::RectangleShape& side, const sf::Vector2f& size, ResizeSideType sideType);
    void UpdateResizeHandlers(sf::RectangleShape& side, ResizeSideType sideType);

    sf::RectangleShape m_panel;

    std::array<sf::RectangleShape, static_cast<size_t>(ResizeSideType::Count)> m_resizeSides;

    sf::Text m_text;
    std::unique_ptr<CheckBox> m_checkBox;

    bool m_isActive;
    bool m_isMoving;
    bool m_isCursorSetted;

    static std::unique_ptr<Debug> s_instance;
    static bool s_isInitialized;
};

template<typename T>
void Debug::AddText(const sf::Vector2<T>& vec)
{
    AddText(std::to_string(vec.x) + ", " + std::to_string(vec.y));
}