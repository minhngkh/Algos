#include "command.hpp"

using std::cout, std::string, std::ifstream, std::fstream, std::ofstream;

void WriteFile(int arr[], int n, string fileName) {
    ofstream ofs(fileName);
    if (!ofs) {
        ofs.close();
        cout << "Unable to create file(s)";

        exit(0);
    }

    // line 1
    ofs << n << '\n';
    // other lines
    for (int i = 0; i < n; i++) {
        ofs << arr[i];
        if (i != n - 1) ofs << " ";
    }

    ofs.close();
}

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

void Command1(string algo, ifstream &inputFile, string fileName, string outputMode) {
    cout << "ALGORITHM MODE" << '\n';
    cout << "Algorithm: " << char(toupper(algo[0])) << algo.substr(1) << " sort" << '\n';
    cout << "Input file: " << fileName << '\n';

    string temp;
    getline(inputFile, temp);
    int dataSize = stoi(temp);
    int count = 0;

    cout << "Input Size: " << dataSize << '\n';
    cout << BREAK_LINE << '\n';

    int *arr = new int[dataSize];
    while (getline(inputFile, temp, ' ')) {
        arr[count] = stoi(temp);
        ++count;
    }

    if (count != dataSize) {
        cout << "File is in wrong format";

        exit(0);
    }

    Info sortResult = Sort(algo, arr, dataSize);

    WriteFile(arr, dataSize, "output.txt");

    delete[] arr;

    if (outputMode != "-comp") cout << "Running time: " << sortResult.time << '\n';
    if (outputMode != "-time") cout << "Comparisons: " << sortResult.comparisons;
}

void Command2(string algo, int dataSize, string dataOrder, string outputMode) {
    cout << "ALGORITHM MODE" << '\n';
    cout << "Algorithm: " << char(toupper(algo[0])) << algo.substr(1) << " sort" << '\n';
    cout << "Input size: " << dataSize << '\n';
    for (int i = 0; i < NUM_DATA_ORDER; i++) {
        if (dataOrder != DATA_ORDERS[i][2]) continue;

        cout << "Input order: " << DATA_ORDERS[i][0] << '\n';
        cout << BREAK_LINE << '\n';

        // Run
        int *arr = new int[dataSize];

        GenerateData(arr, dataSize, i);

        WriteFile(arr, dataSize, "input.txt");

        Info sortResult = Sort(algo, arr, dataSize);

        WriteFile(arr, dataSize, "output.txt");

        delete[] arr;

        // Display result
        // Because all arguments have already had valid check in main(), there is no need to check for -both
        if (outputMode != "-comp") cout << "Running time: " << sortResult.time << '\n';
        if (outputMode != "-time") cout << "Comparisons: " << sortResult.comparisons;
    }
}

void Command3(string algo, int dataSize, string outputMode) {
    cout << "ALGORITHM MODE" << '\n';
    cout << "Algorithm: " << char(toupper(algo[0])) << algo.substr(1) << " sort" << '\n';
    cout << "Input size: " << dataSize << '\n';
    cout << '\n';

    for (int i = 0; i < NUM_DATA_ORDER; i++) {
        cout << "Input order: " << DATA_ORDERS[i][0] << '\n';
        cout << BREAK_LINE << '\n';

        // Run
        int *arr = new int[dataSize];

        GenerateData(arr, dataSize, i);

        string fileName = "input_" + DATA_ORDERS[i][1] + ".txt";
        WriteFile(arr, dataSize, fileName);

        Info sortResult = Sort(algo, arr, dataSize);

        delete[] arr;

        // Display result
        // Because all arguments have already had valid check in main(), there is no need to check for -both
        if (outputMode != "-comp") cout << "Running time: " << sortResult.time << '\n';
        if (outputMode != "-time") cout << "Comparisons: " << sortResult.comparisons << '\n';
        cout << '\n';
    }
}

void Command4(std::string algo1, std::string algo2, std::ifstream &inputFile, std::string fileName) {
    // Create result variables

    int *arr = NULL, size, i = 0;

    // Read the data from file
    // Line 1
    inputFile >> size;
    // Other line
    arr = new int[size];

    while (!inputFile.eof()) {
        inputFile >> arr[i++];
    }
    // Create temp array to store data
    int *temp = CopyArr(arr, size);

    Info info1, info2;
    // Check name algorithm 1
    info1 = Sort(algo1, arr, size);
    // Reset arr
    arr = CopyArr(temp, size);

    // Check name algorithm 2
    info2 = Sort(algo2, arr, size);

    cout << "Algorithms: " << algo1 << " | " << algo2 << '\n';
    cout << "Input size: " << size << '\n';
    cout << "Input file name: " << fileName << '\n';
    cout << "--------------------------------------------------\n";
    cout << "Running time: " << info1.time << " | " << info2.time << '\n';
    cout << "Comparisons: " << info1.comparisons << " | " << info2.comparisons << '\n';
}

void Command5(std::string algo1, std::string algo2, int dataSize, std::string dataOrder) {
    // Create result variables
    int *arr = new int[dataSize];

    // Create Data
    if (dataOrder == "-nsorted") {
        GenerateNearlySortedData(arr, dataSize);
    } else if (dataOrder == "-rand") {
        GenerateRandomData(arr, dataSize);
    } else if (dataOrder == "-sorted") {
        GenerateSortedData(arr, dataSize);
    } else if (dataOrder == "-rev") {
        GenerateReverseData(arr, dataSize);
    }

    int *temp = CopyArr(arr, dataSize);

    Info info1, info2;
    // Check name algorithm 1
    info1 = Sort(algo1, arr, dataSize);
    // Reset arr
    arr = CopyArr(temp, dataSize);

    // Check name algorithm 2
    info2 = Sort(algo2, arr, dataSize);

    // Print into the screen
    cout << "Algorithms: " << algo1 << " sort | " << algo2 << " sort" << '\n';
    cout << "Input size: " << dataSize << '\n';
    cout << "Input order: " << dataOrder << '\n';
    cout << "--------------------------------------------------\n";
    cout << "Running time: " << info1.time << " | " << info2.time << '\n';
    cout << "Comparisons: " << info1.comparisons << " | " << info2.comparisons << '\n';

    // Write down the data
    fstream fileOut;
    fileOut.open("input.txt", std::ios::out);
    if (fileOut) {
        // Line 1
        fileOut << dataSize << '\n';
        // Others
        for (int i = 0; i < dataSize; i++) {
            fileOut << temp[i] << " ";
        }
    } else {
        cout << "Can't open file!\n";
        exit(0);
    }

    fileOut.close();
}
