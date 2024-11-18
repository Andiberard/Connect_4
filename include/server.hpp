/*
** EPITECH PROJECT, 2024
** Connect_4
** File description:
** server.hpp
*/

#ifndef CLIENT_H_
    #define CLIENT_H_
    #include <SFML/Network.hpp>
    #include <vector>
    #include <iostream>
    #include <string>

class server
{
    public :
    server();
    ~server();
    int nbClient();
    int start();
    void add_client();
    void communicate_clients();
    short int getPort();
    sf::SocketSelector getSelector();
    sf::TcpListener& getListener();

    private :
    short int m_port;
    sf::SocketSelector m_selector;
    sf::TcpListener m_listener;
    std::vector<sf::TcpSocket *> m_clients;
    sf::Packet m_sendPacket;
    sf::Packet m_receivePacket;
};

#endif
