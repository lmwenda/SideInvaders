#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

class Game{
	public:
		Game();
		void Run();

	private:
		sf::RenderWindow window;
        std::vector<Enemy> enemies;
        Player player;
        Enemy enemy;

        sf::Clock clock;
        const unsigned int seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());

	private:
		void ProcessEvents();
        void Update();
        void Render();
		
};
