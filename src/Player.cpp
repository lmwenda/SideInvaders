#include "Player.h"
#include <SFML/Graphics.hpp>

Player::Player() : player(){
	player.setSize(sf::Vector2f(50, 50));
	player.setFillColor(sf::Color::Blue);
	player.setPosition(50, 270);
}


void Player::Blitz(sf::RenderWindow &window)
{
	window.draw(this->player);
}


void Player::Controls()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->player.move(0, 5);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->player.move(0, -5);
	}
}
