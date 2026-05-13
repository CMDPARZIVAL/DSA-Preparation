#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> repeatedNumber(const vector<int> &A) {
        long long n = A.size();

        // 1. Calculate Expected Sums using long long
        long long expected_sum = (n * (n + 1)) / 2;
        long long expected_sq_sum = (n * (n + 1) * (2 * n + 1)) / 6;

        long long actual_sum = 0;
        long long actual_sq_sum = 0;

        // 2. Calculate Actual Sums, being careful to cast to long long BEFORE multiplying
        for (int i = 0; i < n; i++) {
            actual_sum += (long long)A[i];
            actual_sq_sum += (long long)A[i] * (long long)A[i];
        }

        // 3. Setup the equations
        // diff1 = A - B
        long long diff1 = actual_sum - expected_sum;

        // diff2 = A^2 - B^2
        long long diff2 = actual_sq_sum - expected_sq_sum;

        // sum_AB = A + B = (A^2 - B^2) / (A - B)
        long long sum_AB = diff2 / diff1;

        // 4. Solve the linear equations
        // A - B = diff1
        // A + B = sum_AB
        // 2A = diff1 + sum_AB
        long long repeated_A = (diff1 + sum_AB) / 2;
        long long missing_B = repeated_A - diff1;

        // The problem asks to return {A, B}
        return {(int)repeated_A, (int)missing_B};
    }
};

int main() {
    Solution sol;
    vector<int> A = {3, 1, 2, 5, 3};
    vector<int> result = sol.repeatedNumber(A);
    
    cout << "Repeated (A): " << result[0] << ", Missing (B): " << result[1] << endl;
    // Expected Output: Repeated (A): 3, Missing (B): 4
    
    return 0;
}