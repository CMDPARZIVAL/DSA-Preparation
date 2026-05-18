#include <iostream>
#include <string>
#include <cctype> // Required for isalnum() and tolower()

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // 1. Skip non-alphanumeric characters from the left
            if (!isalnum(s[left])) {
                left++;
            }
            // 2. Skip non-alphanumeric characters from the right
            else if (!isalnum(s[right])) {
                right--;
            }
            // 3. Both are valid characters, time to compare!
            else {
                // Convert both to lowercase to ignore case differences
                if (tolower(s[left]) != tolower(s[right])) {
                    return false; // Mismatch found, not a palindrome
                }
                
                // Characters match, move both pointers inward
                left++;
                right--;
            }
        }

        // If the loop finishes without returning false, it's a perfect palindrome
        return true;
    }
};

int main() {
    Solution sol;
    
    // Example 1 (Classic long palindrome)
    string s1 = "A man, a plan, a canal: Panama";
    cout << "Example 1 (\"" << s1 << "\"): " 
         << (sol.isPalindrome(s1) ? "True" : "False") << endl;
    // Expected Output: True

    // Example 2 (Not a palindrome)
    string s2 = "race a car";
    cout << "Example 2 (\"" << s2 << "\"): " 
         << (sol.isPalindrome(s2) ? "True" : "False") << endl;
    // Expected Output: False

    // Example 3 (Empty/Whitespace string)
    string s3 = " ";
    cout << "Example 3 (\"" << s3 << "\"): " 
         << (sol.isPalindrome(s3) ? "True" : "False") << endl;
    // Expected Output: True (Reads the same forwards and backwards when stripped)

    return 0;
}