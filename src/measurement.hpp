#pragma once

#include <chrono>

struct Info {
    long double time = 0;
    long long comparisons = 0;
};

typedef std::chrono::_V2::steady_clock::time_point Time;

typedef std::chrono::duration<double, std::milli> milliseconds;

Time GetCurrTime();

double ElapsedTime(Time start, Time end);

int *CopyArr(int og[], int n);