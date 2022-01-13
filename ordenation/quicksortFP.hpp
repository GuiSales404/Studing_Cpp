#pragma once

#include "utils.hpp"
#include <cmath>
#include <iostream>

using namespace std;

template <typename T>
int partitionFP(T array[], int low, int high) {
    T pivot = array[pivo(low, high)];
    int i = low - 1;
    int j = high + 1;
    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);
 
        do {
            j--;
        } while (array[j] > pivot);
 
        if (i >= j) {
            return j;
        }
 
        swap_values(array[i], array[j]);
    }
}

template <typename T>
void quicksortFPRecursive(T array[], int low, int high) {
    if(low < high) {
        int p = partitionFP(array, low, high);
        quicksortFPRecursive(array, low, p);
        quicksortFPRecursive(array, p + 1, high);
    }
}

template <typename T>
void quicksortFP(T array[], int length) {
    quicksortFPRecursive(array, 0, length - 1);
}