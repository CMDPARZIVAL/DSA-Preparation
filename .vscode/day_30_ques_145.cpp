// ============================================================
// Day   : 30
// Ques  : 145
// Topic : Segment Trees
// File  : day_30_ques_145.cpp
// ============================================================

#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// -- Problem Statement ----------------------------------------
// [TODO] Paste the problem statement here.

// -- Approach -------------------------------------------------
// [TODO] Describe your approach / algorithm.

// -- Time Complexity  : O(?)
// -- Space Complexity : O(?)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < (int)nums.size(); i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Day 30 | Ques 145 | Segment Trees" << endl;
    cout << "Solution compiled successfully." << endl;

    return 0;
}
