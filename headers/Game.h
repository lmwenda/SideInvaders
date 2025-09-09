#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "EnemyManager.h"

enum class GameState {
   MAINMENU, 
   GAME, 
   PAUSED,
   DEAD 
};


class Game{
	public:
		Game();
		void Run();

	private:
		void ProcessEvents();
        void Update();
        void Render();

        void Menu(sf::RenderWindow &window);
        void Dead(sf::RenderWindow &window);

	private:
		sf::RenderWindow window;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;
 
        Player player;
        EnemyManager enemy_manager;
        GameState current_State;

        int player_points;
        float point_time;
        sf::Clock clock;
        sf::Time deltaTime;
        const unsigned int seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
};
