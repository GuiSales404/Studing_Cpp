#pragma once

#include <cmath>
#include "utils.hpp"

int iParent(int i) {
    return floor((i-1) / 2);
}

int iLeftChild(int i) {
    return 2*i + 1;
}

int iRightChild(int i) {
    return 2*i + 2;
}

template <typename T>
void siftDown(T array[], int start, int end) {
    int root = start;

    while (iLeftChild(root) <= end)
    {
        int child = iLeftChild(root);
        int swap = root;

        if(array[swap] < array[child])
            swap = child;
        
        if(child + 1 <= end && array[swap] < array[child + 1])
            swap = child + 1;

        if(swap == root) {
            return;
        } else {
            swap_values(array[root], array[swap]);

            root = swap;
        }
    }
}

template <typename T>
void heapify(T array[], int n) {
    int start = iParent(n - 1);

    while (start >= 0)
    {
        siftDown(array, start, n - 1);
        start--;
    }
}

template <typename T>
void heapsort(T array[], int length) {
    heapify(array, length);

    int end = length - 1;
    while (end > 0)
    {
        swap_values(array[end], array[0]);
        end -= 1;

        siftDown(array, 0, end);
    }
}

