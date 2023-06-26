//
// Created by User on 25.06.2023.
//

#ifndef UNTITLED_SORTALGO_HPP
#define UNTITLED_SORTALGO_HPP
#include "Engine.hpp"
using namespace std::literals::chrono_literals;
class SortAlgo {
public:

    static void bubbleSort(std::vector<int> &array, sf::RenderWindow &renderWindow, sf::Clock & sortTime);

    static void selectionSort(std::vector<int> &array, sf::RenderWindow &renderWindow, sf::Clock & sortTime);

    static void insertionSort(std::vector<int> &array, sf::RenderWindow &renderWindow, sf::Clock & sortTime);


    static void merge(std::vector<int>& arr, int left, int mid, int right);
    static void mergeSort(std::vector<int>& arr, int left, int right, sf::RenderWindow &renderWindow, sf::Clock & sortTime);


    static int partition(std::vector<int>& arr, int low, int high, sf::RenderWindow &renderWindow, sf::Clock & sortTime);
    static void quickSort(std::vector<int>& arr, int low, int high, sf::RenderWindow &renderWindow, sf::Clock & sortTime);


    static void heapify(std::vector<int>& arr, int n, int i, sf::RenderWindow &renderWindow, sf::Clock & sortTime);
    static void heapSort(std::vector<int>& arr, sf::RenderWindow &renderWindow, sf::Clock & sortTime);


    // Get the maximum value in the array
    static int getMax(const std::vector<int>& arr);
    // Counting sort for a specific digit (exp)
    static void countingSort(std::vector<int>& arr, int exp, sf::RenderWindow &renderWindow, sf::Clock & sortTime);
    static void radixSort(std::vector<int>& arr, sf::RenderWindow &renderWindow, sf::Clock & sortTime);


    static void bucketSort(std::vector<int>& arr, int numBuckets, sf::RenderWindow &renderWindow, sf::Clock & sortTime);

    static void shellSort(std::vector<int>& arr, sf::RenderWindow &renderWindow, sf::Clock & sortTime);

    /*
    Function for finding the maximum and minimum element of
    the Array
    */
    static void maxMin(std::vector<int> vec, int n, int& bingo, int& nextBingo);

    static void bingoSort(std::vector<int>& vec, sf::RenderWindow &renderWindow, sf::Clock & sortTime);


    static void combSort(std::vector<int>& arr, sf::RenderWindow &renderWindow, sf::Clock & sortTime);

    static void pigeonholeSort(std::vector<int>& arr, sf::RenderWindow &renderWindow, sf::Clock & sortTime);

    static void cycleSort(std::vector<int>& arr, sf::RenderWindow &renderWindow, sf::Clock & sortTime);
};


#endif //UNTITLED_SORTALGO_HPP
