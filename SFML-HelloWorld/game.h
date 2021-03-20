#pragma once
#include <SFML/Graphics.hpp>

#include "dust.h"

class Game
{
public:
	static float gravity;
	static float timeScale;
	static float dustSize;

	sf::Clock bootTime{};
	sf::Clock deltaClock{};
	static float time;
	static float deltaTime;

	sf::RenderWindow& window;
	sf::Font font;
	sf::Text text;

	//Dust* dusts = (Dust*)malloc(sizeof(Dust) * 128);
	Dust dusts[3000];

	Game(sf::RenderWindow& window);
	void clear();
	void update();
	void draw();
};
