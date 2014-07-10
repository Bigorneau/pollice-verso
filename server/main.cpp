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
	int run();
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

int Server::run()
{
	sf::TcpListener listener;
	if (listener.listen(m_port) != sf::Socket::Done)
		return -1;
	if (listener.accept(m_socket) != sf::Socket::Done)
		return -1;
	cout << "client: " << m_socket.getRemoteAddress();
	cout << ":" << m_socket.getRemotePort();

	sf::Packet packet;
	string message;
	while (true) {
		m_socket.receive(packet);
		if (packet >> message)
			cout << message << endl;
		packet.clear();
		message.clear();
		sf::sleep(sf::milliseconds(10));
	}

	return 0;
}

int main(int argc, char *argv[])
{
	Server s(8888);
	s.run();
	return 0;
}
