//
// Created by User on 25.06.2023.
//

#ifndef UNTITLED_SORTALGO_HPP
#define UNTITLED_SORTALGO_HPP
#include "Engine.hpp"
#include "HUD.hpp"

using namespace std::literals::chrono_literals;

class SortAlgo {
public:
    SortAlgo();

    ~SortAlgo();

public:
    //std::unique_ptr<HUD> hud;
    HUD * hud;
private:
    //CLOCKS
    sf::Clock sortTime;
private:
    //VIEWS
    sf::View mainView;
public:

    void bubbleSort(std::vector<int> &array, sf::RenderWindow &renderWindow);

    void selectionSort(std::vector<int> &array, sf::RenderWindow &renderWindow);

    void insertionSort(std::vector<int> &array, sf::RenderWindow &renderWindow);


    void merge(std::vector<int> &arr, int left, int mid, int right);

    void mergeSort(std::vector<int> &arr, int left, int right, sf::RenderWindow &renderWindow);


    int partition(std::vector<int> &arr, int low, int high, sf::RenderWindow &renderWindow);

    void quickSort(std::vector<int> &arr, int low, int high, sf::RenderWindow &renderWindow);


    void heapify(std::vector<int> &arr, int n, int i, sf::RenderWindow &renderWindow);

    void heapSort(std::vector<int> &arr, sf::RenderWindow &renderWindow);


    // Counting sort for a specific digit (exp)
    void countingSort(std::vector<int> &arr, int exp, sf::RenderWindow &renderWindow);

    void radixSort(std::vector<int> &arr, sf::RenderWindow &renderWindow);


    void bucketSort(std::vector<int> &arr, int numBuckets, sf::RenderWindow &renderWindow);

    void shellSort(std::vector<int> &arr, sf::RenderWindow &renderWindow);


    void bingoSort(std::vector<int> &vec, sf::RenderWindow &renderWindow);

    void combSort(std::vector<int> &arr, sf::RenderWindow &renderWindow);

    void pigeonholeSort(std::vector<int> &arr, sf::RenderWindow &renderWindow) const;

    void cycleSort(std::vector<int> &arr, sf::RenderWindow &renderWindow);

private:
    //Utility
    // Get the maximum value in the array
    int getMax(const std::vector<int> &arr);

    /* Function for finding the maximum and minimum element of
    the Array */
    void maxMin(std::vector<int> vec, int n, int &bingo, int &nextBingo);

    bool checkIfSorted(const std::vector<int> &array);

    void drawArray(const std::vector<int> &array, sf::RenderWindow &renderWindow, unsigned short redPos,
                   unsigned short greenPos) const;
};


#endif //UNTITLED_SORTALGO_HPP
