#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"
#include "EnemyManager.h"

Game::Game() : window(sf::VideoMode(800,600), "Side Invaders"), player(), enemy_manager(){	
	window.setFramerateLimit(60);
    this->player_points = 0;
    this->point_time = 5.00;
    this->current_State = GameState::MAINMENU; 
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


void Game::Menu(sf::RenderWindow &window)
{
    sf::Font font;
    font.loadFromFile("assets/arial.ttf"); // make sure this path is correct

    sf::Text menuText;
    menuText.setFont(font);
    menuText.setString("Press Space to Start");
    menuText.setCharacterSize(32);
    menuText.setFillColor(sf::Color::White);
    menuText.setPosition(200.f, 300.f); 


    window.draw(menuText);
}

void Game::Dead(sf::RenderWindow &window)
{
    sf::Font font;
    font.loadFromFile("assets/arial.ttf"); // make sure this path is correct

    sf::Text menuText;
    menuText.setFont(font);
    menuText.setString("YOU DIED..."); 
    menuText.setCharacterSize(32);
    menuText.setFillColor(sf::Color::Red);
    menuText.setPosition(200.f, 300.f);
    
    window.draw(menuText);
}

void Game::ProcessEvents(){
	sf::Event event;
	while(window.pollEvent(event)){

		if(event.type == sf::Event::Closed)
			window.close();
            std::cout << this->player_points << std::endl;

        if(this->current_State == GameState::MAINMENU){
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space){
                    this->current_State = GameState::GAME;
            }
        }
	}
}


void Game::Update(){
    // Update Game Logic
    player.Controls();
    enemy_manager.Update(deltaTime);

    if (clock.getElapsedTime().asSeconds() >= point_time)
    {
        this->player_points = this->player_points + 10;
        this->point_time = this->point_time + 2.50;
        std::cout << "Player Points: " << this->player_points << std::endl;
    }

    std::cout << clock.getElapsedTime().asSeconds() << std::endl;

}

void Game::Render(){
    window.clear();

    if (this->current_State == GameState::MAINMENU){
        Game::Menu(window);
    }

    if(this->current_State == GameState::DEAD){
        Game::Dead(window);
    }

    if (this->current_State == GameState::GAME){
        player.Blitz(window);
        enemy_manager.Blitz(window);
    }

    window.display();
}
