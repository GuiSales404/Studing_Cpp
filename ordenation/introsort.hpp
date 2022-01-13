#pragma once

#include <cmath>
#include <iostream>

template <typename T>
int partition(T array[], int low, int high) {
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
void introsortRecursive(T array[], int low, int high, int depthLimit) {
    if(low < high) {
        if(depthLimit == 0) {
            heapsort(array + low, high - low + 1);
            return;
        }

        int p = partition(array, low, high);
        introsortRecursive(array, low, p, depthLimit - 1);
        introsortRecursive(array, p + 1, high, depthLimit - 1);
    }
}

template <typename T>
void introsort(T array[], int length) {
    int depthLimit = 2 * integerLog2(length);
    introsortRecursive(array, 0, length - 1, depthLimit);
}