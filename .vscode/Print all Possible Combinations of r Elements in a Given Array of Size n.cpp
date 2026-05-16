#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // The core recursive backtracking function
    void combinationUtil(const vector<int>& arr, vector<int>& data, int start, int end, int index, int r) {
        
        // BASE CASE 1: If our temporary combination bucket is full, print it and backtrack!
        if (index == r) {
            cout << "[ ";
            for (int j = 0; j < r; j++) {
                cout << data[j] << " ";
            }
            cout << "]\n";
            return;
        }

        // Loop to fix the element at 'index' and recurse for the remaining elements
        // The condition "end - i >= r - index" is a powerful optimization: 
        // It stops the loop if there aren't enough elements left in the array to fill the remaining slots in 'data'.
        for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
            
            // 1. Include the current element in our data bucket
            data[index] = arr[i];
            
            // 2. Recurse to fill the next index in the bucket using the remaining elements
            combinationUtil(arr, data, i + 1, end, index + 1, r);
            
            // 3. Backtracking happens automatically! 
            // When the recursive call returns, the loop increments 'i', 
            // and the next element simply overwrites data[index].
        }
    }

public:
    void printCombinations(vector<int>& arr, int r) {
        int n = arr.size();
        
        // A temporary vector to store the current combination being built
        vector<int> data(r);
        
        // Call the recursive utility function
        // arr, data buffer, start index 0, end index n-1, current data index 0, target size r
        combinationUtil(arr, data, 0, n - 1, 0, r);
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> arr1 = {1, 2, 3, 4};
    int r1 = 2;
    cout << "Combinations of size " << r1 << " from [1, 2, 3, 4]:\n";
    sol.printCombinations(arr1, r1);
    /* Expected Output:
       [ 1 2 ]
       [ 1 3 ]
       [ 1 4 ]
       [ 2 3 ]
       [ 2 4 ]
       [ 3 4 ]
    */

    cout << "\n--------------------\n\n";

    // Example 2
    vector<int> arr2 = {10, 20, 30, 40, 50};
    int r2 = 3;
    cout << "Combinations of size " << r2 << " from [10, 20, 30, 40, 50]:\n";
    sol.printCombinations(arr2, r2);

    return 0;
}