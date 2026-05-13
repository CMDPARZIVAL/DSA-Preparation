#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long findMinDiff(vector<long long> a, long long n, long long m) {
        // 1. If there are no students or no packets, difference is 0
        if (m == 0 || n == 0) return 0;

        // 2. Sort the packets to bring similar sizes together
        sort(a.begin(), a.end());

        // 3. If students are more than packets, distribution is impossible
        if (n < m) return -1;

        long long min_diff = LLONG_MAX;

        // 4. Sliding window of size M
        // i is the starting index, i + m - 1 is the ending index
        for (long long i = 0; i <= n - m; i++) {
            long long diff = a[i + m - 1] - a[i];
            
            if (diff < min_diff) {
                min_diff = diff;
            }
        }

        return min_diff;
    }
};

int main() {
    Solution sol;
    
    // Example test case
    vector<long long> packets = {3, 4, 1, 9, 56, 7, 9, 12};
    long long m = 5; // Number of students
    long long n = packets.size();

    long long result = sol.findMinDiff(packets, n, m);
    
    cout << "Minimum difference is: " << result << endl;

    return 0;
}