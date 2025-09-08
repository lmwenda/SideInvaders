#pragma once
#include <SFML/Graphics.hpp>


class Enemy{

	public:
		Enemy();
        void Blitz(sf::RenderWindow &window);
        void Move();
        bool isOffScreen() const;

	private:
		sf::RectangleShape enemy;
        int posX;
        int posY;
		
};
