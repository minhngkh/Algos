#include "command.hpp"

using std::cout, std::string, std::ifstream;

Info Sort(string algo, int arr[], int n) {
    if (algo == "selection") return SelectionSort(arr, n);
    if (algo == "insertion") return InsertionSort(arr, n);
    if (algo == "bubble") return BubbleSort(arr, n);
    if (algo == "shaker") return ShakerSort(arr, n);
    if (algo == "shell") return ShellSort(arr, n);
    if (algo == "heap") return HeapSort(arr, n);
    if (algo == "merge") return MergeSort(arr, n);
    if (algo == "quick") return QuickSort(arr, n);
    if (algo == "counting") return CountingSort(arr, n);
    if (algo == "radix") return RadixSort(arr, n);
    if (algo == "flash") return FlashSort(arr, n);

    Info result{};
    return result;
}

void Command1(string algo, ifstream &inputFile, string outputMode) { cout << "ok"; }

void Command2(string algo, int dataSize, string dataOrder, string outputMode) { cout << "ok"; }

void Command3(string algo, int dataSize, string outputMode) {
    cout << "ALGORITHM MODE" << '\n';
    cout << "Algorithm: " << char(toupper(algo[0])) << algo.substr(1) << " sort" << '\n';
    cout << "Input size: " << dataSize << '\n';
    cout << '\n';
    for (int i = 0; i < NUM_DATA_ORDER; i++) {
        cout << "Input order: " << DATA_ORDERS[i] << '\n';
        cout << BREAK_LINE << '\n';

        // Run
        int *arr = new int[dataSize];

        GenerateData(arr, dataSize, i);

        Info sortResult = Sort(algo, arr, dataSize);

        delete[] arr;

        // Display result
        // Because all arguments have already had valid check in main(), there is no need to check for -both
        if (outputMode != "-comp") cout << "Running time: " << sortResult.time << '\n';
        if (outputMode != "-time") cout << "Comparisons: " << sortResult.comparisons << '\n';
        cout << '\n';
    }
}

void Command4(string algo1, string algo2, ifstream &inputFile) { cout << "ok"; }

void Command5(string algo1, string algo2, int dataSize, string dataOrder) { cout << "ok"; }