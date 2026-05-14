#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Use a Hash Set for O(1) average time complexity lookups
        unordered_set<int> seen;

        for (int num : nums) {
            // If num is already in the set, we found a duplicate
            if (seen.find(num) != seen.end()) {
                return true;
            }
            // Add current number to the set
            seen.insert(num);
        }

        return false;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    
    if (sol.containsDuplicate(nums)) {
        cout << "Duplicate Found!" << endl;
    } else {
        cout << "No Duplicates." << endl;
    }
    
    return 0;
}