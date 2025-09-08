#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class EnemyManager{
    public:
        EnemyManager();
        void Update(sf::Time deltaTime);
        void Blitz(sf::RenderWindow &window);


    private:
        std::vector<Enemy> Enemies;
        sf::Clock m_spawnClock;
        sf::Time m_spawnInterval;
        sf::RenderWindow* m_window; // For drawing enemies

};
