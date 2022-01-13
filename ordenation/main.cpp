#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include "utils.hpp"
#include "heapsort.hpp"
#include "quicksortFP.hpp"
#include "quicksortRP.hpp"
#include "introsort.hpp"
#include "introsortInsertion.hpp"

using namespace std;

template <typename T>
bool generate_worst_case(T array[], size_t array_size) {
    // Array que armazena valores aleatorios ordenados
    T *rand_sorted_array;

    try
    {
        rand_sorted_array = new T[array_size];
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        return false;
    }

    for (size_t i = 0; i < array_size; i++) 
        rand_sorted_array[i] = rand();
    heapsort(rand_sorted_array, array_size);

    //Array que acontecera a simulacao de quicksort
    int *quicksort_array;

    try
    {
        quicksort_array = new int[array_size];
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
        delete[] rand_sorted_array;
        return false;
    }

    // Armazena o proprio indice em cada posicao
    for (size_t i = 0; i < array_size; i++)
        quicksort_array[i] = i;
    

    for (size_t i = 0; i < array_size; i++)
    {

        int pivot_index = pivo(i, array_size - 1);
        //Pega o primeiro valor aleatorio e armazena no index que o quicksort_array[pivot_index] estava guardando
        array[quicksort_array[pivot_index]] = rand_sorted_array[i];
        //Troca o quicksort_array[pivot_index] com o "primeiro elemento"
        swap_values(quicksort_array[i], quicksort_array[pivot_index]);
    }

    delete[] rand_sorted_array;
    delete[] quicksort_array;
    return true;
}

template <typename T, typename F>
clock_t sort_time_measurement(T array[], size_t array_size, F sort_f) {
    // Reserva a memoria e faz uma copia do array
    T *array_copy;
    try
    {
        array_copy = new T[array_size];
    }
    catch(const exception& e)
    {
       cerr << e.what() << '\n';
       return 0;
    }
    memcpy(array_copy, array, sizeof(T) * array_size);
    
    // Mede o tempo de sorting
    clock_t begin = clock();
    sort_f(array_copy, array_size);
    clock_t end = clock();

    //Checa o sorting
    if(!is_sorted(array_copy, array_size)) {
        cerr << "[Error]: Sorting Error." << endl;
    }

    delete[] array_copy;
    return end - begin;
}

int main(int argc, char const *argv[])
{
    if(argc < 4) return 1;

    char instance_type = argv[1][0]; // [Tipo de Instancia]
    size_t array_size = atol(argv[2]); // [Tamanho do Vetor]
    size_t instance_amount = atol(argv[3]); // [Numero de Instancias]

    clock_t heapsort_elapsed_time = 0, quicksortFP_elapsed_time = 0, quicksortRP_elapsed_time = 0, introsort_insertionsort_elapsed_time = 0, introsort_elapsed_time = 0;

    // Reserva a memoria do array principal
    int *array;
    try
    {
        array = new int[array_size];
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }

    srand(time(0));

    for (size_t i = 0; i < instance_amount; i++)
    {
        switch (instance_type)
        {
        case 'A':
            // Aleatório
            for (size_t k = 0; k < array_size; k++)
                array[k] = rand();

            break;
        case 'C':
            // Ordem Crescente
            for (size_t k = 0; k < array_size; k++)
                array[k] = rand();
                
            heapsort(array, array_size);
            break;
        case 'D':
            // Ordem Decrescente
            for (size_t k = 0; k < array_size; k++)
                array[k] = rand();
                
            heapsort(array, array_size);
            inverse_array(array, array_size);
            break;
        case 'P':
            // Pior Caso
            generate_worst_case(array, array_size);
            break;
        default:
            return 1;
        }

        // HeapSort
        heapsort_elapsed_time += sort_time_measurement<int, void(*)(int*, int)>(array, array_size, heapsort);
        //Quicksort Fixed Pivot
        quicksortFP_elapsed_time += sort_time_measurement<int, void(*)(int*, int)>(array, array_size, quicksortFP);
        //Quicksort Random Pivot
        quicksortRP_elapsed_time += sort_time_measurement<int, void(*)(int*, int)>(array, array_size, quicksortRP);
        // Introsort
        introsort_elapsed_time += sort_time_measurement<int, void(*)(int*, int)>(array, array_size, introsort);
        // Introsort with Insertion Sort
        introsort_insertionsort_elapsed_time += sort_time_measurement<int, void(*)(int*, int)>(array, array_size, introsortInsertion);

    }

    cout << "heapsort_elapsed_time: " << (double)heapsort_elapsed_time / CLOCKS_PER_SEC << endl;
    cout << "quicksortFP_elapsed_time: " << (double)quicksortFP_elapsed_time / CLOCKS_PER_SEC << endl;
    cout << "quicksortRP_elapsed_time: " << (double)quicksortRP_elapsed_time / CLOCKS_PER_SEC << endl;
    cout << "introsort_elapsed_time: " << (double)introsort_elapsed_time / CLOCKS_PER_SEC << endl;
    cout << "introsort_insertionsort_elapsed_time: " << (double)introsort_insertionsort_elapsed_time / CLOCKS_PER_SEC << endl;
    

    delete[] array;
    return 0;
}