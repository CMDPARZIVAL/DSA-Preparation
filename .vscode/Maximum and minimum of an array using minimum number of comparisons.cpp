#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// Function to find the minimum and maximum of an array
pair<int, int> findMinMax(const vector<int>& arr) {
    int n = arr.size();
    int min_val, max_val;
    int i; // Index to keep track of where we are in the array

    // Step 1: Initialize min_val and max_val
    if (n % 2 == 0) { // Array has an EVEN number of elements
        if (arr[0] > arr[1]) {
            max_val = arr[0];
            min_val = arr[1];
        } else {
            max_val = arr[1];
            min_val = arr[0];
        }
        i = 2; // We already processed the first 2 elements, start from index 2
    } else { // Array has an ODD number of elements
        min_val = arr[0];
        max_val = arr[0];
        i = 1; // We processed the 1st element, start from index 1
    }

    // Step 2: Process the rest of the array in PAIRS
    while (i < n - 1) {
        // Compare the pair first
        if (arr[i] > arr[i + 1]) {
            // arr[i] is larger, check it against max_val
            if (arr[i] > max_val) max_val = arr[i];
            // arr[i+1] is smaller, check it against min_val
            if (arr[i + 1] < min_val) min_val = arr[i + 1];
        } else {
            // arr[i+1] is larger, check it against max_val
            if (arr[i + 1] > max_val) max_val = arr[i + 1];
            // arr[i] is smaller, check it against min_val
            if (arr[i] < min_val) min_val = arr[i];
        }
        i += 2; // Move forward by 2 elements
    }

    return {min_val, max_val};
}

int main() {
    // Example 1
    vector<int> arr1 = {3, 5, 4, 1, 9};
    pair<int, int> result1 = findMinMax(arr1);
    cout << "Array 1 -> Min: " << result1.first << ", Max: " << result1.second << endl;

    // Example 2
    vector<int> arr2 = {22, 14, 8, 17, 35, 3};
    pair<int, int> result2 = findMinMax(arr2);
    cout << "Array 2 -> Min: " << result2.first << ", Max: " << result2.second << endl;

    return 0;
}
