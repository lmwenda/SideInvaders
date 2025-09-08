#include "EnemyManager.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>


EnemyManager::EnemyManager() : m_spawnInterval(sf::seconds(2)){

}

void EnemyManager::Update(sf::Time deltaTime){
    if(m_spawnClock.getElapsedTime() >= m_spawnInterval){
        if(Enemies.size() < 5){
            Enemy newenemy;

            Enemies.push_back(newenemy);
        }
    }

    Enemies.erase(
        std::remove_if(Enemies.begin(), Enemies.end(), [](const Enemy& e) {
            return e.isOffScreen();
        }),
        Enemies.end()
    );
    for (auto& enemy : Enemies)
    {
        enemy.Move();
    }

};


void EnemyManager::Blitz(sf::RenderWindow &window){
    for (auto& enemy : Enemies)
    {
       enemy.Blitz(window);
    }

}
