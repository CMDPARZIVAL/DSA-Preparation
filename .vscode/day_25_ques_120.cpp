// ============================================================
// Day   : 25
// Ques  : 120
// Topic : Arrays
// File  : day_25_ques_120.cpp
// ============================================================

#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// -- Problem Statement ----------------------------------------
// [TODO] Paste the problem statement here.

// -- Approach -------------------------------------------------
// [TODO] Describe your approach / algorithm.

// -- Time Complexity  : O(?)
// -- Space Complexity : O(?)

class Solution {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Day 25 | Ques 120 | Arrays" << endl;
    cout << "Solution compiled successfully." << endl;

    return 0;
}
