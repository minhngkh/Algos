#include <string>
#include <fstream>
#include <vector>
#include <iostream>

void Command1(std::vector<std::string> algos, std::ifstream &inputFile, std::string outputMode);

void Command2(std::vector<std::string> algos, int dataSize, std::string dataOrder, std::string outputMode);

void Command3(std::vector<std::string> algos, int dataSize, std::string outputMode);

void Command4(std::string algo1, std::string algo2, std::ifstream &inputFile);

void Command5(std::string algo1, std::string algo2, int dataSize, std::string dataOrder);