#include "DataGenerator.hpp"
#include "algorithms.hpp"
#include <iostream>

using std::cout;

int main() {
    cout << "HELLO" << '\n';

    int *a = new int[2000];
    GenerateData(a, 2000, 1);

    Info result = MergeSort(a, 2000);

    cout << "time: " << result.time << '\n' << "comparisons: " << result.comparisons;
    
    return 0;
}