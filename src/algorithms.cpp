#include "algorithms.hpp"

void MergeWithoutCounting(int arr[], int const left, int const mid, int const right) {
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;
 
    // Create temp arrays
    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];
 
    int indexOfSubArrayOne = 0; // Initial index of first sub-array
    int indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void MergeWithCounting(int arr[], int const left, int const mid, int const right, int& comparisons) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    // Create temp arrays
    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne && ++comparisons; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < subArrayTwo && ++comparisons; j++)
        rightArray[j] = arr[mid + 1 + j];
 
    int indexOfSubArrayOne = 0; // Initial index of first sub-array
    int indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while ((indexOfSubArrayOne < subArrayOne && ++comparisons) 
        && (indexOfSubArrayTwo < subArrayTwo && ++comparisons)) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo] && ++comparisons) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne && ++comparisons) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo && ++comparisons) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}


void MergeSortWithoutCounting(int arr[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
 
    int mid = begin + (end - begin) / 2;
    MergeSortWithoutCounting(arr, begin, mid);
    MergeSortWithoutCounting(arr, mid + 1, end);
    MergeWithoutCounting(arr, begin, mid, end);
}


void MergeSortWithCounting(int arr[], int const begin, int const end, int &comparisons)
{
    if (begin >= end && ++comparisons)
        return; // Returns recursively
 
    int mid = begin + (end - begin) / 2;
    MergeSortWithCounting(arr, begin, mid, comparisons);
    MergeSortWithCounting(arr, mid + 1, end, comparisons);
    MergeWithCounting(arr, begin, mid, end, comparisons);
}

Info MergeSort(int arr[], int n) {
    Info result;

    MergeSortWithCounting(arr, 0, n - 1, result.comparisons);

    int *copy = CopyArr(arr, n);

    Time start = GetCurrTime();
    MergeSortWithoutCounting(copy, 0, n - 1);
    Time end = GetCurrTime();

    result.time = ElapsedTime(start, end);

    return result;
}