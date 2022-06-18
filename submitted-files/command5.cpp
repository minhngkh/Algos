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