//
// Created by User on 25.06.2023.
//

#ifndef UNTITLED_ENGINE_HPP
#define UNTITLED_ENGINE_HPP

#include "definitions.hpp"
#include "predefined.hpp"
#include "SortAlgo.hpp"
class Engine {
private:
    sf::RenderWindow window;
    std::vector<int> data;

    sf::View statView;
    sf::View mainView;

    std::mt19937 rng;
    int min_value;
    int max_value;
    std::uniform_int_distribution<int> dist;

    //Sounds
    sf::Sound tick_sound;
    sf::SoundBuffer tick_sound_buffer;

private:
    void initArray();
    void initSounds();
    void initRandomEngine();
public:
    Engine();
    void run();
    static void updatePollEvent(sf::RenderWindow & renderWindow);
    static void drawArray(const std::vector<int> &array, sf::RenderWindow &renderWindow, size_t redPos);
};


#endif //UNTITLED_ENGINE_HPP
