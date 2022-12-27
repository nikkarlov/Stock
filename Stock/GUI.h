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

    bool nextDay();

    void eventProcessing();

    void Draw(const Stock&);

private:
    sf::RenderWindow* window_;
    sf::Font* font_ = new sf::Font;

    enum ClickState {NotClicked, Clicked, Analysed};
    ClickState state_;

    int lastMoney_ = 0;
    int savedMoney_ = 0;

    std::string ConvertDate(uint16_t) const;
};

