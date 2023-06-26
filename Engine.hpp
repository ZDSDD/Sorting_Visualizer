//
// Created by User on 25.06.2023.
//

#ifndef UNTITLED_ENGINE_HPP
#define UNTITLED_ENGINE_HPP

#include "definitions.hpp"
#include "predefined.hpp"
#include "SortAlgo.hpp"

enum Sorting_Algo{
    Bubble,
    Selection_Sort,
    Insertion_Sort,
    Merge_Sort,
    Quick_Sort,
    Heap_Sort,
    Radix_Sort,
    Bucket_Sort,
    Shell_Sort,
    Bingo_Sort,
    Comb_Sort,
    Pigeonhole_Sort,
    Cycle_Sort,

};

class Engine {
private:
    sf::RenderWindow window;
    std::vector<int> data;
private:
    //VIEWS
    sf::View statView;
    sf::View mainView;
private:
    //RANDOM NUMBER GENERATOR
    std::mt19937 rng;
    int min_value;
    int max_value;
    std::uniform_int_distribution<int> dist;
private:
    //SOUNDS
    sf::Sound tickSound;
    sf::SoundBuffer tick_sound_buffer;
private:
    //CLOCKS
    sf::Clock sortTime;


private:
    void initArray();
    void initSounds();
    void initRandomEngine();
public:
    void startSort(Sorting_Algo sortingAlgo);
    static bool checkIfSorted(const std::vector<int> & array);
    void reShuffle(std::vector<int> & array);

public:
    Engine();
    ~Engine() = default;
    void run();
    static void updatePollEvent(sf::RenderWindow & renderWindow);
    static void drawArray(const std::vector<int> & array, sf::RenderWindow &renderWindow, unsigned short redPos,unsigned short greenPos);
};


#endif //UNTITLED_ENGINE_HPP
