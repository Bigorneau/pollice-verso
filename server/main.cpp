#include <iostream>

#include <SFML/Network.hpp>

class Server
{
public:
	Server(unsigned short port);
	~Server();
	int listen();
private:
	unsigned short m_port;
	sf::TcpSocket m_socket;
};

Server::Server(unsigned short port) :
	m_port(port)
{
}

Server::~Server()
{
}

int Server::listen()
{
	sf::TcpListener listener;
	listener.listen(m_port);
	listener.accept(m_socket);
	return 0;
}

void ServerLoop(void)
{
}

int main(int argc, char *argv[])
{
	sf::Thread *thread = NULL;
	Server s(8888);
	s.listen();
	return 0;
}
