//
// Created by User on 27.06.2023.
//

#ifndef SORTING_VISUALIZER_HUD_HPP
#define SORTING_VISUALIZER_HUD_HPP


class HUD {
private:
    sf::Text hudText;
    sf::Font hudFont;
    sf::View statView;
public:
    HUD();
    ~HUD() = default;
    void drawHUD(sf::RenderWindow &renderWindow);
    void updateHUD(const std::string &sortName);

    void initFont();
};


#endif //SORTING_VISUALIZER_HUD_HPP
