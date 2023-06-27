//
// Created by User on 27.06.2023.
//

#include "HUD.hpp"

HUD::HUD() {
    initFont();
    statView.setViewport(sf::FloatRect(0, 0, 0.5f, 0.5f));
}

void HUD::drawHUD(sf::RenderWindow &renderWindow) {
    //renderWindow.setView(statView);
    renderWindow.draw(this->hudText);
}

void HUD::updateHUD(const std::string &sortName) {
    std::stringstream stringstream;
    //todo more info to show about algorithm
    stringstream << sortName;
    this->hudText.setString(stringstream.str());
}

void HUD::initFont() {
    this->hudFont.loadFromFile("Fonts/arial.ttf");

    this->hudText.setFont(hudFont);
    this->hudText.setFillColor(sf::Color::White);
    this->hudText.setCharacterSize(32);

}


