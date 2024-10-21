#include <iostream>
#include <vector>

using namespace std;

// Merge function to combine two halves
void merge(vector<int>& arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;  // Size of left half
    int rightSize = right - mid;     // Size of right half

    vector<int> leftArr(leftSize);   // Left subarray
    vector<int> rightArr(rightSize);  // Right subarray

    // Copy data to temporary arrays
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < rightSize; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into the original array
    int i = 0;  // Initial index of the left subarray
    int j = 0;  // Initial index of the right subarray
    int k = left; // Initial index of merged subarray

    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    // Copy any remaining elements of leftArr
    while (i < leftSize) {
        arr[k++] = leftArr[i++];
    }

    // Copy any remaining elements of rightArr
    while (j < rightSize) {
        arr[k++] = rightArr[j++];
    }
}

// Merge Sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Avoid overflow

        mergeSort(arr, left, mid);    // Sort first half
        mergeSort(arr, mid + 1, right); // Sort second half
        merge(arr, left, mid, right);  // Merge the sorted halves
    }
}

// Utility function to display the array
void displayArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array: ";
    displayArray(arr);

    mergeSort(arr, 0, arr.size() - 1); // Sort the array

    cout << "Sorted array: ";
    displayArray(arr); // Display the sorted array

    return 0; // End of program
}
