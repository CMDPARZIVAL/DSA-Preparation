// ============================================================
// Day   : 22
// Ques  : 108
// Topic : Backtracking
// File  : day_22_ques_108.cpp
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
    int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (wt[i - 1] <= w)
                    dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]],
                                   dp[i - 1][w]);
                else
                    dp[i][w] = dp[i - 1][w];
            }
        }
        return dp[n][W];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Day 22 | Ques 108 | Backtracking" << endl;
    cout << "Solution compiled successfully." << endl;

    return 0;
}
