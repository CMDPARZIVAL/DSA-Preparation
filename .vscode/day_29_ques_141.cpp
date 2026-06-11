// ============================================================
// Day   : 29
// Ques  : 141
// Topic : Segment Trees
// File  : day_29_ques_141.cpp
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
    void dfs(int node,
             vector<vector<int>>& adj,
             vector<bool>& visited,
             vector<int>& result) {
        visited[node] = true;
        result.push_back(node);
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, result);
            }
        }
    }

    vector<int> dfsTraversal(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        vector<int>  result;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) dfs(i, adj, visited, result);
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Day 29 | Ques 141 | Segment Trees" << endl;
    cout << "Solution compiled successfully." << endl;

    return 0;
}
