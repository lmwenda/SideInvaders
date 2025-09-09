#pragma once
#include <SFML/Graphics.hpp>


class Enemy{

	public:
		Enemy();
        void Blitz(sf::RenderWindow &window);
        void Move();
        bool isOffScreen() const;
        sf::FloatRect getEnemyBounds() const;

	private:
		//sf::RectangleShape enemy;
        static sf::Texture texture;
        sf::Sprite enemy;
 
        int posX;
        int posY;
		
};
