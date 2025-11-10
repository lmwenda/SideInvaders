#include <iostream>
#include "Game.h"
#include <SFML/Graphics.hpp>

int main()
{

	// sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "Test Background");
    // sf::Texture backgroundTexture;

    // if (!backgroundTexture.loadFromFile("assets/Background.png")) {
    //     std::cerr << "Failed to load background image!\n";
    //     return -1;
    // }

    // sf::Sprite backgroundSprite(backgroundTexture);
    // sf::FloatRect bounds = backgroundSprite.getLocalBounds();

    // backgroundSprite.setScale(
	// 	sf::Vector2f(
	// 		static_cast<float>(window.getSize().x) / bounds.size.x,
	// 		static_cast<float>(window.getSize().y) / bounds.size.y
	// 	)
    // );

    // backgroundSprite.setPosition(sf::Vector2f(0, 0));

    // while (window.isOpen())
    // {
    //     while (auto event = window.pollEvent())
    //     {
    //         // SFML 3.0.2 event checking:
    //         if (event->is<sf::Event::Closed>()) {
    //             window.close();
    //         }
    //     }

    //     window.clear();
    //     window.draw(backgroundSprite);
    //     window.display();
    // }

	Game game;
	game.Run();

	return 0;
}
