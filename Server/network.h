#ifndef NETWORK_H
#define NETWORK_H

#include <thread>

#include <SFML/Network.hpp>

#include "World/world.h"
#include "Network/client.h"


class Network
{
public:
    Network(World &GameWorld);

    void Configure();

    void NewConnect();

    void MakePackets();

    void MakeHumansPacket();
    void MakeGroundsPacket();
    void MakeItemsPacket();

    void SendPackets();

    void ReceivePackets();


//private:
    World &GameWorld;

    sf::UdpSocket NewClientSocket;
    std::vector<Client> Clients;

    sf::UdpSocket SendSocket;
    sf::UdpSocket ReceiveSocket;

    sf::UdpSocket GroundsSocket;
    sf::UdpSocket HumansSocket;
//    sf::UdpSocket ItemsSocket;

//    sf::Packet ItemsPacket;
    sf::Packet HumansPacket;
    sf::Packet GroundsPacket;

    std::thread * SendThread;
    std::thread * ReceiveThread;
    std::thread * NewClientThread;
    std::vector<std::thread *> MakePacketThreads;
};

#endif // NETWORK_H
