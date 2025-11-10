#include "Enemy.h"
#include <iostream>
#include <SFML/Graphics.hpp>

sf::Texture Enemy::texture;

int RandomIntegerX(){
    int number = std::rand()%(900-800+1)+800;

    return number;
}

int RandomIntegerY()
{
    int number = std::rand()%500;

    return number;
}

Enemy::Enemy() :asteroid(Enemy::texture){
    int posX = RandomIntegerX();
    int posY = RandomIntegerY();

    if (!Enemy::texture.loadFromFile("assets/asteroid.png")) {
        std::cerr << "Error: Failed to load enemy texture from 'enemy.png'\n";
    }

    this->asteroid.setTexture(Enemy::texture);
	this->asteroid.setPosition(sf::Vector2f(posX, posY));
    this->asteroid.setScale(sf::Vector2f(0.5f, 0.5f));
}

void Enemy::Move(){
    this->asteroid.move(sf::Vector2f(-10,0));
}

bool Enemy::isOffScreen() const {
    return this->asteroid.getPosition().x + this->asteroid.getGlobalBounds().position.x < 0;
}

void Enemy::Blitz(sf::RenderWindow &window){
    window.draw(this->asteroid);
}

sf::FloatRect Enemy::getEnemyBounds() const{
    // sf::FloatRect b_enemy = this->enemy.getGlobalBounds();

    return this->asteroid.getGlobalBounds();
}


