/*
** EPITECH PROJECT, 2024
** Connect_4
** File description:
** server.cpp
*/

#include "../include/server.hpp"

using namespace std;
using namespace sf;

server::server()
{
    m_port = 2000;
}

server::~server()
{
    m_selector.clear();
}

short int server::getPort()
{
    return m_port;
}

SocketSelector server::getSelector()
{
    return m_selector;
}

TcpListener& server::getListener()
{
    return m_listener;
}

int server::start()
{
    if (m_listener.listen(m_port) == Socket::Done) {
        cout << "Server lancé sur le port : " << m_port << endl;
    } else {
        exit(84);
    }
    m_selector.add(m_listener);
    return m_port;
}

int server::nbClient()
{
    return m_clients.size();
}

void server::add_client()
{
    TcpSocket *socket = new TcpSocket();
    Packet receivePacket;
    string pseudo;
    
    m_listener.accept(*socket);
    m_selector.add(*socket);
    m_clients.push_back(socket);
    
    if (socket->receive(receivePacket) == Socket::Done) {
        receivePacket >> pseudo;
        cout << pseudo << " Joined Server" << endl;
    }
}

void server::communicate_clients()
{
    for (int i = 0; i < m_clients.size(); i++) {
        if (m_selector.isReady(*m_clients[i])) {
            if (m_clients[i]->receive(m_receivePacket) == Socket::Done) {
                //reception
                
                //envoie
                for (int j = 0; j < m_clients.size(); j++) {
                    if (i != j) {
                        m_clients[j]->send(m_sendPacket);
                    }
                }
            }
        }
    }
}