#include <iostream>
#include <vector>
#include <algorithm> // For std::max
#include <climits>   // For INT_MIN

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int max_prod = INT_MIN; // Keep track of the absolute maximum found
        int prefix = 1;         // Running product from left to right
        int suffix = 1;         // Running product from right to left

        for (int i = 0; i < n; i++) {
            // If we hit a zero in a previous step, our product was destroyed.
            // We must reset to 1 to start a fresh contiguous subarray.
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;

            // Multiply current element into the prefix
            prefix *= nums[i];
            
            // Multiply the corresponding element from the back into the suffix
            // (n - 1 - i) walks backward as 'i' walks forward
            suffix *= nums[n - 1 - i];

            // Update the global maximum with whichever is largest
            max_prod = max({max_prod, prefix, suffix});
        }

        return max_prod;
    }
};

// Driver code to test locally in VS Code
int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Max Product (Example 1): " << sol.maxProduct(nums1) << endl; 
    // Expected: 6

    // Example 2 (Zero splitting the array)
    vector<int> nums2 = {-2, 0, -1};
    cout << "Max Product (Example 2): " << sol.maxProduct(nums2) << endl; 
    // Expected: 0

    return 0;
}