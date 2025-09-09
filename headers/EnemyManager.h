#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Player.h"

enum class GameState;

class EnemyManager{
    public:
        EnemyManager();
        void Update(sf::Time deltaTime);
        void Blitz(sf::RenderWindow &window);
        void checkPlayerCollision(const Player &player, GameState &current_State);
        void destroyAll();


    private:
        std::vector<Enemy> Enemies;
        sf::Clock m_spawnClock;
        sf::Time m_spawnInterval;
        sf::RenderWindow* m_window; // For drawing enemies

};
