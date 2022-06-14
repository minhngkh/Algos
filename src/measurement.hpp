#pragma once

#include <chrono>

struct Info {
    double time = 0;
    int comparisons = 0;
};

typedef std::chrono::_V2::steady_clock::time_point Time;

Time GetCurrTime();
double ElapsedTime(Time start, Time end);

int *CopyArr(int og[], int n);