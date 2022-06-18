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

void Command1(string algo, ifstream &inputFile, string outputMode) { 
    int* a;
    int n;
    PrintAlgorithm(agrv[2], "");
    readFile(agrv[3], a, n);
    double timeuse;
    unsigned long long int comp = 0;
    cout << "---------------------------------------\n";

    if (agrv[4] == "-time")
        Algorithm_Time(agrv[2], a, n, timeuse);
    else Algorithm_Both(agrv[2], a, n, comp, timeuse);


    ModePara(agrv[4], timeuse, comp);
    writingFile("output.txt", a, n);
    delete[] a;

 }
void Command1(int agrc, char* agrv[])
{
    string mode = agrv[1];
    Mode(mode);
    string modeChoice(agrv[2]);
    int* a;
    int n;
    PrintAlgorithm(modeChoice, "");
    readFile(agrv[3], a, n);
    string s4 = agrv[4];
    double timeuse;
    unsigned long long int comp = 0;
    cout << "---------------------------------------\n";

    if (s4 == "-time")
        Algorithm_Time(modeChoice, a, n, timeuse);
    else Algorithm_Both(modeChoice, a, n, comp, timeuse);


    ModePara(s4, timeuse, comp);
    writingFile("output.txt", a, n);
    delete[] a;

}
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

void command5(std::string algo1, std::string algo2, int dataSize, std::string dataOrder){

    // Create result variables
    int *arr = new int[dataSize];

    // Create Data
    if (dataOrder == "-nsorted"){
        GenerateNearlySortedData(arr, dataSize);
    }
    else if (dataOrder == "-rand"){
        GenerateRandomData(arr, dataSize);
    }
    else if (dataOrder == "-sorted"){
        GenerateSortedData(arr, dataSize);
    }
    else if (dataOrder == "-rev"){
        GenerateReverseData(arr, dataSize);        
    }

    int *temp = CopyArr(arr, dataSize);
    
    Info  info1, info2;
    // Check name algorithm 1
    if (algo1 == "selection-sort"){
        info1 = SelectionSort(arr, dataSize); 
    }
    else if (algo1 == "insertion-sort"){
        info1 = InsertionSort(arr, dataSize);  
    }
    else if (algo1 == "bubble-sort"){
        info1 = BubbleSort(arr, dataSize); 
    }
    else if (algo1 == "heap-sort"){
        info1 = HeapSort(arr, dataSize); 
    }
    else if (algo1 == "merge-sort"){
        info1 = MergeSort(arr, dataSize); 
    }
    else if (algo1 == "quick-sort"){
        info1 = QuickSort(arr, dataSize); 
    }
    else if (algo1 == "radix-sort"){
        info1 = RadixSort(arr, dataSize); 
    }
    else if (algo1 == "shaker-sort"){
        info1 = ShakerSort(arr, dataSize); 
    }
    else if (algo1 == "shell-sort"){
        info1 = ShellSort(arr, dataSize); 
    }
    else if (algo1 == "counting-sort"){
        info1 = CountingSort(arr, dataSize); 
    }
    else if (algo1 == "flash-sort"){
        info1 = FlashSort(arr, dataSize); 
    }
    // Reset arr
    arr = CopyArr(temp, dataSize);
    
    // Check name algorithm 2
    if (algo2 == "selection-sort"){
        info2 = SelectionSort(arr, dataSize); 
    }
    else if (algo2 == "insertion-sort"){
        info2 = InsertionSort(arr, dataSize); 
    }
    else if (algo2 == "bubble-sort"){
        info2 = BubbleSort(arr, dataSize); 
    }
    else if (algo2 == "heap-sort"){
        info2 = HeapSort(arr, dataSize); 
    }
    else if (algo2 == "merge-sort"){
        info2 = MergeSort(arr, dataSize); 
    }
    else if (algo2 == "quick-sort"){
        info2 = QuickSort(arr, dataSize); 
    }
    else if (algo2 == "radix-sort"){
        info2 = RadixSort(arr, dataSize); 
    }
    else if (algo2 == "shaker-sort"){
        info2 = ShakerSort(arr, dataSize); 
    }
    else if (algo2 == "shell-sort"){
        info2 = ShellSort(arr, dataSize); 
    }
    else if (algo2 == "counting-sort"){
        info2 = CountingSort(arr, dataSize); 
    }
    else if (algo2 == "flash-sort"){
        info2 = FlashSort(arr, dataSize); 
    }

    // Print into the screen
    cout << "Algorithms: " << algo1 << " | " << algo2 << endl;
    cout << "Input size: " << dataSize << endl;
    cout << "Input order: " << dataOrder << endl;
    cout << "--------------------------------------------------\n";
    cout << "Running time: " << info1.time << " | " << info2.time << endl;
    cout << "Comparisons: " << info1.comparisons << " | " << info2.comparisons << endl;
    
    // Write down the data
    fstream fileOut;
    fileOut.open("input.txt", ios::out);
    if (fileOut){
        // Line 1
        fileOut << dataSize << endl; 
        // Others
        for (int i = 0; i < dataSize; i++){
            fileOut << temp[i] << " ";
        }        
    }
    else{
        cout << "Can't open file!\n";
        exit(0);
    }
    
    fileOut.close();    
}
