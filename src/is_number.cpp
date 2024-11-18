/*
** EPITECH PROJECT, 2024
** Connect_4
** File description:
** is_number.cpp
*/

#include <iostream>
#include <string>

using namespace std;

bool my_isdigit(char ch)
{
    return isdigit(static_cast<unsigned char>(ch));
}

bool is_number(string str)
{
    for (int i = 0; i < str.size(); i++) {
        if (!my_isdigit(str[i])) {
            return false;
        }
    }
    return true;
}