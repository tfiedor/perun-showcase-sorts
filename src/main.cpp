#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <climits>
#include "sorts.h"

#define DEBUG false

#if DEBUG
const int MAX_SORT_ARR_LEN = 50;
#else
const int MAX_SORT_ARR_LEN = 5000;
#endif
const int SORT_ARR_LEN_INC = 10;

/** Prints the input array
 *
 * @param array: input array which will be printed
 * @param len: lenght of the input array
 */
void PrintArray(int* array, int len) {
    std::cout << "[";
    for (int i = 0; i < len; ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << array[i];
    }
    std::cout << "]\n";
}

int main() {

    // init the rng
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, INT_MAX - 1);

    // perform all sorts on scaling data
    for(int i = SORT_ARR_LEN_INC; i <= MAX_SORT_ARR_LEN; i += SORT_ARR_LEN_INC) {
        int *input = new int[i];
        for(int j = 0; j < i; j++) {
            input[j] = dis(gen);
        }
        if(DEBUG) {
            std::cout << "Generated input array:\n";
            PrintArray(input, i);
        }

        if(DEBUG) {
            std::cout << "Applying BubbleSort!\n";
        }
        HeapSort(input, i);
        if(DEBUG) {
            std::cout << "Done!\n";
        }

        if(DEBUG) {
            std::cout << "Resulting array:\n";
            PrintArray(input, i);
        }
        delete[] input;
    }

    return 0;
}
