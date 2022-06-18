#include "measurement.hpp"

Time GetCurrTime() { return std::chrono::steady_clock::now(); }

double ElapsedTime(Time start, Time end) {
    std::chrono::duration<double, std::milli> interval = end - start;
    return double(interval.count());
}

int *CopyArr(int og[], int n) {
    int *copy = new int[n];

    for (int i = 0; i < n; i++) {
        copy[i] = og[i];
    }

    return copy;
}