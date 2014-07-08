#include <iostream>
#include <string>

#include <SFML/Network.hpp>

using std::cout;
using std::endl;
using std::string;

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
	cout << "client: " << m_socket.getRemoteAddress();
	cout << ":" << m_socket.getRemotePort();

	sf::Packet packet;
	m_socket.receive(packet);

	string message;
	if (packet >> message)
		cout << message << endl;
	return 0;
}

void ServerLoop(void)
{
}

int main(int argc, char *argv[])
{
	Server s(8888);
	s.listen();
	return 0;
}
