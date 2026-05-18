/**
 * Problem: Valid Anagram
 * Concept: Frequency Array / Hashing / ASCII Math
 * Time Complexity: O(N) - We iterate through the strings exactly once.
 * Space Complexity: O(1) - The frequency array is always size 26, which is constant.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Base case: If the strings are different lengths, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // Create a frequency array of size 26, initialized to 0
        vector<int> count(26, 0);

        // We can do Phase 1 (Addition) and Phase 2 (Subtraction) in the exact same loop!
        for (int i = 0; i < s.length(); i++) {
            // Add 1 for the character in string 's'
            count[s[i] - 'a']++;
            
            // Subtract 1 for the character in string 't'
            count[t[i] - 'a']--;
        }

        // Phase 3: Verification
        // Check if any bucket is not 0
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false; // Found a mismatch!
            }
        }

        // All buckets are 0, it's a perfect anagram
        return true;
    }
};

// Driver code to test locally in VS Code
int main() {
    Solution sol;
    
    // Example 1 (Valid)
    string s1 = "anagram";
    string t1 = "nagaram";
    cout << "Example 1 (\"" << s1 << "\", \"" << t1 << "\"): " 
         << (sol.isAnagram(s1, t1) ? "True" : "False") << endl;
    // Expected Output: True

    // Example 2 (Invalid)
    string s2 = "rat";
    string t2 = "car";
    cout << "Example 2 (\"" << s2 << "\", \"" << t2 << "\"): " 
         << (sol.isAnagram(s2, t2) ? "True" : "False") << endl;
    // Expected Output: False

    return 0;
}