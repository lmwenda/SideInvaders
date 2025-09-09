#include "EnemyManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include <SFML/Graphics.hpp>


EnemyManager::EnemyManager() : m_spawnInterval(sf::seconds(2)){}

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

void EnemyManager::destroyAll(){
    std::cout << "Cleared Enemy Vector" << std::endl;
    Enemies.clear();
}

void EnemyManager::checkPlayerCollision(const Player &player, GameState &current_State){
    for(auto& enemy : Enemies)
    {
        if(enemy.getEnemyBounds().intersects(player.getPlayerBounds()))
        {
            std::cout << "Player Collisioned with Enemy" << std::endl;
            current_State = GameState::DEAD;
        }
    }
};

void EnemyManager::Blitz(sf::RenderWindow &window){
    for (auto& enemy : Enemies)
    {
       enemy.Blitz(window);
    }

};


