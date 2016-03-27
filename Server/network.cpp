#include "network.h"

Network::Network(World &GameWorld)
    : GameWorld(GameWorld)
{
    Configure();

    SendThread = new std::thread(&Network::SendPackets, this);
    ReceiveThread = new std::thread(&Network::ReceivePackets, this);
    NewClientThread = new std::thread(&Network::NewConnect, this);

    /*
    SendThread->join();
    ReceiveThread->join();
    NewClientThread->join();
    */
}


void Network::Configure()
{
    NewClientSocket.bind(54000);

    GroundsSocket.bind(53000);
    HumansSocket.bind(53001);
    //ItemsSocket.bind(53002);
}


void Network::NewConnect()
{
    while(1)
    {
        sf::Packet NewConnectionPacket;
        sf::IpAddress NewIp;
        short unsigned int Port;

        NewClientSocket.receive(NewConnectionPacket, NewIp, Port);

        int Value;

        NewConnectionPacket >> Value;

        if(Value == 1)
        {
            Client NewClient;

            NewClient.Ip = NewIp;
            NewClient.Port = Port;

            GameWorld.CreateHuman(b2Vec2(0.0f, 10.0f));

            NewClient.ID = GameWorld.ID;

            Clients.push_back(NewClient);
        }
    }
}


void Network::MakePackets()
{
    MakePacketThreads.push_back(new std::thread(&Network::MakeGroundsPacket, this));
    MakePacketThreads.push_back(new std::thread(&Network::MakeHumansPacket, this));
    //MakePacketThreads.push_back(new std::thread(&Network::MakeItemsPacket, this));

    for(unsigned int i=0; i<MakePacketThreads.size(); i++)
    {
        MakePacketThreads[i]->join();
    }

    for(unsigned int i=0; i<MakePacketThreads.size(); i++)
    {
        MakePacketThreads[i] = NULL;
    }
    MakePacketThreads.clear();
}


void Network::MakeGroundsPacket()
{
    for(unsigned int i=0; i<GameWorld.Grounds.size(); i++)
    {
        GroundsPacket << GameWorld.Grounds[i]->Body->GetPosition().x;
        GroundsPacket << GameWorld.Grounds[i]->Body->GetPosition().y;
    }
}


void Network::MakeHumansPacket()
{
    for(unsigned int i=0; i<GameWorld.Humans.size(); i++)
    {
        HumansPacket << GameWorld.Humans[i]->ID;

        HumansPacket << GameWorld.Humans[i]->Body->GetPosition().x;
        HumansPacket << GameWorld.Humans[i]->Body->GetPosition().y;
    }
}


void Network::MakeItemsPacket()
{
/*
    for(unsigned int i=0; i<GameWorld.Items.size(); i++)
    {
        ItemsPacket << GameWorld.Items[i]->Body->GetPosition().x;
        ItemssPacket << GameWorld.Items[i]->Body->GetPosition().y;
    }
*/
}


void Network::SendPackets()
{
    while(1)
    {
        MakePackets();

        for(unsigned int i=0; i<Clients.size(); i++)
        {
            SendSocket.send(GroundsPacket, Clients[i].Ip, 53000);
            SendSocket.send(HumansPacket, Clients[i].Ip, 53001);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}


void Network::ReceivePackets()
{
    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
