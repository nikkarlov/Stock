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
    border.setSize(sf::Vector2f(1280, 1));
    border.setFillColor(sf::Color(0x808080FF));
    border.setPosition(0, 128);
    window_->draw(border);

    border.setSize(sf::Vector2f(320, 1));

    sf::Text text;
    text.setCharacterSize(24);
    text.setFillColor(sf::Color(0xE0E0E0FF));
    text.setFont(*font_);

    // Requests
    for (uint8_t i = 0; i < stock.GetRequests().size(); ++i) {
        Request req = stock.GetRequests()[i];

        text.setString(std::to_string(req.GetProduct().GetNumber()));
        text.setPosition(12, 128 + 32 * i);
        window_->draw(text);

        border.setPosition(0, 128 + 32 * (i + 1));
        window_->draw(border);
    }

    // Our products
    int16_t shift = 0;
    for (uint8_t i = 0; i < stock.shelfs_.size(); ++i) {
        for (uint8_t j = 0; j < stock.shelfs_[i].GetPackages().size(); ++j) {
            Package curPackage = stock.shelfs_[i].GetPackages()[j];
            Product curProduct = curPackage.GetProduct();

            text.setString(std::to_string(curProduct.GetNumber()) + ": " + std::to_string(curPackage.GetCost()) + "$ - " + ConvertDate(curPackage.GetManifuctureDate() + curProduct.GetExpirationDate()));
            text.setPosition(320 + 12, 128 + 32 * (shift + j));
            window_->draw(text);
        }
        shift += stock.shelfs_[i].GetPackages().size();
        border.setPosition(320, 128 + 32 * shift);
        window_->draw(border);
    }

    // Trucks
    for (uint8_t i = 0; i < stock.trucks_.size(); ++i) {
        Truck truck = stock.trucks_[i];
        Package package = truck.GetPackage();
        Product product = package.GetProduct();

        text.setString(std::to_string(product.GetNumber()) + ": " + ConvertDate(stock.GetDay() + truck.GetTime()) + " (in " + std::to_string(truck.GetTime() + 1) + " days)");
        text.setPosition(640 + 12, 128 + 32 * i);
        window_->draw(text);

        border.setPosition(640, 128 + 32 * (i + 1));
        window_->draw(border);
    }

    // Titles
    border.setFillColor(sf::Color(0xE0E0E0FF));
    border.setSize(sf::Vector2f(2, 720));
    border.setPosition(320, 64);
    window_->draw(border);

    border.setPosition(640, 64);
    window_->draw(border);

    border.setPosition(960, 64);
    window_->draw(border);

    border.setSize(sf::Vector2f(1280, 2));
    border.setPosition(0, 64);
    window_->draw(border);

    text.setCharacterSize(32);  
    text.setFillColor(sf::Color(0xE0E0E0FF));
    text.setFont(*font_);
    text.setString(ConvertDate(stock.GetDay()) + " (day " + std::to_string(stock.GetDay()) + ")");
    text.setPosition(16, 10);
    window_->draw(text);

    text.setString("Profit: " + std::to_string(stock.GetMoney()));
    text.setPosition(640 + 16, 10);
    window_->draw(text);

    text.setString("Requests");
    text.setPosition(16, 80);
    window_->draw(text);

    text.setString("Our products");
    text.setPosition(320 + 16, 80);
    window_->draw(text);

    text.setString("Active trucks");
    text.setPosition(640 + 16, 80);
    window_->draw(text);

    text.setString("Next order");
    text.setPosition(960 + 16, 80);
    window_->draw(text);

    text.setString("Next day");
    text.setStyle(text.Underlined);
    text.setPosition(1100 + 16, 10);
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
    if (date / 30 / 12 % 100 + 1 < 10) year = "0" + year;

    return day + "." + month + "." + year;
}