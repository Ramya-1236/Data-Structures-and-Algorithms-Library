#include <iostream>
#include <vector>

using namespace std;

// Function for binary search
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;                 // Starting index
    int right = arr.size() - 1;  // Ending index

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Midpoint to avoid overflow

        if (arr[mid] == target) {
            return mid;          // Target found
        } 
        else if (arr[mid] < target) {
            left = mid + 1;      // Search in the right half
        } 
        else {
            right = mid - 1;     // Search in the left half
        }
    }

    return -1;  // Target not found
}

// Utility function to display the array
void displayArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40}; // Sorted array
    int target = 10; // Element to search for

    cout << "Array: ";
    displayArray(arr);

    int result = binarySearch(arr, target); // Perform binary search

    if (result != -1) {
        cout << "Element found at index: " << result << endl; // Target found
    } else {
        cout << "Element not found in the array." << endl; // Target not found
    }

    return 0; // End of program
}
