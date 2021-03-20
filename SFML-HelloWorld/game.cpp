#include "game.h"

#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>


Game::Game(sf::RenderWindow& window) : window(window)
{
	if (!font.loadFromFile("res/fonts/pixelated/pixelated.ttf"))
	{
		std::cout << "ERROR::Failed to load font (class)" << "\n";
	}
	text.setFont(font);
	
	for (int i{ 0 }; i < 3000; ++i)
	{
		int randomX = rand() % 1000;
		int randomY = rand() % 400;
		dusts[i].position = sf::Vector2f((float)randomX + 100.0f, (float)randomY + 100.0f);
		randomX = rand() % 50 - 25;
		randomY = rand() % 100 - 150;
		dusts[i].velocity = sf::Vector2f((float)randomX, (float)randomY);
	}
}

void Game::clear()
{
	window.clear(sf::Color::Black);
}

void Game::update()
{
	time = bootTime.getElapsedTime().asSeconds() * 4.0f;

	// temporary
	std::string topText = "Falling Sand Engine - Indev\nBrought to you by Hermitao (for now)\n";
	std::ostringstream fpsTextFloat;
	fpsTextFloat << (1.0f / deltaTime);
	std::string fpsTextString(fpsTextFloat.str());
	std::string finalText = topText + fpsTextString;
	text.setString(finalText);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Color(232, 231, 209, 222));
	// ----------


	for (int i{ 0 }; i < 3000; ++i)
	{
		dusts[i].update();
	}

	deltaTime = deltaClock.restart().asSeconds() * timeScale;
}

void Game::draw()
{
	window.draw(text);
	for (int i{ 0 }; i < 3000; ++i)
	{
		window.draw(dusts[i].rectangle);
	}

	window.display();
}

