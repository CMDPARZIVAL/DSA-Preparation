#include <iostream>
#include <vector>
#include <algorithm> // For std::max and std::min

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        // Edge case: If there are less than 3 buildings, no water can be trapped
        if (n <= 2) return 0;

        vector<int> left_max(n);
        vector<int> right_max(n);

        // 1. Precompute the highest building to the left of each index
        left_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        // 2. Precompute the highest building to the right of each index
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        // 3. Calculate the trapped water
        int total_water = 0;
        for (int i = 0; i < n; i++) {
            // Water trapped = Minimum of the two highest walls minus current height
            int water_level = min(left_max[i], right_max[i]);
            total_water += (water_level - height[i]);
        }

        return total_water;
    }
};

int main() {
    Solution sol;
    
    // Example from the GeeksforGeeks image
    vector<int> height1 = {3, 0, 1, 0, 4, 0, 2};
    cout << "Trapped Water (Example 1): " << sol.trap(height1) << endl; 
    // Expected Output: 10

    // Classic LeetCode Example
    vector<int> height2 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped Water (Example 2): " << sol.trap(height2) << endl; 
    // Expected Output: 6

    return 0;
}