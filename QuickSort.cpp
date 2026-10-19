#include <iostream>
#include <omp.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    #pragma omp parallel for shared(arr, low, high, pivot, i) default(none)
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            #pragma omp critical
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        #pragma omp parallel sections
        {
            #pragma omp section
            {
                quickSort(arr, low, pi - 1);
            }
            #pragma omp section
            {
                quickSort(arr, pi + 1, high);
            }
        }
    }
}

int main() {
    cout<<"Code by MSanathoi"<<endl;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
