#include <iostream>

//rosnaco

void babelkowe(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//porownuje elementy oddalone o n - gap/shrink
void grzebieniowe(int arr[], int n) {
    int gap = n;
    float shrink = 1.3;
    bool swapped;

    do {
        gap = static_cast<int>(gap / shrink);
        if (gap < 1) {
            gap = 1;
        }

        swapped = false;

        for (int i = 0; i < n - gap; ++i) {
            if (arr[i] > arr[i + gap]) {
                std::swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    } while (gap > 1 || swapped);
}

void selekcja(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(arr[i], arr[minIndex]);
    }
}

int main() {
    return 0;
}