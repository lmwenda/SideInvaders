#pragma once
#include <SFML/Graphics.hpp>


class Player{

	public:
		Player();
		void Controls();
		void Blitz(sf::RenderWindow &window); // Draw and Render Player Component
        sf::FloatRect getPlayerBounds() const;

	private:
		sf::RectangleShape player;
		
};
