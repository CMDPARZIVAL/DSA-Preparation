/**
 * Problem: Search in Rotated Sorted Array
 * Concept: Modified Binary Search
 * Time Complexity: O(log N) - We divide the search space in half every time.
 * Space Complexity: O(1) - No extra memory used.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // 1. Check if we found the target
            if (nums[mid] == target) {
                return mid;
            }

            // 2. Identify the sorted half
            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                // Check if target lies within the left sorted half
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1; // Target is here, discard right half
                } else {
                    low = mid + 1;  // Target is NOT here, discard left half
                }
            } 
            // Right half is sorted
            else {
                // Check if target lies within the right sorted half
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;  // Target is here, discard left half
                } else {
                    high = mid - 1; // Target is NOT here, discard right half
                }
            }
        }

        // Target not found
        return -1;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << "Target " << target1 << " found at index: " << sol.search(nums1, target1) << endl; 
    // Expected Output: 4

    // Example 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    cout << "Target " << target2 << " found at index: " << sol.search(nums2, target2) << endl; 
    // Expected Output: -1

    return 0;
}