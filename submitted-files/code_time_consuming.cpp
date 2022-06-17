#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include<algorithm>
#include <stdio.h>
#include <cassert>
#include <string>
#include<time.h>
#define MAX_SIZE 16382

using namespace std;


template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
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

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}
void bubble_sort(int a[], int n) {
   clock_t start, end;
	double time_use;
	start = clock();
    for (int j = n; j > 1; --j) 
        for (int i = 1;i < j; ++i)
            if (a[i - 1] > a[i]) 
                swap(a[i - 1], a[i]);

    end = clock();
	time_use = (double(end) - double(start)) / CLOCKS_PER_SEC;
	cout << " Time heap sort " << time_use << endl;
}
int partition(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];
    while (i < j)
    {
        while (pivot >= arr[i])
            i++;
        while (pivot < arr[j])
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
 
void quickSort(int arr[], int low, int high)
{
     clock_t start, end;
	double time_use;
	start = clock();
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
     end = clock();
	time_use = (double(end) - double(start)) / CLOCKS_PER_SEC;
	cout << " Time heap sort " << time_use << endl;
}
 
/**
 * Quick Sort
 * Average complexity: O(nlogn)
 * Best Case: O(nlogn)
 * Worst Case: O(n^2)
 * Space: O(logn)
 * Not Stable
 * Random Pivot
 */ 

void shellSort(int arr[], int n)
{
     clock_t start, end;
	double time_use;
	start = clock();
 
    for (int gap = n/2;  gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
     end = clock();
	time_use = (double(end) - double(start)) / CLOCKS_PER_SEC;
	cout << " Time heap sort " << time_use << endl;3
}
void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}
int main()
{

	int u,n;
	cout << " So phan tu cua mang la : ";
	cin >> n;
	u = n;
	int* a;
	a = new int[n];
	int datatype;
	cout << " Mang duoc sap xep theo kieu : ";
	cin >> datatype;
	GenerateData(a, n, datatype);
	//printArray(a, n);
    //bubble_sort( a, n);
    // quickSort(arr, 0, n - 1);
    shellSort(a,  n);
	//cout << "comparisons : " <<  count_compare << endl;
	//printArray(a, n);
}

