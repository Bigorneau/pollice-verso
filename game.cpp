#include <unistd.h>

#include <SFML/Window.hpp>

#include "config.h"
#include "game.h"

using namespace std;

Game::Game()
{
}

Game::~Game()
{
}

int Game::run()
{
	struct config_s * config = get_config();
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::Window window(sf::VideoMode(config->width, config->height, desktop.bitsPerPixel), "Pollice Verso");

	while(window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		usleep(1000);
	}

	return 0;
}

int Game::stop()
{
	return 0;
}
