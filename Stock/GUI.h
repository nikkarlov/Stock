#pragma once
#include <SFML/Graphics.hpp>

#include "Stock.h"

class GUI
{
public:
    GUI() {
        window_ = new sf::RenderWindow(sf::VideoMode(1278, 720), "Stock Simutator 2022", sf::Style::Close);
        if (!font_->loadFromFile("resourses/Consolas.ttf")) {
            throw;
        }
    }


    bool isOpened() const;

    bool nextDay() const;

    void eventProcessing();

    void Draw(const Stock&) const;

private:
    sf::RenderWindow* window_;
    sf::Font* font_ = new sf::Font;

    enum ClickState {NotClicked, Clicked, Analysed};
    ClickState state_;
};
