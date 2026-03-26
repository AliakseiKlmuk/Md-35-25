#include "utils.h"

long long findSumm(const int arr[], int n) {
    long long summ = 0;
    for (int i = 0; i < n; ++i) {
        summ += arr[i];
    }
    return summ;
}

int findMax(const int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(const int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void random_arr(int arr[], int n) {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 99);

    for (int i = 0; i < n; ++i) {
        arr[i] = dist(gen);
    }
}