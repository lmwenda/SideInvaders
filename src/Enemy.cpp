#include "Enemy.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int RandomIntegerX(){
    int number = std::rand()%(900-800+1)+800;

    return number;
}

Enemy::Enemy() : enemy(){
    int posX = RandomIntegerX();
	enemy.setSize(sf::Vector2f(50, 50));
	enemy.setFillColor(sf::Color::Red);
	enemy.setPosition(posX, 270);
}


void Enemy::Blitz(sf::RenderWindow &window)
{
	window.draw(this->enemy);
}

