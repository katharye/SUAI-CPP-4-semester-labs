#ifndef MERGESORT_H
#define MERGESORT_H

template <typename type>
type* merge_sort(type* arr, int length);
template <typename type>
type* merge(type* left, int left_length, type* right, int right_length);

#endif