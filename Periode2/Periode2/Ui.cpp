#include "Ui.h"
#include <SFML/Graphics.hpp>
#include "Player.h"

int UI(){
	sf::RenderWindow window(sf::VideoMode(800, 600), "UI");

	window.setFramerateLimit(60);

	sf::RectangleShape button(sf::Vector2f(200, 50)); 
	button.setFillColor(sf::Color::Green); 
	button.setPosition(300, 275); 

	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
		return -1; 
	}

	sf::Text buttonText("Play", font, 24); 
	buttonText.setFillColor(sf::Color::White);  
	buttonText.setPosition(350, 290);


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close(); 
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					
					if (button.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
					
						window.close(); 
					}
				}
			}
		}
		window.clear(sf::Color::Blue); 

	
		window.draw(button);
		window.draw(buttonText);
		
		window.display();
	}
	return 0;
}
