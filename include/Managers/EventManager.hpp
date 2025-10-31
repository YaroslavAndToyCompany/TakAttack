#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

using EventCallback = std::function<void(const sf::Event& event)>;

template <typename T>
class SubTypeEventManager
{
public:
    SubTypeEventManager(std::function<T(const sf::Event&)> unpacker)
        : m_unpacker(unpacker)
    {}

    void HandleEvents(const sf::Event& event);
    void AddCallback(const T& subType, EventCallback callback);
private:
    std::function<T(const sf::Event&)> m_unpacker;
    std::unordered_map<T, EventCallback> m_callmap;
};

template <typename T>
void SubTypeEventManager<T>::HandleEvents(const sf::Event& event)
{
    T subType = m_unpacker(event);
    auto it = m_callmap.find(subType);
    if (it != m_callmap.end())
    {
        (it->second)(event);
    }
}

template <typename T>
void SubTypeEventManager<T>::AddCallback(const T& subType, EventCallback callback)
{
    m_callmap[subType] = callback;
}

class EventMap
{
public:
    EventMap(bool useBuiltinHelpers);

    void AddEventCallback(sf::Event::EventType type, EventCallback callback);
    void AddKeyPressedCallback(sf::Keyboard::Key keyCode, EventCallback callback);
    void AddKeyReleasedCallback(sf::Keyboard::Key keyCode, EventCallback callback);
    void AddMousePressedCallback(sf::Mouse::Button button, EventCallback callback);
    void AddMouseReleasedCallback(sf::Mouse::Button button, EventCallback callback);

    void HandleCallback(const sf::Event& event, EventCallback fallback = nullptr);
    void RemoveCallback(sf::Event::EventType type);

private:
    SubTypeEventManager<sf::Keyboard::Key> m_keyPressedManager;
    SubTypeEventManager<sf::Keyboard::Key> m_keyReleasedManager;
    SubTypeEventManager<sf::Mouse::Button> m_mousePressedManager;
    SubTypeEventManager<sf::Mouse::Button> m_mouseReleasedManager;
    std::unordered_map<sf::Event::EventType, EventCallback> m_EventsCallmap;
};

class EventManager
{
public:
    EventManager(bool useBuiltinHelpers = true)
        : m_eventMap(useBuiltinHelpers)
    {}

    void HandleEvents(sf::RenderWindow& window, EventCallback fallback = nullptr);

    void AddEventCallback(sf::Event::EventType type, EventCallback callback);
    void RemoveEventCallback(sf::Event::EventType type);

    void AddKeyPressedCallback(sf::Keyboard::Key key, EventCallback callback);
    void AddKeyReleasedCallback(sf::Keyboard::Key key, EventCallback callback);
    void AddMousePressedCallback(sf::Mouse::Button button, EventCallback callback);
    void AddMouseReleasedCallback(sf::Mouse::Button button, EventCallback callback);

private:
    EventMap m_eventMap;
};