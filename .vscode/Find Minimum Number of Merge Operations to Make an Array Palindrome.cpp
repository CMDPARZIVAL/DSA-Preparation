#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinOps(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        int merge_count = 0;

        while (left <= right) {
            // Case 1: Elements match, no merge needed
            if (arr[left] == arr[right]) {
                left++;
                right--;
            } 
            // Case 2: Left element is smaller, we must merge left
            else if (arr[left] < arr[right]) {
                // Conceptually merge arr[left] with arr[left+1]
                left++; 
                arr[left] += arr[left - 1]; 
                merge_count++;
            } 
            // Case 3: Right element is smaller, we must merge right
            else {
                // Conceptually merge arr[right] with arr[right-1]
                right--; 
                arr[right] += arr[right + 1]; 
                merge_count++;
            }
        }

        return merge_count;
    }
};
int main() {
    Solution sol;
    
    // Example 1
    vector<int> arr1 = {1, 4, 5, 9, 1};
    cout << "Minimum merges for Example 1: " << sol.findMinOps(arr1) << endl; 
    // Expected Output: 1

    // Example 2
    vector<int> arr2 = {11, 14, 15, 99};
    cout << "Minimum merges for Example 2: " << sol.findMinOps(arr2) << endl; 
    // Expected Output: 3 (11+14=25 -> 25+15=40 -> 40+99=139)

    // Example 3 (Already a palindrome)
    vector<int> arr3 = {15, 4, 15};
    cout << "Minimum merges for Example 3: " << sol.findMinOps(arr3) << endl; 
    // Expected Output: 0

    return 0;
}