#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cctype>

using namespace std;

// Function prototypes
void printArray(int arr[], int size);
int selectionSort(int arr[], int size, bool ascending);
int insertionSort(int arr[], int size, bool ascending);
int bubbleSort(int arr[], int size, bool ascending);

int exchanges = 0;

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    char sortType, sortOrder, runAgain;
    int n, compares;
    
    do {
        // Get array size
        do {
            cout << "Enter the array size [3,100]: ";
            cin >> n;
        } while (n < 3 || n > 100);
        
        // Create and populate array with random values
        int arr[n];
        cout << "The " << n << " random values are: ";
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 201 - 100; // Range [-100,100]
            cout << arr[i] << " ";
        }
        cout << endl;
        
        // Get sorting type
        do {
            cout << "Enter type of sort [S)election I)nsertion B)ubble]: ";
            cin >> sortType;
            sortType = toupper(sortType);
        } while (sortType != 'S' && sortType != 'I' && sortType != 'B');
        
        // Get sorting order
        do {
            cout << "Enter sorting order [A)scending, D)escending]: ";
            cin >> sortOrder;
            sortOrder = toupper(sortOrder);
        } while (sortOrder != 'A' && sortOrder != 'D');
        
        // Sort the array and count comparisons and exchanges
        switch (sortType) {
            case 'S':
                compares = selectionSort(arr, n, sortOrder == 'A');
                break;
            case 'I':
                compares = insertionSort(arr, n, sortOrder == 'A');
                break;
            case 'B':
                compares = bubbleSort(arr, n, sortOrder == 'A');
                break;
        }
        exchanges = compares; // In all cases, exchanges = compares
        
        // Output results
        cout << "Sorted!" << endl;
        cout << "A total of " << compares << " comparisons and " << exchanges << " exchanges were made." << endl;
        cout << "Array sorted in " << (sortOrder == 'A' ? "ascending" : "descending") << " order by " << (sortType == 'S' ? "selection" : sortType == 'I' ? "insertion" : "bubble") << " sort: ";
        printArray(arr, n);
        
        // Ask user to run again
        do {
            cout << "Run Again (Y/N): ";
            cin >> runAgain;
            runAgain = toupper(runAgain);
        } while (runAgain != 'Y' && runAgain != 'N');
    } while (runAgain == 'Y');
    
    return 0;
}

// Function to print the contents of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to perform selection sort on an array
int selectionSort(int arr[], int size, bool ascending) {
    int compares = 0;
    int minIndex;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if ((ascending && arr[j] < arr[minIndex]) || (!ascending && arr[j] > arr[minIndex])) {
                minIndex = j;
            }
            compares++;
        printArray(arr, size);
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            exchanges++;
        }
    }
    return compares;
}

// Function to perform insertion sort on an array
int insertionSort(int arr[], int size, bool ascending) {
    int compares = 0;
    int j, temp;
    for (int i = 1; i < size; i++) {
        j = i;
        temp = arr[i];
        while (j > 0 && ((ascending && arr[j-1] > temp) || (!ascending && arr[j-1] < temp))) {
            arr[j] = arr[j-1];
            j--;
            compares++;
        }
        arr[j] = temp;
        exchanges++;
    }
    return compares;
}

// Function to perform bubble sort on an array
int bubbleSort(int arr[], int size, bool ascending) {
    int compares = 0;
    bool swapped = true;
    for (int i = 0; i < size - 1 && swapped; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if ((ascending && arr[j] > arr[j+1]) || (!ascending && arr[j] < arr[j+1])) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            compares++;
        }
    }
    return compares;
}
