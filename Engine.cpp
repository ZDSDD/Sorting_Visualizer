//
// Created by User on 25.06.2023.
//

#include "Engine.hpp"

Engine::Engine() : min_value(1), max_value(window_height), dist(min_value, max_value) {
    window.create(sf::VideoMode(window_width, window_height), "Sort", sf::Style::Close | sf::Style::Titlebar);
    initRandomEngine();
    initArray();
    initSounds();
    statView.setViewport(sf::FloatRect(0, 0, 0.5f, 0.5f));
//    mainView.setViewport(window.getView().getViewport());
//    window.setView(mainView);
}

void Engine::initArray() {
    data.resize(array_size);
    for (int &item: data) {
        item = dist(rng);
        //std::cout << item << ' ';
    }
    //std::cout << std::endl;
}

void Engine::initRandomEngine() {
    std::srand(unsigned(std::time(nullptr)));
    rng.seed(std::rand());
}

void Engine::initSounds() {
    tick_sound_buffer.loadFromFile("Sounds/sort1.wav");
    tickSound.setBuffer(tick_sound_buffer);
}

void Engine::drawArray(const std::vector<int> &array, sf::RenderWindow &renderWindow, const unsigned short redPos,
                       const unsigned short greenPos) {

    unsigned short size = array.size();
    renderWindow.clear();
    float_t y = static_cast<float>(renderWindow.getSize().y);
    sf::RectangleShape line;
    for (unsigned short i = 0; i < size; ++i) {
        line.setSize(sf::Vector2f(2, static_cast<float>(array[i])));
        line.setFillColor(sf::Color(255, 255, 255));
        line.setPosition(3.f * static_cast<float>(i),
                         y - line.getGlobalBounds().height);
        renderWindow.draw(line);
    }
    /* Paint the current switched position in red color */
    line.setSize(sf::Vector2f(2, static_cast<float>(array[redPos])));
    line.setFillColor(sf::Color(255, 0, 0));
    line.setPosition(static_cast<float>(3 * redPos),
                     y - line.getGlobalBounds().height);
    renderWindow.draw(line);
    /* Paint the current switched position in green color */
    line.setSize(sf::Vector2f(2, static_cast<float>(array[greenPos])));
    line.setFillColor(sf::Color(0, 255, 0));
    line.setPosition(static_cast<float>(3 * greenPos),
                     y - line.getGlobalBounds().height);
    renderWindow.draw(line);

    renderWindow.display();

}

/*
    Engine loop
*/
void Engine::run() {
//    startSort(Sorting_Algo::Bubble);
//    reShuffle(this->data);
//    startSort(Sorting_Algo::Selection_Sort);
//    reShuffle(this->data);
//    startSort(Sorting_Algo::Insertion_Sort);
//    reShuffle(this->data);
//    startSort(Sorting_Algo::Merge_Sort);
//    reShuffle(this->data);
//    startSort(Sorting_Algo::Quick_Sort);
//    startSort(Sorting_Algo::Heap_Sort);
//    startSort(Sorting_Algo::Radix_Sort);
//    startSort(Sorting_Algo::Bucket_Sort);
//    startSort(Sorting_Algo::Shell_Sort);
//    startSort(Sorting_Algo::Bingo_Sort);
//    startSort(Sorting_Algo::Comb_Sort);
//    startSort(Sorting_Algo::Pigeonhole_Sort);
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
            SortAlgo::bubbleSort(this->data, this->window, this->sortTime);
            break;
        case Selection_Sort:
            SortAlgo::selectionSort(this->data, this->window, this->sortTime);
            break;
        case Insertion_Sort:
            SortAlgo::insertionSort(this->data, this->window, this->sortTime);
            break;
        case Merge_Sort:
            SortAlgo::mergeSort(this->data,0, data.size() - 1, this->window, this->sortTime);
            break;
        case Quick_Sort:
            SortAlgo::quickSort(this->data,0,data.size() - 1, this->window,this->sortTime);
            break;
        case Heap_Sort:
            SortAlgo::heapSort(this->data, this->window,this->sortTime);
            break;
        case Radix_Sort:
            SortAlgo::radixSort(this->data, this->window,this->sortTime);
            break;
        case Bucket_Sort:
            SortAlgo::bucketSort(this->data,5, this->window,this->sortTime);
            break;
        case Shell_Sort:
            SortAlgo::shellSort(this->data, this->window,this->sortTime);
            break;
        case Bingo_Sort:
            SortAlgo::bingoSort(this->data, this->window,this->sortTime);
            break;
        case Comb_Sort:
            SortAlgo::combSort(this->data, this->window,this->sortTime);
            break;
        case Pigeonhole_Sort:
            SortAlgo::pigeonholeSort(this->data, this->window,this->sortTime);
            break;
        case Cycle_Sort:
            SortAlgo::cycleSort(this->data, this->window,this->sortTime);
            break;
        default:
            this->window.close();
            break;
    }
}

bool Engine::checkIfSorted(const std::vector<int> &array) {
    for (unsigned short i = 0, n = array.size(); i < n - 1; ++i) {
        if (array.at(i) < array.at(i + 1))
            return false;
    }
    return true;
}

void Engine::reShuffle(std::vector<int> &array) {
    std::shuffle(array.begin(), array.end(), rng);
}
