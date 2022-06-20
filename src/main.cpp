#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "DataGenerator.hpp"
#include "algorithms.hpp"
#include "command.hpp"

using std::cout, std::string, std::vector, std::stringstream, std::ifstream, std::stoi;

bool NameConverter(string str, string &result) {
    stringstream ss(str);
    string name;

    getline(ss, name, '-');

    string temp;
    if (getline(ss, temp) && temp == "sort") {
        result = name;
        return true;
    }

    return false;
}

bool InArray(string str, vector<string> arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (str == arr[i]) return true;
    }

    return false;
}

int DisplayInvalidErr() {
    cout << "Invalid argument(s)";

    return 0;
}

int main(int argc, char **argv) {
    // int argc; char **argv;
    // std::cin >> argc;
    // argv = new char *[argc];

    // for (int i = 0; i < argc; i++) {
    //     argv[i] = new char[50];
    //     std::cin >> argv[i];
    // }

    const int MIN_ARGS = 5;
    const int MAX_ARGS = 6;
    const int MAX_DATA_SIZE = 1000000;
    const vector<string> validAlgos = {"selection", "insertion", "bubble",   "shaker", "shell", "heap",
                                       "merge",     "quick",     "counting", "radix",  "flash"};
    const vector<string> validOutputModes = {"-time", "-comp", "-both"};
    const vector<string> validInputOrders = {"-rand", "-nsorted", "-sorted", "-rev"};

    // Check number of arguments
    if (argc <= 1 || argc < MIN_ARGS) {
        cout << "Missing argument(s)";

        return 0;
    }

    if (argc > MAX_ARGS) return DisplayInvalidErr();

    // Check mode
    string mode = argv[1];

    if (mode == "-a") {
        // Check if all algorithms are valid
        string algo;
        if (!(NameConverter(argv[2], algo) && InArray(algo, validAlgos))) return DisplayInvalidErr();

        // Check if output mode is valid
        string outputMode = argv[argc - 1];

        if (!InArray(outputMode, validOutputModes)) return DisplayInvalidErr();

        // Check whether the input argument is a file path or a number
        ifstream ifs(argv[3]);

        if (ifs) {
            // check max number of arguments of command 1
            if (argc > 5)
                DisplayInvalidErr();
            else
                Command1(algo, ifs, argv[3], outputMode);

            ifs.close();

            return 0;
        }

        ifs.close();

        // Input argument is now probably a number
        // Check number of arguments to determine which command (2 or 3) to execute
        int dataSize;
        stringstream ss(argv[3]);
        ss >> dataSize;

        if (dataSize <= 0 || dataSize > MAX_DATA_SIZE) return DisplayInvalidErr();

        if (argc == 6) {
            // Check if input order is valid
            string inputOrder = argv[4];

            if (!InArray(inputOrder, validInputOrders))
                DisplayInvalidErr();
            else
                Command2(algo, dataSize, inputOrder, outputMode);

            return 0;
        }

        Command3(algo, dataSize, outputMode);

        return 0;

    } else if (mode == "-c") {
        // check if the 2 algorithms are valid
        string algo1, algo2;

        if (!(NameConverter(argv[2], algo1) && NameConverter(argv[3], algo2))) return DisplayInvalidErr();

        if (!(InArray(algo1, validAlgos) && InArray(algo2, validAlgos))) return DisplayInvalidErr();

        // Check whether the input argument is a file path or a number
        ifstream ifs(argv[4]);

        if (ifs) {
            Command4(algo1, algo2, ifs, argv[4]);

            ifs.close();
            return 0;
        }

        ifs.close();

        // Input argument is now probably a number
        int dataSize;
        stringstream ss(argv[4]);
        ss >> dataSize;

        if (dataSize <= 0 || dataSize > MAX_DATA_SIZE || argc < 6) return DisplayInvalidErr();

        // Check if input order is valid
        string inputOrder = argv[5];

        if (!InArray(inputOrder, validInputOrders))
            DisplayInvalidErr();
        else
            Command5(algo1, algo2, dataSize, inputOrder);

        return 0;
    }

    return DisplayInvalidErr();
}