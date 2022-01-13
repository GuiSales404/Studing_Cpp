#pragma once

#include <ctime>
#include <cmath>

template <typename T>
int partitionRP(T array[], int low, int high) {
    T pivot = array[rand() % (high - low) + low];
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
void quicksortRPRecursive(T array[], int low, int high) {
    if(low < high) {
        int p = partitionRP(array, low, high);
        quicksortRPRecursive(array, low, p);
        quicksortRPRecursive(array, p + 1, high);
    }
}

template <typename T>
void quicksortRP(T array[], int length) {
    srand(time(0));
    quicksortRPRecursive(array, 0, length - 1);
}