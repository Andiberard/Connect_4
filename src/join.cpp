/*
** EPITECH PROJECT, 2024
** Connect_4
** File description:
** join.cpp
*/

#include "../include/game.hpp"

using namespace std;

int getport()
{
    int port(0);
    string str_port;

    cin >> str_port;
    if (!is_number(str_port)) {
        return -1;
    }
    port = stoi(str_port);
    cin.ignore();
    return port;
}

void join()
{
    int port = getport();

}