#include "Enemy.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int RandomIntegerX(){
    int number = std::rand()%(900-800+1)+800;

    return number;
}

int RandomIntegerY()
{
    int number = std::rand()%500;

    return number;
}

Enemy::Enemy() : enemy(){
    int posX = RandomIntegerX();
    int posY = RandomIntegerY();
	enemy.setSize(sf::Vector2f(50, 50));
	enemy.setFillColor(sf::Color::Red);
	enemy.setPosition(posX, posY);
}

void Enemy::Move(){
    enemy.move(-10,0);
}

bool Enemy::isOffScreen() const {
    return enemy.getPosition().x + enemy.getSize().x < 0;
}

void Enemy::Blitz(sf::RenderWindow &window){
    window.draw(this->enemy);
}


