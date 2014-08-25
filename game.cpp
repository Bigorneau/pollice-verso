#include <unistd.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>

#include "config.h"
#include "game.h"
#include "unit.h"

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
	sf::RenderWindow window(sf::VideoMode(config->width, config->height, desktop.bitsPerPixel), "Pollice Verso");

	window.setFramerateLimit(60);

	Unit u("resources/ak47-m4_0.png");

	connect();
	while(window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			handleEvent(event);
		}

		window.clear();

		window.draw(u.getSprite());

		window.display();

		//sf::sleep(sf::milliseconds(100));
	}

	return 0;
}

int Game::stop()
{
	return 0;
}

int Game::handleEvent(sf::Event &event)
{
	string message;
	switch (event.type) {
	case sf::Event::Closed: {
		message = "closed";
	} break;
	case sf::Event::Resized: {
		message = "resized";
	} break;
	case sf::Event::LostFocus: {
		message = "lost focus";
	} break;
	case sf::Event::GainedFocus: {
		message = "gained focus";
	} break;
	case sf::Event::TextEntered: {
		message = "text entered";
	} break;
	case sf::Event::KeyPressed: {
		message = "key pressed";
	} break;
	case sf::Event::KeyReleased: {
		message = "key released";
	} break;
	case sf::Event::MouseWheelMoved: {
		message = "mousse wheel moved";
	} break;
	case sf::Event::MouseButtonPressed: {
		message = "mouse button pressed";
	} break;
	case sf::Event::MouseButtonReleased: {
		message = "mouse button released";
	} break;
	case sf::Event::MouseMoved: {
		message = "mouse moved";
	} break;
	case sf::Event::MouseEntered: {
		message = "mouse entered";
	} break;
	case sf::Event::MouseLeft: {
		message = "mouse left";
	} break;
	case sf::Event::JoystickButtonPressed: {
		message = "joystick button pressed";
	} break;
	case sf::Event::JoystickButtonReleased: {
		message = "joystick button released";
	} break;
	case sf::Event::JoystickMoved: {
		message = "joystick moved";
	} break;
	case sf::Event::JoystickConnected: {
		message = "joystick connected";
	} break;
	case sf::Event::JoystickDisconnected: {
		message = "joystick disconnected";
	} break;
	default: {
	} break;
	}

	sendPacket(message);
	return 0;
}

int Game::connect()
{
	m_socket.connect("127.0.0.1", 8888);
	return 0;
}

int Game::sendPacket(string &message)
{
	sf::Packet packet;
	packet << message;
	m_socket.send(packet);
	return 0;
}
