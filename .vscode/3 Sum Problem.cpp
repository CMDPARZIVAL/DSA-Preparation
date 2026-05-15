#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        // 1. Sort the array to easily handle duplicates and use two pointers
        sort(nums.begin(), nums.end());

        // 2. Iterate through the array. 
        // We stop at n-2 because we need at least 3 elements to form a triplet.
        for (int i = 0; i < n - 2; i++) {
            
            // TRAP AVOIDANCE: Skip duplicate 'i' values to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; 
            }

            // Standard Two-Pointer approach for the remainder of the array
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // Match found! Add the triplet to our results.
                    result.push_back({nums[i], nums[left], nums[right]});

                    // TRAP AVOIDANCE: Skip duplicate 'left' values
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // TRAP AVOIDANCE: Skip duplicate 'right' values
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // Move both pointers inward to look for other potential pairs
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    // Sum is too small, we need a larger number. Move left pointer.
                    left++;
                } 
                else {
                    // Sum is too large, we need a smaller number. Move right pointer.
                    right--;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> triplets = sol.threeSum(nums);
    
    cout << "Unique Triplets summing to 0:" << endl;
    for (const auto& triplet : triplets) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    // Expected Output:
    // [-1, -1, 2]
    // [-1, 0, 1]

    return 0;
}