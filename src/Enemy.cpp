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

Enemy::Enemy(){
    int posX = RandomIntegerX();
    int posY = RandomIntegerY();

    if (!Enemy::texture.loadFromFile("assets/asteroid.png")) {
        std::cerr << "Error: Failed to load enemy texture from 'enemy.png'\n";
    }

    this->enemy.setTexture(Enemy::texture);
	this->enemy.setPosition(posX, posY);
    this->enemy.setScale(0.f, 0.f);
}

void Enemy::Move(){
    this->enemy.move(-10,0);
}

bool Enemy::isOffScreen() const {
    return this->enemy.getPosition().x + this->enemy.getGlobalBounds().width< 0;
}

void Enemy::Blitz(sf::RenderWindow &window){
    window.draw(this->enemy);
}

sf::FloatRect Enemy::getEnemyBounds() const{
    // sf::FloatRect b_enemy = this->enemy.getGlobalBounds();

    return this->enemy.getGlobalBounds();;
}


