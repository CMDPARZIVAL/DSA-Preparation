#include <iostream>
#include <vector>
#include <queue> // Required for priority_queue

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Syntax to create a Min-Heap in C++
        priority_queue<int, vector<int>, greater<int>> min_heap;

        // Iterate through all numbers in the array
        for (int i = 0; i < nums.size(); i++) {
            // Push the current number into the heap
            min_heap.push(nums[i]);

            // If the heap grows larger than 'k', kick out the smallest element
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        // After the loop, the heap contains the 'k' largest elements.
        // The top of the Min-Heap is the smallest of those, which is the kth largest overall.
        return min_heap.top();
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    cout << "Example 1 Output: " << sol.findKthLargest(nums1, k1) << endl; // Expected: 5

    // Example 2
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << "Example 2 Output: " << sol.findKthLargest(nums2, k2) << endl; // Expected: 4

    return 0;
}