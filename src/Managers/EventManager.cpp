#include "Managers/EventManager.hpp"

// EventMap
EventMap::EventMap(bool useBuiltinHelpers) 
    : m_keyPressedManager([](const sf::Event& event) { return event.key.code; })
    , m_keyReleasedManager([](const sf::Event& event) { return event.key.code; })
    , m_mousePressedManager([](const sf::Event& event) { return event.mouseButton.button; })
    , m_mouseReleasedManager([](const sf::Event& event) { return event.mouseButton.button; })
{
    if (useBuiltinHelpers) 
    {
        this->AddEventCallback(sf::Event::EventType::KeyPressed, [&](const sf::Event& event) {m_keyPressedManager.HandleEvents(event); });
        this->AddEventCallback(sf::Event::EventType::KeyReleased, [&](const sf::Event& event) {m_keyReleasedManager.HandleEvents(event); });
        this->AddEventCallback(sf::Event::EventType::MouseButtonPressed, [&](const sf::Event& event) {m_mousePressedManager.HandleEvents(event); });
        this->AddEventCallback(sf::Event::EventType::MouseButtonReleased, [&](const sf::Event& event) {m_mouseReleasedManager.HandleEvents(event); });
    }
}

void EventMap::AddEventCallback(sf::Event::EventType type, EventCallback callback)
{
    m_EventsCallmap[type] = callback;
}

void EventMap::AddKeyPressedCallback(sf::Keyboard::Key keyCode, EventCallback callback)
{
    m_keyPressedManager.AddCallback(keyCode, callback);
}

void EventMap::AddKeyReleasedCallback(sf::Keyboard::Key keyCode, EventCallback callback)
{
    m_keyReleasedManager.AddCallback(keyCode, callback);
}

void EventMap::AddMousePressedCallback(sf::Mouse::Button button, EventCallback callback)
{
    m_mousePressedManager.AddCallback(button, callback);
}

void EventMap::AddMouseReleasedCallback(sf::Mouse::Button button, EventCallback callback)
{
    m_mouseReleasedManager.AddCallback(button, callback);
}

void EventMap::HandleCallback(const sf::Event& event, EventCallback fallback)
{
    auto it = m_EventsCallmap.find(event.type);
    if (it != m_EventsCallmap.end())
    {
        (it->second)(event);
    }
    else if (fallback)
    {
        fallback(event);
    }
}

void EventMap::RemoveCallback(sf::Event::EventType type)
{
    auto it = m_EventsCallmap.find(type);
    if (it != m_EventsCallmap.end())
    {
        m_EventsCallmap.erase(it);
    }
}

// EventManager
void EventManager::HandleEvents(sf::RenderWindow& window, EventCallback fallback)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        m_eventMap.HandleCallback(event, fallback);
    }
}

void EventManager::AddEventCallback(sf::Event::EventType type, EventCallback callback)
{
    m_eventMap.AddEventCallback(type, callback);
}

void EventManager::RemoveEventCallback(sf::Event::EventType type)
{
    m_eventMap.RemoveCallback(type);
}

void EventManager::AddKeyPressedCallback(sf::Keyboard::Key key, EventCallback callback)
{
    m_eventMap.AddKeyPressedCallback(key, callback);
}

void EventManager::AddKeyReleasedCallback(sf::Keyboard::Key key, EventCallback callback)
{
    m_eventMap.AddKeyReleasedCallback(key, callback);
}

void EventManager::AddMousePressedCallback(sf::Mouse::Button button, EventCallback callback)
{
    m_eventMap.AddMousePressedCallback(button, callback);
}

void EventManager::AddMouseReleasedCallback(sf::Mouse::Button button, EventCallback callback)
{
    m_eventMap.AddMouseReleasedCallback(button, callback);
}