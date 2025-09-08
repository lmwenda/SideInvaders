#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"
#include "Enemy.h"

Game::Game() : window(sf::VideoMode(800,600), "Side Invaders"), player(), enemy(){	
	window.setFramerateLimit(60);
}

void Game::Run(){
	// Everything in this loop runs every frame
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


    /*
    std::vector<Enemy> enemies;
    
    if (enemies.size() < 5){
        Enemy enemy;
        enemies.push_back(enemy);
    } */



}

void Game::Render(){
    window.clear();

    player.Blitz(window);

    /* 
    for(int i=0; i < enemies.size(); i++)
    {
        enemy.Blitz(window);
    }

    */
    window.display();
}
