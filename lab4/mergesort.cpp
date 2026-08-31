#include "mergesort.h"

#include <iostream>
#include <stdexcept>
#include <string>

template <typename type>
type* merge_sort(type* arr, int length) {
    if (!arr) throw std::invalid_argument("Null pointer");
    if (length < 0) throw std::invalid_argument("Invalid length");

    if (length <= 1) {
        type* result = new type[length];
        if (length > 0) result[0] = arr[0];
        return result;
    }

    int left_length = length / 2;
    int right_length = length - left_length;

    type* left = new type[left_length];
    type* right = new type[right_length];

    for (int i = 0; i < left_length; i++) left[i] = arr[i];
    for (int i = 0; i < right_length; i++) right[i] = arr[i + left_length];

    type* sorted_left = merge_sort(left, left_length);
    type* sorted_right = merge_sort(right, right_length);

    delete[] left;
    delete[] right;

    type* sorted_array = merge(sorted_left, left_length, sorted_right, right_length);

    delete[] sorted_left;
    delete[] sorted_right;

    return sorted_array;
}

template <typename type>
type* merge(type* left, int left_length, type* right, int right_length) {
    type* merged = new type[left_length + right_length];
    int i = 0, j = 0, k = 0;

    while (i < left_length && j < right_length) {
        if (left[i] <= right[j]) {
            merged[k++] = left[i++];
        } else {
            merged[k++] = right[j++];
        }
    }

    while (i < left_length) {
        merged[k++] = left[i++];
    }

    while (j < right_length) {
        merged[k++] = right[j++];
    }

    return merged;
}

template int* merge<int>(int*, int, int*, int);
template char* merge<char>(char*, int, char*, int);
template float* merge<float>(float*, int, float*, int);
template double* merge<double>(double*, int, double*, int);
template std::string* merge<std::string>(std::string[], int, std::string[], int);

template int* merge_sort<int>(int*, int);
template char* merge_sort<char>(char*, int);
template float* merge_sort<float>(float*, int);
template double* merge_sort<double>(double*, int);
template std::string* merge_sort<std::string>(std::string[], int);