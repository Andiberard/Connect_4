/*
** EPITECH PROJECT, 2024
** Connect_4
** File description:
** multiplayer.cpp
*/

#include "../include/game.hpp"

using namespace std;

void multiplayer()
{
    server server;
    bool done = false;

    server.start();
    while (!done) {
        if (server.getSelector().wait()) {
            if (server.getSelector().isReady(server.getListener())) {
                //ajoute un client au server
                server.add_client();
            } else {
                //comunique avec les clients*
                server.communicate_clients();
            }
        }
    }
}