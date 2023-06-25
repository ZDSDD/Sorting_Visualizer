//
// Created by User on 25.06.2023.
//

#include "SortAlgo.hpp"

void SortAlgo::bubbleSort(std::vector<int> &array, sf::RenderWindow &renderWindow) {

    size_t size = array.size();
    for (size_t step = 0; step < size; ++step) {
        for (size_t i = 0; i < size - step; ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
            //std::this_thread::sleep_for(10ms);
            //Engine::drawArray(array, renderWindow, i + 1);
        }

        std::this_thread::sleep_for(10ms);
        Engine::drawArray(array, renderWindow, size-step);
        Engine::updatePollEvent(renderWindow);
        if(!renderWindow.isOpen()) break;
    }
}
