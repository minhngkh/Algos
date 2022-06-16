#include "algorithms.hpp"

// Selection sort

// Insertion sort
void InsertionSortWithoutCounting(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void InsertionSortWithCounting(int arr[], int n, int &comparisons) {
    comparisons = 0;

    int i;
    int key;
    int j;
    for (i = 1; ++comparisons && i < n; i++) {
        key = arr[i];
        j = i - 1;
        while ((++comparisons && j >= 0) && (arr[j] > key && ++comparisons)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

Info InsertionSort(int arr[], int n) {
    Info result;

    InsertionSortWithCounting(arr, n, result.comparisons);

    int *copy = CopyArr(arr, n);

    Time start = GetCurrTime();
    InsertionSortWithoutCounting(arr, n);
    Time end = GetCurrTime();

    result.time = ElapsedTime(start, end);

    return result;
}

// Bubble sort

// Shaker sort

// Shell sort

// Heap sort
void HeapRebuildWithoutCounting(int start, int arr[], int n) {
    int leftChild = 2 * start + 1;  // A left child must exist
    if (leftChild >= n) return;
    int largerChild = leftChild;     // Make assumption about larger child
    int rightChild = 2 * start + 2;  // A right child might not exist
    if (rightChild < n) {            // Whether a right child exists
                                     // A right child exists; check whether it is larger
        if (arr[rightChild] > arr[largerChild]) largerChild = rightChild;  // Assumption was wrong
    }
    // If arr[start] is smaller than the larger child, swap values
    if (arr[start] < arr[largerChild]) {
        std::swap(arr[largerChild], arr[start]);
        HeapRebuildWithoutCounting(largerChild, arr, n);  // Recursion at that child
    }
}

void HeapSortWithoutCounting(int arr[], int n) {
    // Build initial heap
    for (int index = (n - 1) / 2; index >= 0; index--) HeapRebuildWithoutCounting(index, arr, n);
    std::swap(arr[0], arr[n - 1]);  // swap the largest element to the end
    int heapSize = n - 1;           // Heap region size decreases by 1
    while (heapSize > 1) {
        HeapRebuildWithoutCounting(0, arr, heapSize);
        heapSize--;
        std::swap(arr[0], arr[heapSize]);
    }
}

void HeapRebuildWithCounting(int start, int arr[], int n, int &comparisons) {
    int leftChild = 2 * start + 1;
    if (++comparisons && leftChild >= n) return;
    int largerChild = leftChild;
    int rightChild = 2 * start + 2;
    if (++comparisons && rightChild < n) {
        if (++comparisons && arr[rightChild] > arr[largerChild]) largerChild = rightChild;
    }
    if (++comparisons && arr[start] < arr[largerChild]) {
        std::swap(arr[largerChild], arr[start]);
        HeapRebuildWithCounting(largerChild, arr, n, comparisons);
    }
}

void HeapSortWithCounting(int arr[], int n, int &comparisons) {
    comparisons = 0;
    int index;
    for (index = (n - 1) / 2; ++comparisons && index >= 0; index--) {
        HeapRebuildWithCounting(index, arr, n, comparisons);
    }

    std::swap(arr[0], arr[n - 1]);
    int heapSize = n - 1;
    while (heapSize > 1 && ++comparisons) {
        HeapRebuildWithCounting(0, arr, heapSize, comparisons);
        heapSize--;
        std::swap(arr[0], arr[heapSize]);
    }
}

Info HeapSort(int arr[], int n) {
    Info result;

    HeapSortWithCounting(arr, n, result.comparisons);

    Time start = GetCurrTime();
    HeapSortWithoutCounting(arr, n);
    Time end = GetCurrTime();

    result.time = ElapsedTime(start, end);

    return result;
}

// Merge sort
void MergeWithoutCounting(int arr[], int const left, int const mid, int const right) {
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    // Create temp arrays
    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++) leftArray[i] = arr[left + i];
    for (int j = 0; j < subArrayTwo; j++) rightArray[j] = arr[mid + 1 + j];

    int indexOfSubArrayOne = 0;     // Initial index of first sub-array
    int indexOfSubArrayTwo = 0;     // Initial index of second sub-array
    int indexOfMergedArray = left;  // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
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

void MergeSortWithoutCounting(int arr[], int const begin, int const end) {
    if (begin >= end) return;  // Returns recursively

    int mid = begin + (end - begin) / 2;
    MergeSortWithoutCounting(arr, begin, mid);
    MergeSortWithoutCounting(arr, mid + 1, end);
    MergeWithoutCounting(arr, begin, mid, end);
}

void MergeWithCounting(int arr[], int const left, int const mid, int const right, int &comparisons) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne && ++comparisons; i++) leftArray[i] = arr[left + i];
    for (int j = 0; j < subArrayTwo && ++comparisons; j++) rightArray[j] = arr[mid + 1 + j];

    int indexOfSubArrayOne = 0;     // Initial index of first sub-array
    int indexOfSubArrayTwo = 0;     // Initial index of second sub-array
    int indexOfMergedArray = left;  // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while ((indexOfSubArrayOne < subArrayOne && ++comparisons) && (indexOfSubArrayTwo < subArrayTwo && ++comparisons)) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo] && ++comparisons) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
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

void MergeSortWithCounting(int arr[], int const begin, int const end, int &comparisons) {
    if (begin >= end && ++comparisons) return;  // Returns recursively

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

// Quick sort

// Counting sort
/*
void CountingSortWithoutCounting(int arr[], int n, int u) {
    int *f = new int[u + 1]{0};
    for (int i = 0; i < n; i++) f[arr[i]]++;
    for (int i = 1; i <= u; i++) f[i] = f[i - 1] + f[i];
    int *b = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        b[f[arr[i]] - 1] = arr[i];
        f[arr[i]]--;
    }
    for (int i = 0; i < n; i++) arr[i] = b[i];
}

void CountingSortWithCounting(int arr[], int n, int u, int &comparisons) {
    comparisons = 0;
    int *f = new int[u + 1]{0};
    for (int i = 0; ++comparisons && i < n; i++) f[arr[i]]++;
    for (int i = 1; ++comparisons && i <= u; i++) f[i] = f[i - 1] + f[i];
    int *b = new int[n];
    for (int i = n - 1; ++comparisons && i >= 0; i--) {
        b[f[arr[i]] - 1] = arr[i];
        f[arr[i]]--;
    }
    for (int i = 0; ++comparisons && i < n; i++) arr[i] = b[i];
}

Info CountingSort(int arr[], int n) {
    Info result;

    CountingSortWithCounting(arr, n, result.comparisons);

    Time start = GetCurrTime();
    CountingSortWithoutCounting(arr, n);
    Time end = GetCurrTime();
}
*/

// Radix sort

// Flash sort