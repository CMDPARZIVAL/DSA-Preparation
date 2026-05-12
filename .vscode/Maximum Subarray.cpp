#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <climits>   // For INT_MAX

using namespace std;

// Function to find the minimum difference
int findMinDiff(vector<int>& arr, int m) {
    int n = arr.size();

    // Edge Cases
    if (m == 0 || n == 0) return 0;
    
    // If there are fewer packets than students, distribution is impossible
    if (n < m) return -1;

    // Step 1: Sort the array
    sort(arr.begin(), arr.end());

    int min_diff = INT_MAX;

    // Step 2: Slide a window of size 'm' across the array
    // We stop at n - m because that's the last valid starting position for a window of size m
    for (int i = 0; i <= n - m; i++) {
        // Minimum element in this window is arr[i]
        // Maximum element in this window is arr[i + m - 1]
        int current_diff = arr[i + m - 1] - arr[i];

        // Update the global minimum difference
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }

    return min_diff;
}

int main() {
    // Example 1
    vector<int> arr1 = {7, 3, 2, 4, 9, 12, 56};
    int m1 = 3;
    cout << "Minimum difference is: " << findMinDiff(arr1, m1) << endl;

    // Example 2
    vector<int> arr2 = {3, 4, 1, 9, 56, 7, 9, 12};
    int m2 = 5;
    cout << "Minimum difference is: " << findMinDiff(arr2, m2) << endl;

    return 0;
}