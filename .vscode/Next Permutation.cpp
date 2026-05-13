#include <iostream>
#include <vector>
#include <algorithm> // For std::swap and std::reverse

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int break_point = -1;

        // Step 1: Find the break point from the right
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                break_point = i;
                break;
            }
        }

        // Step 2: If no break point exists, the array is strictly descending.
        // It's the last permutation. Just reverse the whole array.
        if (break_point == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the smallest element greater than nums[break_point] from the right
        for (int i = n - 1; i > break_point; i--) {
            if (nums[i] > nums[break_point]) {
                // Step 4: Swap them
                swap(nums[break_point], nums[i]);
                break;
            }
        }

        // Step 5: Reverse the right half (everything after the break point)
        reverse(nums.begin() + break_point + 1, nums.end());
    }
};

// Driver code to test locally
void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int main() {
    Solution sol;
    
    vector<int> nums1 = {2, 1, 5, 4, 3};
    cout << "Original: "; printArray(nums1);
    sol.nextPermutation(nums1);
    cout << "Next:     "; printArray(nums1); // Expected: 2 3 1 4 5

    vector<int> nums2 = {3, 2, 1};
    cout << "\nOriginal: "; printArray(nums2);
    sol.nextPermutation(nums2);
    cout << "Next:     "; printArray(nums2); // Expected: 1 2 3

    return 0;
}