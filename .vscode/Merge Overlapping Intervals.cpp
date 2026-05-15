#include <iostream>
#include <vector>
#include <algorithm> // For std::sort and std::max

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Base case: if there are no intervals, return an empty list
        if (intervals.empty()) {
            return {};
        }

        // 1. Sort the intervals based on their start times
        // C++ sorts vector<vector<int>> by the first element of each inner vector by default
        sort(intervals.begin(), intervals.end());

        // 2. Initialize the merged array with the first interval
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        // 3. Iterate through the remaining intervals
        for (int i = 1; i < intervals.size(); i++) {
            // Get the last interval we inserted into our merged list
            vector<int>& last_merged = merged.back();
            
            // Check for overlap: does the current interval start before or when the last one ends?
            if (intervals[i][0] <= last_merged[1]) {
                // Overlap found! Merge them by updating the end time.
                // We take the max because the current interval might be completely inside the previous one (e.g. [1,5] and [2,4])
                last_merged[1] = max(last_merged[1], intervals[i][1]);
            } else {
                // No overlap. Just add the current interval to the list.
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
int main() {
    Solution sol;
    
    // Example 1
    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result1 = sol.merge(intervals1);
    
    cout << "Merged Intervals (Example 1): ";
    for (const auto& interval : result1) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl; // Expected: [1, 6] [8, 10] [15, 18]

    // Example 2 (One interval completely swallows the other)
    vector<vector<int>> intervals2 = {{1, 4}, {2, 3}};
    vector<vector<int>> result2 = sol.merge(intervals2);
    
    cout << "Merged Intervals (Example 2): ";
    for (const auto& interval : result2) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl; // Expected: [1, 4]

    return 0;
}