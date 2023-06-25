//
// Created by User on 25.06.2023.
//

#include "Engine.hpp"

Engine::Engine() : min_value(1), max_value(window_height), dist(min_value, max_value) {
    window.create(sf::VideoMode(window_width, window_height), "Sort", sf::Style::Close | sf::Style::Titlebar);
    initRandomEngine();
    initArray();
    initSounds();
//    view.setViewport(sf::FloatRect(0, 0, 0.5f, 0.5f));
//    mainView.setViewport(window.getView().getViewport());
//    window.setView(mainView);
}

void Engine::initArray() {
    data.resize(array_size);
    for( int & item : data){
        item = dist(rng);
        std::cout << item << ' ';
    }std::cout << std::endl;
}

void Engine::initRandomEngine() {
    std::srand(unsigned(std::time(nullptr)));
    rng.seed(std::rand());
}

void Engine::initSounds() {
    tick_sound_buffer.loadFromFile("Sounds/sort1.wav");
    tick_sound.setBuffer(tick_sound_buffer);
}

void Engine::drawArray(const std::vector<int> &array, sf::RenderWindow &renderWindow, const size_t redPos) {

    size_t size = array.size();
    renderWindow.clear();

    for (int i = 0; i < size; ++i) {
        sf::RectangleShape line(sf::Vector2f(2, array[i]));
        line.setFillColor(sf::Color(255, 255, 255));
        line.setPosition(3 * i, renderWindow.getSize().y - line.getGlobalBounds().height);
        renderWindow.draw(line);
    }
    sf::RectangleShape line(sf::Vector2f(2, array[redPos]));
    line.setFillColor(sf::Color(255, 0, 0));
    line.setPosition(3 * redPos, renderWindow.getSize().y - line.getGlobalBounds().height);
    renderWindow.draw(line);
    renderWindow.display();

}

void Engine::run() {
    while(this->window.isOpen()){
        updatePollEvent(this->window);
        SortAlgo::bubbleSort(this->data,this->window);
    }
}

void Engine::updatePollEvent(sf::RenderWindow & renderWindow) {
    sf::Event ev{};
    while(renderWindow.pollEvent(ev)){
        if(ev.type == sf::Event::Closed){
            renderWindow.close();
        }
        if(ev.key.code == sf::Keyboard::Escape){
            renderWindow.close();
        }
    }
}
