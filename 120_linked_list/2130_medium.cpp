// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> q;
        ListNode* h1 = head;
        ListNode* h2 = head;
        while (h2 != nullptr) {
            q.push(h1->val);
            h1 = h1->next;
            h2 = h2->next->next;
        }
        h2 = h1;
        int res = 0;
        while (!q.empty()) {
            res = max(res, q.top() + h2->val);
            h2 = h2->next;
            q.pop();
        }
        return res;
    }
};

class Solution2 {
public:
    int pairSum(ListNode* head) {
        ListNode* h1_h1 = nullptr;
        ListNode* h1_h2 = nullptr;
        ListNode* h1 = head;
        ListNode* h2 = head;
        while (h2 != nullptr) {
            h2 = h2->next->next;
            h1_h2 = h1_h1;
            h1_h1 = h1;
            h1 = h1->next;
            h1_h1->next = h1_h2;                        
        }
        h2 = h1;
        h1 = h1_h1;
        int res = 0;
        while (h2 != nullptr) {
            res = max(res, h1->val + h2->val);
            h2 = h2->next;
            h1 = h1->next;
        }
        return res;
        
    }
};


int main() {


    return 0;
}