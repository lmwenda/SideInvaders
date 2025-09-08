#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"
#include "EnemyManager.h"

Game::Game() : window(sf::VideoMode(800,600), "Side Invaders"), player(), enemy_manager(){	
	window.setFramerateLimit(60);
}

void Game::Run(){
	// Everything in this loop runs every frame
    

    sf::Clock clock;
    sf::Time deltaTime = clock.restart();
	while (window.isOpen()){

		Game::ProcessEvents();
        Game::Update();
        Game::Render();
	}


}

void Game::ProcessEvents(){
	sf::Event event;
	while(window.pollEvent(event)){
		if(event.type == sf::Event::Closed)
			window.close();
	}
}


void Game::Update(){
    // Update Game Logic
    player.Controls();
    enemy_manager.Update(deltaTime);
   
    std::cout << clock.getElapsedTime().asSeconds() << std::endl;



}

void Game::Render(){
    window.clear();

    player.Blitz(window);
    enemy_manager.Blitz(window);

    window.display();
}
