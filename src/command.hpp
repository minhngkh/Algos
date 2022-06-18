#include "algorithms.hpp"
#include "DataGenerator.hpp"

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

#define NUM_DATA_ORDER 4
const std::vector<std::string> DATA_ORDERS = {"Randomized", "Sorted", "Reverse sorted", "Nearly sorted"};

const std::string BREAK_LINE = std::string(25, '-');

void Command1(std::string algo, std::ifstream &inputFile, std::string outputMode);

void Command2(std::string algo, int dataSize, std::string dataOrder, std::string outputMode);

void Command3(std::string algo, int dataSize, std::string outputMode);

void Command4(std::string algo1, std::string algo2, std::ifstream &inputFile);

void Command5(std::string algo1, std::string algo2, int dataSize, std::string dataOrder);