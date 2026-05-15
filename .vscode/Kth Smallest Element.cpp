#include <iostream>
#include <vector>
#include <queue> // Required for priority_queue

using namespace std;

class Solution {
public:
    int kthSmallest(vector<int>& arr, int k) {
        // In C++, priority_queue is a Max-Heap by default!
        priority_queue<int> max_heap;

        // Iterate through all numbers in the array
        for (int i = 0; i < arr.size(); i++) {
            // Push the current number into the heap
            max_heap.push(arr[i]);

            // If the heap grows larger than 'k', kick out the LARGEST element
            if (max_heap.size() > k) {
                max_heap.pop();
            }
        }

        // After the loop, the heap contains the 'k' smallest elements.
        // The top of the Max-Heap is the largest of those, which is the kth smallest overall.
        return max_heap.top();
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> arr1 = {7, 10, 4, 3, 20, 15};
    int k1 = 3;
    cout << "Example 1 Output (3rd Smallest): " << sol.kthSmallest(arr1, k1) << endl; 
    // Expected: 7

    // Example 2
    vector<int> arr2 = {7, 10, 4, 20, 15};
    int k2 = 4;
    cout << "Example 2 Output (4th Smallest): " << sol.kthSmallest(arr2, k2) << endl; 
    // Expected: 15

    return 0;
}