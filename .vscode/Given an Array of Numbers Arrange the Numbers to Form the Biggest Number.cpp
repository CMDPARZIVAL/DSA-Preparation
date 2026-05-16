
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::sort

using namespace std;

class Solution {
public:
    // The Custom Comparator Rule
    // It MUST be static if it's declared inside a class for std::sort to use it.
    static bool compare(string a, string b) {
        // Compare the concatenated strings
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        // 1. Convert all integers to strings
        vector<string> str_nums;
        for (int num : nums) {
            str_nums.push_back(to_string(num));
        }

        // 2. Sort using our custom rule
        sort(str_nums.begin(), str_nums.end(), compare);

        // 3. Edge Case: If the largest number after sorting is "0", 
        // it means the array was full of zeros (e.g., [0, 0]). 
        // We should return "0", not "00".
        if (str_nums[0] == "0") {
            return "0";
        }

        // 4. Glue them all together
        string result = "";
        for (string s : str_nums) {
            result += s;
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {3, 30, 34, 5, 9};
    cout << "Largest Number (Example 1): " << sol.largestNumber(nums1) << endl; 
    // Expected Output: 9534330

    // Example 2
    vector<int> nums2 = {10, 2};
    cout << "Largest Number (Example 2): " << sol.largestNumber(nums2) << endl; 
    // Expected Output: 210

    // Example 3 (The Zero Trap)
    vector<int> nums3 = {0, 0};
    cout << "Largest Number (Example 3): " << sol.largestNumber(nums3) << endl; 
    // Expected Output: 0

    return 0;
}