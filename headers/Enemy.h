#pragma once
#include <SFML/Graphics.hpp>


class Enemy{

	public:
		Enemy();
		void Blitz(sf::RenderWindow &window); // Draw and Render Player Component

	private:
		sf::RectangleShape enemy;
        int posX;
		
};
