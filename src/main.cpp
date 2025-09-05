#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	std::cout << "Game System - Initializing Technovaders" << std::endl;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Side Invaders");
	
	std::cout << "Game System - Creating Window" << std::endl;

	sf::RectangleShape player(sf::Vector2f(100, 100));
	player.setFillColor(sf::Color::Blue);
	player.setPosition(50, 270);
	
	std::cout << "Game System - Creating Player" << std::endl;

	while (window.isOpen()){

		// creating close event 
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
		}

		// creating player inputs
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player.move(0, 2);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			player.move(0, -2);
		}


		// draw object and display
		
		window.clear(); 

		window.draw(player);

		window.display();

		//	std::cout << "Game System - Drawing Players" << std::endl;

	}

	return 0;
}
