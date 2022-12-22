#pragma once
#include <SFML/Graphics.hpp>

#include "Stock.h"

class GUI
{
public:
    GUI(const uint16_t width, const uint16_t height, const std::string& title) {
        window = new sf::RenderWindow(sf::VideoMode(width, height), title);
        if (!font->loadFromFile("resourses/Consolas.ttf")) {
            throw;
        }
    }


    bool isOpened() const {
        return window->isOpen();
    }

    bool pressed() const {
        return false;
    }

    void Draw(const Stock& stock) {
        //window->clear(sf::Color(0x202020FF));
        sf::Text text;
        text.setCharacterSize(32);
        text.setFillColor(sf::Color(0xE0E0E0FF));
        text.setString("aboba)");
        text.setPosition(100, 100);
        window->draw(text);
        window->display();
        return;
    }

private:
    sf::RenderWindow* window;
    sf::Font* font = new sf::Font;
};

