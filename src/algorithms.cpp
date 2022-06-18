#include "algorithms.hpp"

void Swap(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

// Selection sort
void SelectionSortWithoutCounting(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int cur_min = i;

        for (int j = i + 1; j < n; ++j)
            if (arr[cur_min] > arr[j]) cur_min = j;
        Swap(arr[cur_min], arr[i]);
    }
}

void SelectionSortWithCounting(int arr[], int n, long long &comparisons) {
    comparisons = 0;
    for (int i = 0; ++comparisons && (i < n - 1); ++i) {
        int cur_min = i;

        for (int j = i + 1; ++comparisons && (j < n); ++j)
            if (++comparisons && arr[cur_min] > arr[j]) cur_min = j;
        Swap(arr[cur_min], arr[i]);
    }
}

Info SelectionSort(int arr[], int n) {
    Info result;
    int *copy = CopyArr(arr, n);

    SelectionSortWithCounting(arr, n, result.comparisons);

    Time start = GetCurrTime();
    SelectionSortWithoutCounting(copy, n);
    Time end = GetCurrTime();

    result.time = ElapsedTime(start, end);

    delete[] copy;

    return result;
}

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

void InsertionSortWithCounting(int arr[], int n, long long &comparisons) {
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
    int *copy = CopyArr(arr, n);

    InsertionSortWithCounting(arr, n, result.comparisons);

    Time start = GetCurrTime();
    InsertionSortWithoutCounting(copy, n);
    Time end = GetCurrTime();

    result.time = ElapsedTime(start, end);

    delete[] copy;
    
    return result;
}

// Bubble sort
void BubbleSortWithoutCounting(int arr[], int n) {
    for (int j = n; j > 1; --j)
        for (int i = 1; i < j; ++i)
            if (arr[i - 1] > arr[i]) Swap(arr[i - 1], arr[i]);
}

void BubbleSortWithCounting(int arr[], int n, long long &comparisons) {
    comparisons = 0;
    for (int j = n; ++comparisons && j > 1; --j)
        for (int i = 1; ++comparisons && i < j; ++i)
            if (arr[i - 1] > arr[i]) Swap(arr[i - 1], arr[i]);
}

Info BubbleSort(int arr[], int n) {
    Info result;
    int *copy = CopyArr(arr, n);

    BubbleSortWithCounting(arr, n, result.comparisons);

    Time start = GetCurrTime();
    BubbleSortWithoutCounting(copy, n);
    Time end = GetCurrTime();

    result.time = ElapsedTime(start, end);

    delete[] copy;

    return result;
}

// Shaker sort
void ShakerSortWithoutCounting(int arr[], int n) {
    int left = 1, right = n - 1, k = n - 1;

    do {
        for (int j = right; j >= left; --j)
            if (arr[j - 1] > arr[j]) {
                Swap(arr[j - 1], arr[j]);
                k = j;
            }  // Smaller elements to the top

        left = k + 1;

        for (int j = left; j <= right; ++j)
            if (arr[j - 1] > arr[j]) {
                Swap(arr[j - 1], arr[j]);
                k = j;
            }  // Larger elements to the end

        right = k - 1;
    } while (left <= right);
}

void ShakerSortWithCounting(int arr[], int n, long long &comparisons) {
    int left = 1, right = n - 1, k = n - 1;

    do {
        for (int j = right; ++comparisons && j >= left; --j)
            if (++comparisons && arr[j - 1] > arr[j]) {
                Swap(arr[j - 1], arr[j]);
                k = j;
            }  // Smaller elements to the top

        left = k + 1;

        for (int j = left; ++comparisons && j <= right; ++j)
            if (++comparisons && arr[j - 1] > arr[j]) {
                Swap(arr[j - 1], arr[j]);
                k = j;
            }  // Larger elements to the end

        right = k - 1;
    } while (++comparisons && left <= right);
}

Info ShakerSort(int arr[], int n) {
    Info result;
    int *copy = CopyArr(arr, n);

    ShakerSortWithCounting(arr, n, result.comparisons);

    Time start = GetCurrTime();
    ShakerSortWithoutCounting(copy, n);
    Time end = GetCurrTime();

    result.time = ElapsedTime(start, end);

    delete[] copy;

    return result;
}

// Shell sort
void ShellSortWithoutCounting(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int ShellSortWithCounting(int arr[], int n, long long &comparisons) {
    comparisons = 0;
    for (int gap = n / 2; ++comparisons && gap > 0; gap /= 2) {
        for (int i = gap; ++comparisons && i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; ++comparisons && j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}

Info ShellSort(int arr[], int n) {
    Info result;
    int *copy = CopyArr(arr, n);

    ShellSortWithCounting(arr, n, result.comparisons);

    Time start = GetCurrTime();
    ShellSortWithoutCounting(copy, n);
    Time end = GetCurrTime();

    result.time = ElapsedTime(start, end);

    delete[] copy;

    return result;
}

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
        Swap(arr[largerChild], arr[start]);
        HeapRebuildWithoutCounting(largerChild, arr, n);  // Recursion at that child
    }
}

void HeapSortWithoutCounting(int arr[], int n) {
    // Build initial heap
    for (int index = (n - 1) / 2; index >= 0; index--)
        HeapRebuildWithoutCounting(index, arr, n);
    Swap(arr[0], arr[n - 1]);  // swap the largest element to the end
    int heapSize = n - 1;      // Heap region size decreases by 1
    while (heapSize > 1) {
        HeapRebuildWithoutCounting(0, arr, heapSize);
        heapSize--;
        Swap(arr[0], arr[heapSize]);
    }
}

void HeapRebuildWithCounting(int start, int arr[], int n, long long &comparisons) {
    int leftChild = 2 * start + 1;
    if (++comparisons && leftChild >= n) return;
    int largerChild = leftChild;
    int rightChild = 2 * start + 2;
    if (++comparisons && rightChild < n) {
        if (++comparisons && arr[rightChild] > arr[largerChild]) largerChild = rightChild;
    }
    if (++comparisons && arr[start] < arr[largerChild]) {
        Swap(arr[largerChild], arr[start]);
        HeapRebuildWithCounting(largerChild, arr, n, comparisons);
    }
}

void HeapSortWithCounting(int arr[], int n, long long &comparisons) {
    comparisons = 0;
    int index;
    for (index = (n - 1) / 2; ++comparisons && index >= 0; index--) {
        HeapRebuildWithCounting(index, arr, n, comparisons);
    }

    Swap(arr[0], arr[n - 1]);
    int heapSize = n - 1;
    while (heapSize > 1 && ++comparisons) {
        HeapRebuildWithCounting(0, arr, heapSize, comparisons);
        heapSize--;
        Swap(arr[0], arr[heapSize]);
    }
}

Info HeapSort(int arr[], int n) {
    Info result;
    int *copy = CopyArr(arr, n);

    HeapSortWithCounting(arr, n, result.comparisons);

    Time start = GetCurrTime();
    HeapSortWithoutCounting(copy, n);
    Time end = GetCurrTime();

    result.time = ElapsedTime(start, end);
    
    delete[] copy;

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
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];

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

void MergeWithCounting(int arr[], int const left, int const mid, int const right, long long &comparisons) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; ++comparisons && i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; ++comparisons && j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];

    int indexOfSubArrayOne = 0;     // Initial index of first sub-array
    int indexOfSubArrayTwo = 0;     // Initial index of second sub-array
    int indexOfMergedArray = left;  // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while ((++comparisons && indexOfSubArrayOne < subArrayOne) && (++comparisons && indexOfSubArrayTwo < subArrayTwo)) {
        if (++comparisons && leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
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
    while (++comparisons && indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (++comparisons && indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void MergeSortWithCounting(int arr[], int const begin, int const end, long long &comparisons) {
    if (++comparisons && begin >= end) return;  // Returns recursively

    int mid = begin + (end - begin) / 2;
    MergeSortWithCounting(arr, begin, mid, comparisons);
    MergeSortWithCounting(arr, mid + 1, end, comparisons);
    MergeWithCounting(arr, begin, mid, end, comparisons);
}

Info MergeSort(int arr[], int n) {
    Info result;
    int *copy = CopyArr(arr, n);

    MergeSortWithCounting(arr, 0, n - 1, result.comparisons);

    Time start = GetCurrTime();
    MergeSortWithoutCounting(copy, 0, n - 1);
    Time end = GetCurrTime();

    result.time = ElapsedTime(start, end);

    delete[] copy;

    return result;
}

// Quick sort
int PartitionWithoutCounting(int arr[], int low, int high) {
    int i = low;
    int j = high;
    int pivot = arr[low];
    while (i < j) {
        while (pivot >= arr[i])
            i++;
        while (pivot < arr[j])
            j--;
        if (i < j) Swap(arr[i], arr[j]);
    }
    Swap(arr[low], arr[j]);
    return j;
}

void QuickSortWithoutCounting(int arr[], int low, int high) {
    if (low < high) {
        int pivot = PartitionWithoutCounting(arr, low, high);
        QuickSortWithoutCounting(arr, low, pivot - 1);
        QuickSortWithoutCounting(arr, pivot + 1, high);
    }
}

int PartitionWithCounting(int arr[], int low, int high, long long &comparisons) {
    int i = low;
    int j = high;
    int pivot = arr[low];
    while (++comparisons && i < j) {
        while (++comparisons && pivot >= arr[i])
            i++;
        while (++comparisons && pivot < arr[j])
            j--;
        if (++comparisons && i < j) Swap(arr[i], arr[j]);
    }
    Swap(arr[low], arr[j]);
    return j;
}

void QuickSortWithCounting(int arr[], int low, int high, long long &comparisons) {
    if (++comparisons && low < high) {
        int pivot = PartitionWithCounting(arr, low, high, comparisons);
        QuickSortWithCounting(arr, low, pivot - 1, comparisons);
        QuickSortWithCounting(arr, pivot + 1, high, comparisons);
    }
}

Info QuickSort(int arr[], int n) {
    Info result;
    int *copy = CopyArr(arr, n);

    QuickSortWithCounting(arr, 0, n - 1, result.comparisons);

    Time start = GetCurrTime();
    QuickSortWithoutCounting(copy, 0, n - 1);
    Time end = GetCurrTime();

    result.time = ElapsedTime(start, end);

    delete[] copy;

    return result;
}

// Counting sort
int SearchMaxWithoutCounting(int arr[], int n) {
    int Max(0);
    for (int i = 0; i < n; i++) {
        if (arr[i] > Max) {
            Max = arr[i];
        }
    }
    return Max;
}

void CountingSortWithoutCounting(int arr[], int n) {
    int u = SearchMaxWithoutCounting(arr, n);
    int *f = new int[u + 1]{0};
    for (int i = 0; i < n; i++)
        f[arr[i]]++;
    for (int i = 1; i <= u; i++)
        f[i] = f[i - 1] + f[i];
    int *b = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        b[f[arr[i]] - 1] = arr[i];
        f[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = b[i];
}

int SearchMaxWithCounting(int arr[], int n, long long &comparisons) {
    int Max(0);
    for (int i = 0; i < n && ++comparisons; i++) {
        if (arr[i] > Max && ++comparisons) {
            Max = arr[i];
        }
    }
    return Max;
}

void CountingSortWithCounting(int arr[], int n, long long &comparisons) {
    comparisons = 0;
    int u = SearchMaxWithCounting(arr, n, comparisons);
    int *f = new int[u + 1]{0};
    for (int i = 0; ++comparisons && i < n; i++)
        f[arr[i]]++;
    for (int i = 1; ++comparisons && i <= u; i++)
        f[i] = f[i - 1] + f[i];
    int *b = new int[n];
    for (int i = n - 1; ++comparisons && i >= 0; i--) {
        b[f[arr[i]] - 1] = arr[i];
        f[arr[i]]--;
    }
    for (int i = 0; ++comparisons && i < n; i++)
        arr[i] = b[i];
}

Info CountingSort(int arr[], int n) {
    Info result;
    int *copy = CopyArr(arr, n);

    CountingSortWithCounting(arr, n, result.comparisons);

    Time start = GetCurrTime();
    CountingSortWithoutCounting(copy, n);
    Time end = GetCurrTime();

    result.time = ElapsedTime(start, end);

    delete[] copy;

    return result;
}

// Radix sort
int PowWithoutCounting(int num, int exp) {
    int result = 1;

    for (int i = 0; i < exp; i++) {
        result *= num;
    }

    return result;
}

void RadixSortWithoutCounting(int arr[], int n) {
    int max_val = arr[0];  // get maximum value in the array

    for (int i = 1; i < n; ++i)
        if (arr[i] > max_val) max_val = arr[i];

    int digits = 0, div;  // find the maximum number of digits

    do {
        digits++;
        div = max_val / PowWithoutCounting(10, digits);
    } while (div > 0);

    int *tempArr[10];  // declare variables for temp store

    for (int i = 0; i < 10; ++i)
        tempArr[i] = new int[n];

    int tempCount[10];

    // form groups of numbers and combine groups
    for (int i = 0; i < digits; ++i) {
        int exp = PowWithoutCounting(10, i);

        for (int j = 0; j < 10; ++j)
            tempCount[j] = 0;  // reset the counting

        for (int j = 0; j < n; ++j) {  // form groups
            int idx = (arr[j] / exp) % 10;
            tempArr[idx][tempCount[idx]++] = arr[j];
        }

        int idx = 0;  // combine groups
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < tempCount[j]; ++k)
                arr[idx++] = tempArr[j][k];
    }
}

int PowWithCounting(int num, int exp, long long &comparisons) {
    int result = 1;

    for (int i = 0; ++comparisons && i < exp; i++) {
        result *= num;
    }

    return result;
}

void RadixSortWithCounting(int arr[], int n, long long &comparisons) {
    int max_val = arr[0];  // get maximum value in the array

    for (int i = 1; ++comparisons && i < n; ++i)
        if (++comparisons && arr[i] > max_val) max_val = arr[i];

    int digits = 0, div;  // find the maximum number of digits

    do {
        digits++;
        div = max_val / PowWithCounting(10, digits, comparisons);
    } while (++comparisons && div > 0);

    int *tempArr[10];  // declare variables for temp store

    for (int i = 0; ++comparisons && i < 10; ++i)
        tempArr[i] = new int[n];

    int tempCount[10];

    // form groups of numbers and combine groups
    for (int i = 0; ++comparisons && i < digits; ++i) {
        int exp = PowWithCounting(10, i, comparisons);

        for (int j = 0; ++comparisons && j < 10; ++j)
            tempCount[j] = 0;  // reset the counting

        for (int j = 0; ++comparisons && j < n; ++j) {  // form groups
            int idx = (arr[j] / exp) % 10;
            tempArr[idx][tempCount[idx]++] = arr[j];
        }

        int idx = 0;  // combine groups
        for (int j = 0; ++comparisons && j < 10; ++j)
            for (int k = 0; ++comparisons && k < tempCount[j]; ++k)
                arr[idx++] = tempArr[j][k];
    }
}

Info RadixSort(int arr[], int n) {
    Info result;
    int *copy = CopyArr(arr, n);

    RadixSortWithCounting(arr, n, result.comparisons);

    Time start = GetCurrTime();
    RadixSortWithoutCounting(copy, n);
    Time end = GetCurrTime();

    result.time = ElapsedTime(start, end);

    delete[] copy;

    return result;
}

// Flash sort
void FlashSortWithoutCounting(int arr[], int n) {
    int *__L = new int[n];
    if (n <= 1) return;
    int m = n * 0.43;
    if (m <= 2) m = 2;
    // int m = n;
    for (int i = 0; i < m; ++i)
        __L[i] = 0;
    int Mx = arr[0], Mn = arr[0];
    for (int i = 1; i < n; ++i) {
        if (Mx < arr[i]) Mx = arr[i];
        if (Mn > arr[i]) Mn = arr[i];
    }
    if (Mx == Mn) return;

#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)

    for (int i = 0; i < n; ++i)
        ++__L[getK(arr[i])];
    for (int i = 1; i < m; ++i)
        __L[i] += __L[i - 1];
    // step 2
    int count = 0;
    int i = 0;
    while (count < n) {
        int k = getK(arr[i]);
        while (i >= __L[k])
            k = getK(arr[++i]);
        int z = arr[i];
        while (i != __L[k]) {
            k = getK(z);
            int y = arr[__L[k] - 1];
            arr[--__L[k]] = z;
            z = y;
            ++count;
        }
    }
    // step 3
    for (int k = 1; k < m; ++k) {
        for (int i = __L[k] - 2; i >= __L[k - 1]; --i)
            if (arr[i] > arr[i + 1]) {
                int t = arr[i], j = i;
                while (t > arr[j + 1]) {
                    arr[j] = arr[j + 1];
                    ++j;
                }
                arr[j] = t;
            }
    }
}

void FlashSortWithCounting(int arr[], int n, long long &comparisons) {
    int *__L = new int[n];
    if (n <= 1) return;
    int m = n * 0.43;
    if (m <= 2) {
        m = 2;
    }
    // int m = n;
    for (int i = 0; i < m; ++i)
        __L[i] = 0;
    int Mx = arr[0];
    int Mn = arr[0];
    for (int i = 1; i < n; ++i) {
        if (Mx < arr[i]) {
            Mx = arr[i];
        }
        if (Mn > arr[i]) {
            Mn = arr[i];
        }
    }
    if (Mx == Mn) return;

#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)

    for (int i = 0; ++comparisons && (i < n); ++i) {
        ++__L[getK(arr[i])];
    }

    for (int i = 1; ++comparisons && (i < m); ++i) {
        __L[i] += __L[i - 1];
    }

    // step 2
    int count = 0;
    int i = 0;
    while (++comparisons && count < n) {
        int k = getK(arr[i]);
        while (++comparisons && (i >= __L[k])) {
            k = getK(arr[++i]);
        }

        int z = arr[i];

        while (++comparisons && (i != __L[k])) {
            k = getK(z);
            int y = arr[__L[k] - 1];
            arr[--__L[k]] = z;
            z = y;
            ++count;
        }
    }
    // step 3
    for (int k = 1; ++comparisons && (k < m); ++k) {
        for (int i = __L[k] - 2; ++comparisons && (i >= __L[k - 1]); --i)
            if (++comparisons && (arr[i] > arr[i + 1])) {
                int t = arr[i], j = i;
                while (++comparisons && (t > arr[j + 1])) {
                    arr[j] = arr[j + 1];
                    ++j;
                }
                arr[j] = t;
            }
    }
}

Info FlashSort(int arr[], int n) {
    Info result;
    int *copy = CopyArr(arr, n);

    FlashSortWithCounting(arr, n, result.comparisons);

    Time start = GetCurrTime();
    FlashSortWithoutCounting(copy, n);
    Time end = GetCurrTime();

    result.time = ElapsedTime(start, end);

    delete[] copy;

    return result;
}
