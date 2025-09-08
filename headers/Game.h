#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "EnemyManager.h"

class Game{
	public:
		Game();
		void Run();

	private:
		sf::RenderWindow window;
 
        Player player;
        EnemyManager enemy_manager;

        sf::Clock clock;
        sf::Time deltaTime;
        const unsigned int seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());


	private:
		void ProcessEvents();
        void Update();
        void Render();
		
};
