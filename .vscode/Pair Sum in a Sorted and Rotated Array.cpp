#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        int n = arr.size();
        
        // Find the pivot element (the largest element)
        int pivot = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Initialize left pointer to the smallest element
        int left = (pivot + 1) % n;
        
        // Initialize right pointer to the largest element
        int right = pivot;

        // Run the circular two-pointer algorithm
        while (left != right) {
            int current_sum = arr[left] + arr[right];

            // If we found the target
            if (current_sum == target) {
                return true;
            }

            // If the sum is less than target, move left pointer forward
            if (current_sum < target) {
                left = (left + 1) % n;
            } 
            // If the sum is greater than target, move right pointer backward
            else {
                right = (right + n - 1) % n;
            }
        }

        // If the pointers meet and no pair is found
        return false;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> arr1 = {11, 15, 6, 8, 9, 10};
    int target1 = 16;
    cout << "Pair with sum " << target1 << " exists: " 
         << (sol.pairInSortedRotated(arr1, target1) ? "True" : "False") << endl;
    // Expected Output: True

    // Example 2
    vector<int> arr2 = {11, 15, 26, 38, 9, 10};
    int target2 = 35;
    cout << "Pair with sum " << target2 << " exists: " 
         << (sol.pairInSortedRotated(arr2, target2) ? "True" : "False") << endl;
    // Expected Output: True

    // Example 3
    vector<int> arr3 = {11, 15, 26, 38, 9, 10};
    int target3 = 45;
    cout << "Pair with sum " << target3 << " exists: " 
         << (sol.pairInSortedRotated(arr3, target3) ? "True" : "False") << endl;
    // Expected Output: False

    return 0;
}