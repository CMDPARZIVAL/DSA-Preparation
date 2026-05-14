#include <iostream>
#include <vector>
#include <algorithm> // For std::max
#include <climits>   // For INT_MAX

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX; // Track the lowest price seen so far
        int max_profit = 0;      // Track the maximum profit possible

        for (int i = 0; i < prices.size(); i++) {
            // 1. Update the minimum price if we found a new low
            if (prices[i] < min_price) {
                min_price = prices[i];
            } 
            // 2. Otherwise, calculate profit if we sold today and update max_profit
            else {
                int current_profit = prices[i] - min_price;
                max_profit = max(max_profit, current_profit);
            }
        }

        return max_profit;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit 1: " << sol.maxProfit(prices1) << endl; // Expected: 5

    // Example 2 (Prices strictly decreasing)
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Max Profit 2: " << sol.maxProfit(prices2) << endl; // Expected: 0

    return 0;
}