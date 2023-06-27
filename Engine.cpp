//
// Created by User on 25.06.2023.
//

#include "Engine.hpp"


Engine::Engine() : min_value(1), max_value(window_height), dist(min_value, max_value) {
    window.create(sf::VideoMode(window_width, window_height), "Sort", sf::Style::Close | sf::Style::Titlebar);
    initRandomEngine();
    initArray();
    initSounds();

    this->sortAlgo = new SortAlgo();

}

void Engine::initArray() {
    data.resize(array_size);
    for (int &item: data) {
        item = dist(rng);
    }
}

void Engine::initRandomEngine() {
    std::srand(unsigned(std::time(nullptr)));
    rng.seed(std::rand());
}

void Engine::initSounds() {
    tick_sound_buffer.loadFromFile("Sounds/sort1.wav");
    tickSound.setBuffer(tick_sound_buffer);
}


/*
    Engine loop
*/
void Engine::run() {
//    startSort(Sorting_Algo::Bubble);
//    reShuffle(this->data);
    startSort(Sorting_Algo::Selection_Sort);
    reShuffle(this->data);
    startSort(Sorting_Algo::Insertion_Sort);
    reShuffle(this->data);
    startSort(Sorting_Algo::Merge_Sort);
    reShuffle(this->data);
    startSort(Sorting_Algo::Quick_Sort);
    reShuffle(this->data);
    startSort(Sorting_Algo::Heap_Sort);
    reShuffle(this->data);
    startSort(Sorting_Algo::Radix_Sort);
    reShuffle(this->data);
    startSort(Sorting_Algo::Bucket_Sort);
    reShuffle(this->data);
    startSort(Sorting_Algo::Shell_Sort);
    reShuffle(this->data);
    startSort(Sorting_Algo::Bingo_Sort);
    reShuffle(this->data);
    startSort(Sorting_Algo::Comb_Sort);
    reShuffle(this->data);
    startSort(Sorting_Algo::Pigeonhole_Sort);
    reShuffle(this->data);
    startSort(Sorting_Algo::Cycle_Sort);
    while (this->window.isOpen()) {
        updatePollEvent(this->window);
    }
}

void Engine::updatePollEvent(sf::RenderWindow &renderWindow) {
    sf::Event ev{};
    while (renderWindow.pollEvent(ev)) {
        if (ev.type == sf::Event::Closed) {
            renderWindow.close();
        }
        if (ev.key.code == sf::Keyboard::Escape) {
            renderWindow.close();
        }
    }
}

void Engine::startSort(Sorting_Algo sortingAlgo) {
    switch (sortingAlgo) {
        case Bubble:
            sortAlgo->hud->updateHUD("Bubble sort");
            this->sortAlgo->bubbleSort(this->data, this->window);
            break;
        case Selection_Sort:
            sortAlgo->hud->updateHUD("Selection sort");
            this->sortAlgo->selectionSort(this->data, this->window);
            break;
        case Insertion_Sort:
            sortAlgo->hud->updateHUD("Insertion_Sort");
            this->sortAlgo->insertionSort(this->data, this->window);
            break;
        case Merge_Sort:
            sortAlgo->hud->updateHUD("Merge_Sort");
            this->sortAlgo->mergeSort(this->data, 0, data.size() - 1, this->window);
            break;
        case Quick_Sort:
            sortAlgo->hud->updateHUD("Quick_Sort");
            this->sortAlgo->quickSort(this->data, 0, data.size() - 1, this->window);
            break;
        case Heap_Sort:
            sortAlgo->hud->updateHUD("Heap_Sort");
            this->sortAlgo->heapSort(this->data, this->window);
            break;
        case Radix_Sort:
            sortAlgo->hud->updateHUD("Radix_Sort");
            this->sortAlgo->radixSort(this->data, this->window);
            break;
        case Bucket_Sort:
            sortAlgo->hud->updateHUD("Bucket_Sort");
            this->sortAlgo->bucketSort(this->data, 5, this->window);
            break;
        case Shell_Sort:
            sortAlgo->hud->updateHUD("Shell_Sort");
            this->sortAlgo->shellSort(this->data, this->window);
            break;
        case Bingo_Sort:
            sortAlgo->hud->updateHUD("Bingo_Sort");
            this->sortAlgo->bingoSort(this->data, this->window);
            break;
        case Comb_Sort:
            sortAlgo->hud->updateHUD("Comb_Sort");
            this->sortAlgo->combSort(this->data, this->window);
            break;
        case Pigeonhole_Sort:
            sortAlgo->hud->updateHUD("Pigeonhole_Sort");
            this->sortAlgo->pigeonholeSort(this->data, this->window);
            break;
        case Cycle_Sort:
            sortAlgo->hud->updateHUD("Cycle_Sort");
            this->sortAlgo->cycleSort(this->data, this->window);
            break;
        default:
            this->window.close();
            break;
    }
}


void Engine::reShuffle(std::vector<int> &array) {
    std::shuffle(array.begin(), array.end(), rng);
}


Engine::~Engine() {
    delete this->sortAlgo;
}




