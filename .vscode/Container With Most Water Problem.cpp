#include <iostream>
#include <vector>
#include <algorithm> // For std::max and std::min

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            // 1. Calculate the current area
            int current_width = right - left;
            int current_height = min(height[left], height[right]);
            int current_area = current_width * current_height;

            // 2. Update maximum area found so far
            max_area = max(max_area, current_area);

            // 3. Move the pointer pointing to the shorter line
            // We do this because the width is decreasing. To find a larger area,
            // we MUST find a taller line.
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max Water Area (Example 1): " << sol.maxArea(height1) << endl; 
    // Expected Output: 49

    // Example 2
    vector<int> height2 = {1, 1};
    cout << "Max Water Area (Example 2): " << sol.maxArea(height2) << endl; 
    // Expected Output: 1

    return 0;
}