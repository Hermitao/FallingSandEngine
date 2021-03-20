#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"

float Game::dustSize{ 4.0f };
float Game::gravity{ 20.0f };
float Game::time{0.0f};
float Game::timeScale{ 3.0f };
float Game::deltaTime{0.0f};

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 600), L"(╯ ͠° ͟ʖ ͡°)╯●.* Falling Sand Engine Prototype - Indev");
    Game game(window);

	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
			    window.close();
			}
        }

        game.clear();
        game.update();
        game.draw();
    }

    return 0;
}
