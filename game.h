#ifndef GAME_H
#define GAME_H

#include <string>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

class Game
{
public:
	Game();
	~Game();
	int run();
	int stop();
	int connect();
private:
	int handleEvent(sf::Event &event);
	int sendPacket(std::string &message);
	sf::TcpSocket m_socket;

};
#endif
