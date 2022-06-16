// COMMAND 5
/* Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]

 – Ex:              a.exe      -c   quick-sort    merge-sort     100000      -nsorted

        g++ test.cpp -std=c++17 -o test.exe
        test.exe -c selection-sort flash-sort 1000 -rev
*/
void command_line_5(int argc, char *argv[]){
    // Need to include some libraries
    // #include <chrono>
    // #include <map>
    // #include <string>

    // Get name algorithms
    string algorithm1 = argv[2];
    string algorithm2 = argv[3];
    // Get size input
    int size = atoi(argv[4]);
    // Get order
    string order = argv[5];

    // Create result variables
    long long time1 = 0, time2 = 0, countC1 = 0, countC2 = 0;
    int *arr = new int[size];

    // Create Data
    if (order == "-nsorted"){
        GenerateNearlySortedData(arr, size);
    }
    else if (order == "-rand"){
        GenerateRandomData(arr, size);
    }
    else if (order == "-sorted"){
        GenerateSortedData(arr, size);
    }
    else if (order == "-rev"){
        GenerateReverseData(arr, size);        
    }

    int *temp = new int[size];
    copy_array(arr, temp, size);
    
    // With count
    using pfuncWithCount = void(*)(int a[], int n, long long &countC);  
    map<string, pfuncWithCount> funcMap1;
    funcMap1["selection-sort"] = selectionSortWithCount;
    funcMap1["flash-sort"] = flashSortWithCount;
    // Need to add similar code
    //.............................................


    // Without Count
    using pfuncWithoutCount = void(*)(int a[], int n);  
    map<string, pfuncWithoutCount> funcMap2;
    funcMap2["selection-sort"] = selectionSortWithoutCount;
    funcMap2["flash-sort"] = flashSortWithoutCount;
    // Need to add similar code
    //.............................................


    // Count time
    // 1.
    pfuncWithoutCount f2 = funcMap2[algorithm1];
    auto start = chrono::steady_clock::now();
    (*f2)(arr, size); 
    auto end = chrono::steady_clock::now();
    time1 = chrono::duration_cast<chrono::milliseconds>(end-start).count();
    // Reset arr
    copy_array(temp, arr, size);

    // 2.
    f2 = funcMap2[algorithm2];
    start = chrono::steady_clock::now();
    (*f2)(arr, size); 
    end = chrono::steady_clock::now();
    time2 = chrono::duration_cast<chrono::milliseconds>(end-start).count();

    // Count Comparisons 
    // Reset arr
    copy_array(temp, arr, size);
    // 1.
    pfuncWithCount f1 = funcMap1[algorithm1];
    (*f1)(arr, size, countC1);

    // Reset arr
    copy_array(temp, arr, size);
    f1 = funcMap1[algorithm2];
    (*f1)(arr, size, countC2);

    // Reset arr last
    copy_array(temp, arr, size);

    // Print into the screen
    cout << "Algorithms: " << algorithm1 << " | " << algorithm2 << endl;
    cout << "Input size: " << size << endl;
    cout << "Input order: " << order << endl;
    cout << "--------------------------------------------------\n";
    cout << "Running time: " << time1 << " | " << time2 << endl;
    cout << "Comparisons: " << countC1 << " | " << countC2 << endl;
    
    // Write down the data
    fstream fileOut;
    fileOut.open("input.txt", ios::out);
    if (fileOut){
        // Line 1
        fileOut << size << endl; 
        // Orthers
        for (int i = 0; i < size; i++){
            fileOut << temp[i] << " ";
        }        
    }
    else{
        cout << "Can't open file!\n";
        exit(0);
    }
    
    //printData(temp, size);
    fileOut.close();   
}
