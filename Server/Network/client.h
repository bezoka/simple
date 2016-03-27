#ifndef CLIENT_H
#define CLIENT_H

#include <SFML/Network.hpp>


class Client
{
public:
    Client();

//private:
    sf::IpAddress Ip;
    unsigned int Port;

    unsigned int ID;

};

#endif // CLIENT_H
