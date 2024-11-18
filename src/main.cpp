/*
** EPITECH PROJECT, 2024
** Connect_4
** File description:
** main.cpp
*/

#include "../include/game.hpp"

using namespace std;

int main()
{
    int popo;
    cout << "- 1 pour créer une partie\n- 2 pour rejoindre une partie" << endl;
    cin >> popo;

    if (popo == 1) {
        multiplayer();
    } else if (popo == 2) {
        join();
    } else {
        cout << "1 ou 2 !!" << endl;
    }
    return 0;
}