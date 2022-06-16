#include <iostream>
#include <chrono>
#include <map>
#include <fstream>
using namespace std;

#define RANDOM_DATA 0
#define SORTED_DATA 1
#define REVERSE_DATA 2
#define NEARLY_SORTED_DATA 3

template <class T>
void HoanVi(T &a, T &b){
	T x = a;
	a = b;
	b = x;
}
//-------------------------------------------------------------
// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n){
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}
// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n){
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}
// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n){
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}
// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n){
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		HoanVi(a[r1], a[r2]);
	}
}

// Help function
void printData(int *a, int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void copy_array(int _from[], int _to[], int n) {
    for (int i = 0; i < n; ++i)
        _to[i] = _from[i];
}

//-------------------------------------------------------------------

// Without Count
void selectionSortWithoutCount(int a[], int n){
    for (int i = 0; i < n - 1; ++i) {
        int cur_min = i;
        
        for (int j = i + 1; j < n; ++j)
            if (a[cur_min] > a[j])
                cur_min = j;
        swap(a[cur_min], a[i]); 
    }
}
// Without Count
void flashSortWithoutCount(int a[], int n) {
    int *__L = new int[n];
    if (n <= 1) return;
    int m = n * 0.43;
    if (m <= 2) m = 2;
    // int m = n;
    for (int i = 0; i < m; ++i)
        __L[i] = 0;
    int Mx = a[0], Mn = a[0];
    for (int i = 1; i < n; ++i) {
        if (Mx < a[i]) Mx = a[i];
        if (Mn > a[i]) Mn = a[i];
    }
    if (Mx == Mn)
        return;
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; i < n; ++i)
        ++__L[getK(a[i])];
    for (int i = 1; i < m; ++i)
        __L[i] += __L[i - 1];
    //step 2
    int count = 0;
    int i = 0;
    while (count < n) {
        int k = getK(a[i]);
        while (i >= __L[k]) 
            k = getK(a[++i]);
        int z = a[i];
        while (i != __L[k]) {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            ++count;
        }
    }   
    //step 3
    for (int k = 1; k < m; ++k) {
        for (int i = __L[k] - 2; i >= __L[k - 1]; --i)
            if (a[i] > a[i + 1]) {
                int t = a[i], j = i;
                while (t > a[j + 1]) {a[j] = a[j + 1]; ++j;}
                a[j] = t;
            }
    }
}

//------------------------------------------------------------------
int main(int argc, char *argv[]){
    int *a = new int[1000000], n = 1000000;
    int *temp_array = new int[1000000], n_temp = 1000000;
    int dataSizes[] = {10000, 30000, 50000, 100000, 300000, 500000};

    // i: order
    // j: data size
    // RANDOM_DATA 0
    // SORTED_DATA 1
    // REVERSE_DATA 2
    // NEARLY_SORTED_DATA 3
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 6; j++){
            if (i == RANDOM_DATA){
                GenerateRandomData(a, dataSizes[j]);
                cout << "Random Data\n";
            }
            else if (i == SORTED_DATA){
                GenerateSortedData(a, dataSizes[j]);
                cout << "Sorted Data\n";
            }
            else if (i == REVERSE_DATA){
                GenerateReverseData(a, dataSizes[j]);
                cout << "Reverse Data\n";
            }
            else if (i == NEARLY_SORTED_DATA){
                GenerateNearlySortedData(a, dataSizes[j]);
                cout << "Nearly Sorted Data\n";
            }


            // Copy array
            copy_array(a, temp_array, dataSizes[j]);


            selectionSortWithoutCount(a, dataSizes[j]);
            flashSortWithoutCount(temp_array, dataSizes[j]);

            // Print into the screen
            cout << "Input size: " << dataSizes[j] << endl;
            cout << "Algorithms: " << "Selection Sort" << " | " << "Flash Sort" << endl;
            cout << "--------------------------------------------------\n";

        }
    }

    delete temp_array, a;
    return 0;
}