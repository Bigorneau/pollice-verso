#include <iostream>
#include <string>
#include <list>

#include <SFML/Network.hpp>

using std::cout;
using std::endl;
using std::string;
using std::list;

class Server
{
public:
	Server(unsigned short port);
	~Server();
	int run();
private:
	int acceptClient(sf::TcpListener &listener);
	int receivePacket(sf::TcpSocket &client);
	//
	unsigned short m_port;
	sf::SocketSelector m_selector;
	list<sf::TcpSocket*> m_clients;
};

Server::Server(unsigned short port) :
	m_port(port)
{
}

Server::~Server()
{
}

int Server::acceptClient(sf::TcpListener &listener)
{
	sf::TcpSocket *client = new sf::TcpSocket();
	if (listener.accept(*client) != sf::Socket::Done) {
		delete client;
		return -1;
	}
	m_clients.push_back(client);
	m_selector.add(*client);
	cout << "--- new client ";
	cout << client->getRemoteAddress();
	cout << ":" << client->getRemotePort();
	cout << " (local: " << client->getLocalPort() << ")" << endl;
	return 0;
}

int Server::run()
{
	sf::TcpListener listener;
	if (listener.listen(m_port) != sf::Socket::Done)
		return -1;
	m_selector.add(listener);
	while (true) {
		if (!m_selector.wait())
			continue;

		if (m_selector.isReady(listener)) {
			acceptClient(listener);
		}
		else {
			list<sf::TcpSocket*>::iterator it;
			for (it = m_clients.begin(); it != m_clients.end(); it++) {
				sf::TcpSocket &client = **it;
				if (m_selector.isReady(client))
					receivePacket(client);
			}
		}
		sf::sleep(sf::milliseconds(10));
	}
	return 0;
}

int Server::receivePacket(sf::TcpSocket &client)
{
	sf::Packet packet;
	string message;
	client.receive(packet);
	if (packet >> message) {
		cout << "client: " << client.getRemoteAddress();
		cout << ":" << client.getRemotePort();
		cout << " (local: " << client.getLocalPort() << ")";
		cout << " message:" << message << endl;
	}
	packet.clear();
	message.clear();
	sf::sleep(sf::milliseconds(10));

	return 0;
}

int main(int argc, char *argv[])
{
	Server s(8888);
	s.run();
	return 0;
}
