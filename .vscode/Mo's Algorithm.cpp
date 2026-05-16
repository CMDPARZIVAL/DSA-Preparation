#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// --- GLOBAL VARIABLES & STRUCTURES ---
// These must be outside the class or defined as static so the custom sort can access them.
int block_size;

struct Query {
    int L, R, index;
};

// Custom comparator for Mo's Algorithm
bool compare(Query q1, Query q2) {
    if (q1.L / block_size != q2.L / block_size) {
        return q1.L / block_size < q2.L / block_size;
    }
    return q1.R < q2.R;
}
// -------------------------------------

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        int q = queries.size();
        
        // Calculate block size
        block_size = max(1, (int)sqrt(n));

        // Build our list of struct Queries
        vector<Query> Q(q);
        for (int i = 0; i < q; i++) {
            // TRAP: The problem uses 1-based indexing! Subtract 1 for 0-based C++ arrays.
            Q[i].L = queries[i][0] - 1;
            Q[i].R = queries[i][1] - 1;
            Q[i].index = i; 
        }

        // Sort queries using Mo's logic
        sort(Q.begin(), Q.end(), compare);

        vector<int> answers(q);
        int curr_L = 0, curr_R = -1;
        
        // Frequency array: Constraints say nums[i] <= 1000, so size 1005 is safe.
        vector<int> freq(1005, 0);
        int valid_count = 0; // Tracks how many numbers have frequency >= k

        // Process each query
        for (int i = 0; i < q; i++) {
            int L = Q[i].L;
            int R = Q[i].R;

            // 1. Expand window to the right
            while (curr_R < R) {
                curr_R++;
                int val = nums[curr_R];
                freq[val]++;
                if (freq[val] == k) valid_count++; // Just reached threshold!
            }
            // 2. Shrink window from the left
            while (curr_L < L) {
                int val = nums[curr_L];
                if (freq[val] == k) valid_count--; // About to drop below threshold!
                freq[val]--;
                curr_L++;
            }
            // 3. Expand window to the left
            while (curr_L > L) {
                curr_L--;
                int val = nums[curr_L];
                freq[val]++;
                if (freq[val] == k) valid_count++; // Just reached threshold!
            }
            // 4. Shrink window from the right
            while (curr_R > R) {
                int val = nums[curr_R];
                if (freq[val] == k) valid_count--; // About to drop below threshold!
                freq[val]--;
                curr_R--;
            }

            // Store the answer mapped to its original query index
            answers[Q[i].index] = valid_count;
        }

        return answers;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {1, 1, 2, 1, 3};
    vector<vector<int>> queries1 = {{1, 5}, {2, 4}};
    int k1 = 1;
    vector<int> res1 = sol.solveQueries(nums1, queries1, k1);
    
    cout << "Example 1 Output: ";
    for (int ans : res1) cout << ans << " ";
    cout << "\nExpected Output: 3 2\n\n";

    // Example 2
    vector<int> nums2 = {1, 2, 3, 1};
    vector<vector<int>> queries2 = {{1, 4}, {2, 4}, {4, 4}};
    int k2 = 2;
    vector<int> res2 = sol.solveQueries(nums2, queries2, k2);
    
    cout << "Example 2 Output: ";
    for (int ans : res2) cout << ans << " ";
    cout << "\nExpected Output: 1 0 0\n";

    return 0;
}