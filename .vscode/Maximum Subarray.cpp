#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize max_sum to the smallest possible integer 
        // to handle cases where all numbers are negative.
        int max_sum = INT_MIN; 
        int current_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i]; 

            // Update max_sum if current_sum is the best we've seen
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }

            // If sum becomes negative, it's a burden. 
            // Reset to 0 to start a fresh subarray from the next element.
            if (current_sum < 0) {
                current_sum = 0;
            }
        }

        return max_sum;
    }
};

int main() {
    Solution sol;
    
    // Example 1: Standard case
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Max Subarray Sum (Example 1): " << sol.maxSubArray(nums1) << endl; // Output: 6

    // Example 2: All negative numbers
    vector<int> nums2 = {-5, -1, -8, -2};
    cout << "Max Subarray Sum (Example 2): " << sol.maxSubArray(nums2) << endl; // Output: -1

    return 0;
}