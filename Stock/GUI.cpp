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


    int16_t shift = 0;
    for (uint8_t i = 0; i < stock.shelfs_.size(); ++i) {
        for (uint8_t j = 0; j < stock.shelfs_[i].GetCount(); ++j) {
            Package curPackage = stock.shelfs_[i].GetPackages()[j];
            Product curProduct = curPackage.GetProduct();

            /*if (curProduct.GetNumber() < 0) {
                --shift;
                continue;
            }*/

            sf::Text text;
            text.setCharacterSize(24);
            text.setFillColor(sf::Color(0xE0E0E0FF));
            text.setString("ID: " + std::to_string(curProduct.GetNumber()) + " - until " + ConvertDate(curPackage.GetManifuctureDate() + curProduct.GetExpirationDate()));
            text.setPosition(12, 128 + 32 * (shift + j));
            text.setFont(*font_);
            window_->draw(text);
        }
        shift += stock.shelfs_[i].GetCount();
    }

    sf::Text text;
    text.setCharacterSize(32);  
    text.setFillColor(sf::Color(0xE0E0E0FF));
    text.setFont(*font_);
    text.setString(ConvertDate(stock.GetDay()) + " (day " + std::to_string(stock.GetDay()) + ")");
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


std::string GUI::ConvertDate(uint16_t date) const {
    date--;
    std::string day = std::to_string(date % 30 + 1);
    std::string month = std::to_string(date / 30 % 12 + 1);
    std::string year = std::to_string(date / 30 / 12 % 100 + 1);

    if (date % 30 + 1 < 10) day = "0" + day;
    if (date / 30 % 12 + 1 < 10) month = "0" + month;
    if (date / 30 / 12 + 1 < 10) year = "0" + year;

    return day + "." + month + "." + year;
}