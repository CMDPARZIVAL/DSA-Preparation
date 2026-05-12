#include <iostream>
#include <vector>
#include <algorithm> // Required for std::swap

using namespace std;

// Function to reverse the array in-place
void reverseArray(vector<int>& arr) {
    int left = 0;                  // Pointer at the start
    int right = arr.size() - 1;    // Pointer at the end

    // Loop until the two pointers meet in the middle
    while (left < right) {
        // Swap the elements at left and right indices
        swap(arr[left], arr[right]);
        
        // Move the pointers towards each other
        left++;
        right--;
    }
}

// Helper function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Example 1
    vector<int> arr1 = {1, 4, 3, 2, 6, 5};
    cout << "Original Array 1: ";
    printArray(arr1);
    
    reverseArray(arr1);
    
    cout << "Reversed Array 1: ";
    printArray(arr1);

    // Example 2
    vector<int> arr2 = {4, 5, 1, 2};
    cout << "\nOriginal Array 2: ";
    printArray(arr2);
    
    reverseArray(arr2);
    
    cout << "Reversed Array 2: ";
    printArray(arr2);

    return 0;
}
