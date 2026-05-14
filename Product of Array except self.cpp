#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize the result array with 1s. 
        // (This does not count towards extra space complexity per problem rules)
        vector<int> result(n, 1);

        // 1. First Pass: Calculate products of all elements to the LEFT
        int left_product = 1;
        for (int i = 0; i < n; i++) {
            result[i] = left_product;     // Store the product of elements to the left
            left_product *= nums[i];      // Update left_product with current element
        }

        // 2. Second Pass: Calculate products of all elements to the RIGHT
        // We iterate backwards, maintaining a running right_product
        int right_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= right_product;   // Multiply existing left product by right product
            right_product *= nums[i];     // Update right_product with current element
        }

        return result;
    }
};

// Driver code to test locally in VS Code
int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> ans1 = sol.productExceptSelf(nums1);
    cout << "Example 1 Output: ";
    for (int num : ans1) cout << num << " "; 
    cout << endl; // Expected: 24 12 8 6

    // Example 2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> ans2 = sol.productExceptSelf(nums2);
    cout << "Example 2 Output: ";
    for (int num : ans2) cout << num << " "; 
    cout << endl; // Expected: 0 0 9 0 0

    return 0;
}