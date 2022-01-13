#pragma once

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
void printArray(T array[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        cout << array[i] << " ";
    cout << "\n";
}

template <typename T>
void swap_values(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
bool is_sorted(T array[], size_t array_size) {
    for (size_t i = 1; i < array_size; i++)
    {
        if(array[i - 1] > array[i]) return false;
    }
    return true;
}

template <typename T>
void inverse_array(T array[], size_t array_size) {
    size_t mid = ceil(array_size / 2.0);
    for (size_t i = 0; i < mid; i++)
    {
        swap_values(array[i], array[array_size - 1 - i]);
    }
}

int integerLog2(int number) {
    int i = 0;
    while (number > 1)
    {
        number = number >> 1;
        i++;
    }
    return i;
}

int pivo(int low, int high) {
    return (int)floor((high + low) / 2);
}
