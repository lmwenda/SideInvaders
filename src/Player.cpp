#include "Player.h"
#include <SFML/Graphics.hpp>

Player::Player() : player(){
	player.setSize(sf::Vector2f(50, 50));
	player.setFillColor(sf::Color::Blue);
	player.setPosition(sf::Vector2f(50.0, 270.0));
}


void Player::Blitz(sf::RenderWindow &window)
{
	window.draw(this->player);
}


void Player::Controls()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		this->player.move(sf::Vector2f(0, 5));
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		this->player.move(sf::Vector2f(0, -5));
	}
}

sf::FloatRect Player::getPlayerBounds() const{
    sf::FloatRect b_player = this->player.getGlobalBounds();

    return b_player;
}
