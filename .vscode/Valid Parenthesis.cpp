/**
 * Problem: Valid Parentheses
 * Concept: Stack Data Structure
 * Time Complexity: O(N) - We iterate through the string exactly once.
 * Space Complexity: O(N) - In the worst case (e.g., "((((("), we push all characters onto the stack.
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // 1. If it's an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // 2. If it's a closing bracket...
            else {
                // If the stack is empty, there is no matching opening bracket
                if (st.empty()) {
                    return false;
                }

                // Look at the top of the stack
                char top = st.top();

                // Check if the current closing bracket matches the top opening bracket
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    
                    // It's a match! Pop the opening bracket off the stack
                    st.pop();
                } else {
                    // Mismatch found (e.g., top is '{' but current is ']')
                    return false;
                }
            }
        }

        // 3. If the stack is empty, all brackets were matched properly!
        return st.empty();
    }
};

// Driver code to test locally in VS Code
int main() {
    Solution sol;
    
    // Example 1 (Valid)
    string s1 = "()[]{}";
    cout << "Example 1 (\"" << s1 << "\"): " 
         << (sol.isValid(s1) ? "True" : "False") << endl;
    // Expected Output: True

    // Example 2 (Invalid order)
    string s2 = "([)]";
    cout << "Example 2 (\"" << s2 << "\"): " 
         << (sol.isValid(s2) ? "True" : "False") << endl;
    // Expected Output: False

    // Example 3 (Nested correctly)
    string s3 = "{[()]}";
    cout << "Example 3 (\"" << s3 << "\"): " 
         << (sol.isValid(s3) ? "True" : "False") << endl;
    // Expected Output: True

    // Example 4 (Leftover open brackets)
    string s4 = "((";
    cout << "Example 4 (\"" << s4 << "\"): " 
         << (sol.isValid(s4) ? "True" : "False") << endl;
    // Expected Output: False

    return 0;
}