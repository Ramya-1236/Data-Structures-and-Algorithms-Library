#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array for Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]); // Swap
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in the right position
    return i + 1; // Return the partition index
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Get the partition index
        quickSort(arr, low, pi - 1); // Recursively sort the left part
        quickSort(arr, pi + 1, high); // Recursively sort the right part
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " "; // Print each element
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5}; // Sample array
    cout << "Original array: ";
    printArray(arr); // Print original array

    quickSort(arr, 0, arr.size() - 1); // Sort the array

    cout << "Sorted array: ";
    printArray(arr); // Print sorted array

    return 0; // End of program
}
