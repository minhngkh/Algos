#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "DataGenerator.hpp"
#include "algorithms.hpp"

#define NUM_DATA_ORDER 4

// I have to do this due to inconsistent numbering in the teacher provided cpp file (DataGenerator.cpp) and pdf file
const std::vector<std::vector<std::string>> DATA_ORDERS = {{"Randomized", "1", "-rand"},
                                                           {"Sorted", "3", "-sorted"},
                                                           {"Reverse sorted", "4", "-rev"},
                                                           {"Nearly sorted", "2", "-nsorted"}};

const std::string BREAK_LINE = std::string(25, '-');

void Command1(std::string algo, std::ifstream &inputFile, std::string outputMode);

void Command2(std::string algo, int dataSize, std::string dataOrder, std::string outputMode);

void Command3(std::string algo, int dataSize, std::string outputMode);

void Command4(std::string algo1, std::string algo2, std::ifstream &inputFile);

void Command5(std::string algo1, std::string algo2, int dataSize, std::string dataOrder);