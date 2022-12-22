#include "GUI.h"

bool GUI::isOpened() const {
    return window_->isOpen();
}

bool GUI::nextDay() const {
    return false;
}

void GUI::eventProcessing() {
    sf::Event event;
    if (window_->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window_->close();
        }
    }
    return;
}

void GUI::Draw(const Stock& stock) const {
    window_->clear(sf::Color(0x202020FF));

    // Borders for beaty
    sf::RectangleShape border;
    border.setFillColor(sf::Color(0xE0E0E0FF));
    border.setSize(sf::Vector2f(2, 720));
    border.setPosition(426, 64);
    window_->draw(border);

    border.setPosition(852, 64);
    window_->draw(border);

    border.setSize(sf::Vector2f(1278, 2));
    border.setPosition(0, 64);
    window_->draw(border);


    for (uint8_t i = 0; i < stock.shelfs_.size(); ++i) {
        for (uint8_t j = 0; j < stock.shelfs_[i].GetCount(); ++j) {
            sf::Text moneyText;
            moneyText.setCharacterSize(24);
            moneyText.setFillColor(sf::Color(0xE0E0E0FF));
            moneyText.setString(std::to_string(stock.shelfs_[i].GetPackages()[j].GetProduct().GetNumber()));
            moneyText.setPosition(12, 128 + 32 * (stock.shelfs_[i].GetCount() + j));
            moneyText.setFont(*font_);
            window_->draw(moneyText);
        }
    }

    sf::Text text;
    text.setCharacterSize(32);  
    text.setFillColor(sf::Color(0xE0E0E0FF));
    text.setFont(*font_);
    text.setString(std::to_string(stock.GetDay()) + ".01.23 (day " + std::to_string(stock.GetDay()) + ")");
    if (stock.GetDay() < 10) {
        text.setString("0" + std::to_string(stock.GetDay()) + ".01.23 (day " + std::to_string(stock.GetDay()) + ")");
    }
    text.setPosition(16, 10);
    window_->draw(text);

    text.setString("Profit: " + std::to_string(stock.GetMoney()));
    text.setPosition(426 + 16, 10);
    window_->draw(text);

    text.setString("Our products");
    text.setPosition(16, 80);
    window_->draw(text);

    text.setString("Active trucks");
    text.setPosition(426 + 16, 80);
    window_->draw(text);

    text.setString("Next order");
    text.setPosition(852 + 16, 80);
    window_->draw(text);

    text.setString("Next day");
    text.setStyle(text.Underlined);
    text.setPosition(852 + 16, 10);
    window_->draw(text);

    window_->display();
    return;
}