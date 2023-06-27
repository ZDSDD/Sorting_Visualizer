//
// Created by User on 25.06.2023.
//

#ifndef UNTITLED_ENGINE_HPP
#define UNTITLED_ENGINE_HPP

#include "definitions.hpp"
#include "predefined.hpp"
#include "SortAlgo.hpp"

enum Sorting_Algo {
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

class SortAlgo;

class Engine {
private:
    sf::RenderWindow window;
    std::vector<int> data;

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
    //std::unique_ptr<SortAlgo> sortAlgo;
    SortAlgo * sortAlgo;


private:
    void initArray();

    void initSounds();

    void initRandomEngine();

public:
    void startSort(Sorting_Algo sortingAlgo);

    void reShuffle(std::vector<int> &array);

public:
    Engine();

    ~Engine();

    void run();

    static void updatePollEvent(sf::RenderWindow &renderWindow);

};


#endif //UNTITLED_ENGINE_HPP
