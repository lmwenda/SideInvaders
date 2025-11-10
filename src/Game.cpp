#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Event.hpp>

#include "Game.h"
#include "Player.h"
#include "EnemyManager.h"

Game::Game() : window(sf::VideoMode(sf::Vector2u(800, 600)), "Side Invaders"), backgroundTexture("assets/Background.png"), backgroundSprite(backgroundTexture), enemy_manager(){	
	window.setFramerateLimit(60);

    sf::FloatRect spriteBounds = backgroundSprite.getLocalBounds();

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(sf::Vector2f(0, 0));
    backgroundSprite.setScale(
        sf::Vector2f(
            static_cast<float>(window.getSize().x) / spriteBounds.size.x,
            static_cast<float>(window.getSize().y) / spriteBounds.size.y
        )
    );

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
    font.openFromFile("assets/arial.ttf"); // make sure this path is correct

    sf::Text menuText(font, "Press Space to Start", 32);
    menuText.setFillColor(sf::Color::White);
    menuText.setPosition(sf::Vector2f(200.0f, 300.0f));


    window.draw(menuText);
}

void Game::Dead(sf::RenderWindow &window)
{
    sf::Font font;
    font.openFromFile("assets/arial.ttf"); // make sure this path is correct

    sf::Text menuText(font, "YOU DIED...", 32);
    menuText.setFillColor(sf::Color::Red);
    menuText.setPosition(sf::Vector2f(250.0f, 300.0f));
    
    std::string pp_str = std::to_string(this->player_points);
    std::string message = "Your Points: " + pp_str;
    sf::Text pointText(font, message, 32); 
    pointText.setFillColor(sf::Color::White);
    pointText.setPosition(sf::Vector2f(250.0f, 400.0f));

    window.draw(menuText);
    window.draw(pointText);
}

void Game::ProcessEvents(){
	while(auto event = window.pollEvent()){

		if(event->is<sf::Event::Closed>())
			window.close();
            std::cout << this->player_points << std::endl;

        if(this->current_State == GameState::MAINMENU){
            if (auto keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if(keyPressed->code == sf::Keyboard::Key::Space){
                    this->current_State = GameState::GAME;
                }
            }
        }

        if(this->current_State == GameState::DEAD){
            enemy_manager.destroyAll();
            if(auto keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if(keyPressed->code == sf::Keyboard::Key::Space)
                {
                    this->current_State = GameState::MAINMENU;
                    this->player_points = 0;
                }
            }
        }
	}
}


void Game::Update(){
    // Update Game Logic
    if(this->current_State == GameState::GAME){
        player.Controls();
        enemy_manager.Update(deltaTime);
        enemy_manager.checkPlayerCollision(player, this->current_State);
    }

    if (clock.getElapsedTime().asSeconds() >= point_time && this->current_State == GameState::GAME)
    {
        this->player_points = this->player_points + 10;
        this->point_time = this->point_time + 2.50;
        std::cout << "Player Points: " << this->player_points << std::endl;
    }

    std::cout << clock.getElapsedTime().asSeconds() << std::endl;

}

void Game::Render(){
    window.clear();
    window.draw(backgroundSprite);

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
