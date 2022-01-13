#pragma once

#include <cmath>
#include <iostream>

template <typename T>
void insertionSort(T array[], int n)
{
    int i, j;
    T key;
    for (i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;
 
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

template <typename T>
int partitionInsertion(T array[], int low, int high) {
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
void introsortInsertionRecursive(T array[], int low, int high, int depthLimit) {
    if(high - low > 16) {
        if(depthLimit == 0) {
            heapsort(array + low, high - low + 1);
            return;
        }

        int p = partitionInsertion(array, low, high);
        introsortInsertionRecursive(array, low, p, depthLimit - 1);
        introsortInsertionRecursive(array, p + 1, high, depthLimit - 1);
    } else {
        insertionSort(array + low, high - low + 1);
    }
}

template <typename T>
void introsortInsertion(T array[], int length) {
    int depthLimit = 2 * integerLog2(length);
    introsortInsertionRecursive(array, 0, length - 1, depthLimit);
}