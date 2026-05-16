#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Frequency array to store how many times we've seen a specific remainder.
        // The size is 'k' because remainders when divided by k range from 0 to k-1.
        vector<int> rem_count(k, 0);
        
        // Base case: A prefix sum that is perfectly divisible by k has a remainder of 0.
        // We start with one count of remainder 0 to catch these instances.
        rem_count[0] = 1;

        int running_sum = 0;
        int total_subarrays = 0;

        for (int num : nums) {
            running_sum += num;

            // Calculate the remainder.
            // C++ modulo operator can return negative values for negative numbers.
            // The formula ((sum % k) + k) % k ensures the remainder is always positive.
            int remainder = ((running_sum % k) + k) % k;

            // If we've seen this remainder before, we add the number of times we've seen it 
            // to our total. Each previous occurrence forms a valid subarray ending at this index.
            total_subarrays += rem_count[remainder];

            // Record that we have seen this remainder one more time
            rem_count[remainder]++;
        }

        return total_subarrays;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {4, 5, 0, -2, -3, 1};
    int k1 = 5;
    cout << "Subarrays divisible by 5 (Example 1): " << sol.subarraysDivByK(nums1, k1) << endl; 
    // Expected Output: 7

    // Example 2
    vector<int> nums2 = {5};
    int k2 = 9;
    cout << "Subarrays divisible by 9 (Example 2): " << sol.subarraysDivByK(nums2, k2) << endl; 
    // Expected Output: 0

    return 0;
}