//
// Created by User on 25.06.2023.
//

#include "SortAlgo.hpp"


void SortAlgo::drawArray(const std::vector<int> &array, sf::RenderWindow &renderWindow, const unsigned short redPos,
                       const unsigned short greenPos) const {
    //renderWindow.setView(mainView);
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

    this->hud->drawHUD(renderWindow);
    //renderWindow.setView(mainView);
    renderWindow.display();

}
void SortAlgo::bubbleSort(std::vector<int> &array, sf::RenderWindow &renderWindow) {
    sf::Time realTime;
    unsigned short size = array.size();
    sortTime.restart();
    for (unsigned short step = 0; step < size; ++step) {
        for (unsigned short i = 0; i < size - step; ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
            // realTime += sortTime.getElapsedTime();
            //std::cout << realTime.asSeconds() << std::endl;
            //std::this_thread::sleep_for(10ms);
             //drawArray(array, renderWindow, i + 1,step);
            // sortTime.restart();
        }

        //std::this_thread::sleep_for(10ms);
        //drawArray(array, renderWindow, size - step, step);
        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen()) break;
    }
}

void SortAlgo::selectionSort(std::vector<int> &array, sf::RenderWindow &renderWindow) {
    for (unsigned short i = 0; i < array_size - 1; i++) {
        unsigned short min_idx = i;
        for (unsigned short j = i + 1; j < array_size; j++) {
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            std::swap(array[min_idx], array[i]);
//            std::this_thread::sleep_for(10ms);
//            Engine::drawArray(array,renderWindow,min_idx,i);
        }
        std::this_thread::sleep_for(20ms);
        drawArray(array, renderWindow, min_idx, i);
        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen())return;
    }
}

void SortAlgo::insertionSort(std::vector<int> &array, sf::RenderWindow &renderWindow) {
    for (int i = 1; i < array_size; ++i) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
        std::this_thread::sleep_for(20ms);
        drawArray(array, renderWindow, j, i);
        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen())return;
    }
}

void
SortAlgo::mergeSort(std::vector<int> &arr, int left, int right, sf::RenderWindow &renderWindow) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, renderWindow);
        mergeSort(arr, mid + 1, right, renderWindow);

        merge(arr, left, mid, right);

        std::this_thread::sleep_for(20ms);
       drawArray(arr, renderWindow, left, right);
        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen())return;
    }
}


void SortAlgo::merge(std::vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

int SortAlgo::partition(std::vector<int> &arr, int low, int high, sf::RenderWindow &renderWindow) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
        drawArray(arr, renderWindow, low, high);
    }

    std::swap(arr[i + 1], arr[high]);
    std::this_thread::sleep_for(20ms);
   drawArray(arr, renderWindow, low, high);
    return i + 1;
}

void
SortAlgo::quickSort(std::vector<int> &arr, int low, int high, sf::RenderWindow &renderWindow) {
    if (low < high) {
        std::this_thread::sleep_for(20ms);
       drawArray(arr, renderWindow, low, high);

        int pi = partition(arr, low, high, renderWindow);

        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen())return;

        quickSort(arr, low, pi - 1, renderWindow);

        std::this_thread::sleep_for(20ms);
       drawArray(arr, renderWindow, low, high);

        quickSort(arr, pi + 1, high, renderWindow);

        std::this_thread::sleep_for(20ms);
        drawArray(arr, renderWindow, low, high);
    }
}

void SortAlgo::heapSort(std::vector<int> &arr, sf::RenderWindow &renderWindow) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i, renderWindow);
        std::this_thread::sleep_for(20ms);
        drawArray(arr, renderWindow, n, i);
        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen())return;
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]); // Move current root to end
        //std::this_thread::sleep_for(10ms);
        drawArray(arr, renderWindow, n, i);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0, renderWindow);
        //std::this_thread::sleep_for(10ms);
        drawArray(arr, renderWindow, n, i);
        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen())return;
    }
}

void SortAlgo::heapify(std::vector<int> &arr, int n, int i, sf::RenderWindow &renderWindow) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not the root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        drawArray(arr, renderWindow, largest, i);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest, renderWindow);
        drawArray(arr, renderWindow, largest, i);
    }
}

void SortAlgo::radixSort(std::vector<int> &arr, sf::RenderWindow &renderWindow) {
    int max = getMax(arr);

    // Perform counting sort for each digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp, renderWindow);
        std::this_thread::sleep_for(20ms);
        drawArray(arr, renderWindow, 0, 0);
        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen())return;
    }
}

void SortAlgo::countingSort(std::vector<int> &arr, int exp, sf::RenderWindow &renderWindow) {
    const int radix = 10; // Base 10 (decimal)
    int n = arr.size();

    std::vector<int> output(n);
    std::vector<int> count(radix, 0);

    // Count the occurrences of each digit
    for (int i = 0; i < n; ++i) {
        int digit = (arr[i] / exp) % radix;
        count[digit]++;
        drawArray(arr, renderWindow, exp, i);
        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen())return;
    }

    // Compute the cumulative count
    for (int i = 1; i < radix; ++i) {
        count[i] += count[i - 1];
        drawArray(arr, renderWindow, exp, i);
        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen())return;
    }

    // Build the output array
    for (int i = n - 1; i >= 0; --i) {
        int digit = (arr[i] / exp) % radix;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
        drawArray(arr, renderWindow, i, digit);
        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen())return;
    }

    // Copy the sorted output back to the original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
        drawArray(arr, renderWindow, i, n);
        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen())return;
    }
}

int SortAlgo::getMax(const std::vector<int> &arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void SortAlgo::bucketSort(std::vector<int> &arr, int numBuckets, sf::RenderWindow &renderWindow) {
    if (arr.empty()) {
        return;
    }

    int n = arr.size();

    // Find the minimum and maximum values in the array
    int minValue = arr[0];
    int maxValue = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    // Compute the range of each bucket
    double range = static_cast<double>(maxValue - minValue + 1) / numBuckets;

    // Create buckets
    std::vector<std::vector<int>> buckets(numBuckets);

    // Distribute elements into buckets
    for (int i = 0; i < n; ++i) {
        int bucketIndex = static_cast<int>((arr[i] - minValue) / range);
        buckets[bucketIndex].push_back(arr[i]);
        drawArray(buckets[bucketIndex], renderWindow, i, n);
        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen())return;


    }

    // Sort elements within each bucket
    for (int i = 0; i < numBuckets; ++i) {
        std::sort(buckets[i].begin(), buckets[i].end());
        std::this_thread::sleep_for(1500ms);
        drawArray(buckets[i], renderWindow, i, n);
        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen())return;
    }

    // Merge the sorted buckets into the original array
    int index = 0;
    for (int i = 0; i < numBuckets; ++i) {
        for (int j: buckets[i]) {
            arr[index++] = j;
            std::this_thread::sleep_for(20ms);
            drawArray(arr, renderWindow, i, index);
            Engine::updatePollEvent(renderWindow);
            if (!renderWindow.isOpen())return;
        }
    }
}

void SortAlgo::shellSort(std::vector<int> &arr, sf::RenderWindow &renderWindow) {
    int n = arr.size();

    // Start with a large gap and reduce it on each iteration
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform insertion sort on elements with the current gap
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;

            // Shift elements that are greater than the current value to the right
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
                // std::this_thread::sleep_for(10ms);
                drawArray(arr, renderWindow, i, j - gap);
                Engine::updatePollEvent(renderWindow);
                if (!renderWindow.isOpen())return;
            }

            // Insert the current value into the correct position
            arr[j] = temp;
            //std::this_thread::sleep_for(20ms);
            drawArray(arr, renderWindow, i, j);
            Engine::updatePollEvent(renderWindow);
            if (!renderWindow.isOpen())return;
        }
    }
}

void SortAlgo::bingoSort(std::vector<int> &vec, sf::RenderWindow &renderWindow) {
    int bingo = vec[0];
    int nextBingo = vec[0];
    maxMin(vec, array_size, bingo, nextBingo);
    int largestEle = nextBingo;
    int nextElePos = 0;
    while (bingo < nextBingo) {
        // Will keep the track of the element position to
        // shifted to their correct position
        int startPos = nextElePos;
        for (int i = startPos; i < array_size; i++) {
            if (vec[i] == bingo) {
                std::swap(vec[i], vec[nextElePos]);
                nextElePos = nextElePos + 1;
                //std::this_thread::sleep_for(10ms);
                //drawArray(vec, renderWindow, i, nextElePos);
                Engine::updatePollEvent(renderWindow);
                //if (!renderWindow.isOpen())return;
            }
                // Here we are finding the next Bingo Element
                // for the next pass
            else if (vec[i] < nextBingo) {
                nextBingo = vec[i];
                //std::this_thread::sleep_for(10ms);
                //drawArray(vec, renderWindow, i, nextBingo);
                //Engine::updatePollEvent(renderWindow);
                //if (!renderWindow.isOpen())return;
            }
//            drawArray(vec, renderWindow, i, nextBingo);
//            Engine::updatePollEvent(renderWindow);
//            if (!renderWindow.isOpen())return;
        }
        drawArray(vec, renderWindow, bingo, nextBingo);
        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen())return;

        bingo = nextBingo;
        nextBingo = largestEle;
    }
}

void SortAlgo::maxMin(std::vector<int> vec, int n, int &bingo, int &nextBingo) {
    for (int i = 1; i < n; bingo = std::min(bingo, vec[i]), nextBingo = std::max(nextBingo, vec[i]), i++);
}

void SortAlgo::combSort(std::vector<int> &arr, sf::RenderWindow &renderWindow)  {
    int n = arr.size();
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        // Update the gap value using the shrink factor (e.g., 1.3)
        gap = (gap * 10) / 13;
        if (gap < 1) {
            gap = 1;
        }

        swapped = false;
        std::this_thread::sleep_for(10ms);
        drawArray(arr, renderWindow, 0, 1);
        // Compare elements with the current gap and swap if necessary
        for (int i = 0; i < n - gap; ++i) {
            if (arr[i] > arr[i + gap]) {
                std::this_thread::sleep_for(10ms);
                drawArray(arr, renderWindow, i, i+gap);

                std::swap(arr[i], arr[i + gap]);
                std::this_thread::sleep_for(10ms);
                drawArray(arr, renderWindow, i, i+gap);

                swapped = true;
            }
            Engine::updatePollEvent(renderWindow);
            if (!renderWindow.isOpen())return;
        }
        std::this_thread::sleep_for(10ms);
        drawArray(arr, renderWindow, 0, 1);
    }
}

void SortAlgo::pigeonholeSort(std::vector<int> &arr, sf::RenderWindow &renderWindow) const  {
    int minVal = *std::min_element(arr.begin(), arr.end());
    int maxVal = *std::max_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    std::vector<int> pigeonholes(range, 0);

    // Count the occurrences of each element
    for (int num : arr) {
        pigeonholes[num - minVal]++;
        std::this_thread::sleep_for(10ms);
        drawArray(pigeonholes, renderWindow, 0, 0);
        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen())return;
    }

    // Move the elements from pigeonholes back to the original array
    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (pigeonholes[i] > 0) {
            arr[index] = i + minVal;
            pigeonholes[i]--;
            index++;
            //std::this_thread::sleep_for(10ms);
            drawArray(arr, renderWindow, i, i);
            Engine::updatePollEvent(renderWindow);
            if (!renderWindow.isOpen())return;
        }
        //std::this_thread::sleep_for(10ms);
        drawArray(arr, renderWindow, i, index);
        Engine::updatePollEvent(renderWindow);
        if (!renderWindow.isOpen())return;
    }
}

void SortAlgo::cycleSort(std::vector<int> &arr, sf::RenderWindow &renderWindow) {
    int n = arr.size();

    for (int cycleStart = 0; cycleStart < n - 1; ++cycleStart) {
        int item = arr[cycleStart];

        int pos = cycleStart;
        for (int i = cycleStart + 1; i < n; ++i) {
            if (arr[i] < item) {
                ++pos;
                std::this_thread::sleep_for(5ms);

                drawArray(arr, renderWindow, i, pos);
                Engine::updatePollEvent(renderWindow);
            }
        }

        if (pos == cycleStart) {
            continue;  // Skip if the element is already in the correct position
        }

        while (item == arr[pos]) {
            ++pos;
            drawArray(arr, renderWindow, item, pos);
            Engine::updatePollEvent(renderWindow);
        }

        std::swap(item, arr[pos]);

        drawArray(arr, renderWindow, cycleStart, pos);
        Engine::updatePollEvent(renderWindow);
        std::this_thread::sleep_for(5ms);

        if (!renderWindow.isOpen())return;
        // Rotate the remaining elements to their correct positions
        while (pos != cycleStart) {
            pos = cycleStart;

            for (int i = cycleStart + 1; i < n; ++i) {
                if (arr[i] < item) {
                    ++pos;
                }
            }

            while (item == arr[pos]) {
                ++pos;

            }

            std::swap(item, arr[pos]);
            std::this_thread::sleep_for(5ms);
            drawArray(arr, renderWindow, cycleStart, pos);
            Engine::updatePollEvent(renderWindow);
            if (!renderWindow.isOpen())return;
        }
    }
}

bool SortAlgo::checkIfSorted(const std::vector<int> &array) {
    for (unsigned short i = 0, n = array.size(); i < n - 1; ++i) {
        if (array.at(i) < array.at(i + 1))
            return false;
    }
    return true;
}

SortAlgo::SortAlgo() {
    //mainView.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
    //mainView.setViewport(sf::FloatRect(0.f,0.f,static_cast<float>(window_width),static_cast<float>(window_height)));
    this->hud = new HUD();
}

SortAlgo::~SortAlgo() {
delete this->hud;
}
