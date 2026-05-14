#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        // Note: We use strictly '<' here, not '<='. 
        // We want the loop to break when low == high, pointing exactly to the minimum.
        while (low < high) {
            int mid = low + (high - low) / 2;

            // If the mid element is greater than the rightmost element,
            // the minimum (drop point) must be in the right half.
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } 
            // Otherwise, the right half is sorted.
            // The minimum is either at mid or in the left half.
            else {
                high = mid; 
            }
        }

        // When low == high, we have found the minimum element
        return nums[low];
    }
};

// Driver code to test locally in VS Code
int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Minimum in Example 1: " << sol.findMin(nums1) << endl; 
    // Expected: 1

    // Example 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum in Example 2: " << sol.findMin(nums2) << endl; 
    // Expected: 0

    // Example 3 (Array is not actually rotated)
    vector<int> nums3 = {11, 13, 15, 17};
    cout << "Minimum in Example 3: " << sol.findMin(nums3) << endl; 
    // Expected: 11

    return 0;
}