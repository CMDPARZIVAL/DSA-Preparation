#include <iostream>
#include <vector>

using namespace std;

class SpaceOptimizedTracker {
private:
    vector<int> bit_array;

public:
    // Constructor allocates just enough integers to hold 'n' bits
    SpaceOptimizedTracker(int n) {
        // We divide by 32 and add 1 to ensure we have enough space for the remainder
        int num_ints_needed = (n / 32) + 1;
        bit_array.assign(num_ints_needed, 0); 
    }

    // Function to set the i-th bit to 1
    void setBit(int i) {
        int array_index = i / 32;
        int bit_position = i % 32;
        
        // Use Bitwise OR to turn the specific bit ON
        bit_array[array_index] |= (1 << bit_position);
    }

    // Function to check if the i-th bit is 1
    bool checkBit(int i) {
        int array_index = i / 32;
        int bit_position = i % 32;
        
        // Use Bitwise AND to check the specific bit
        return (bit_array[array_index] & (1 << bit_position)) != 0;
    }
};

int main() {
    int N = 50; // Let's track numbers up to 50
    SpaceOptimizedTracker tracker(N);

    // 1. Mark all multiples of 2 or 5
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0 || i % 5 == 0) {
            tracker.setBit(i);
        }
    }

    // 2. Print them out by checking our compressed bit array
    cout << "Multiples of 2 or 5 up to " << N << " are: \n";
    for (int i = 1; i <= N; i++) {
        if (tracker.checkBit(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}