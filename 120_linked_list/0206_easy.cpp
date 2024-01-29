// https://leetcode.com/problems/reverse-linked-list/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>

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
    ListNode* reverseList(ListNode* head) {
        ListNode* h = head;
        ListNode* new_head = nullptr;
        while (h != nullptr) {
            h = head->next;
            head->next = new_head;
            new_head = head;
            head = h;            
        }
        return new_head;
    }
};


int main() {
    ListNode l_5(5);
    ListNode l_4(4, &l_5);
    ListNode l_3(4, &l_4);
    ListNode l_2(4, &l_3);
    ListNode l_1(4, &l_2);

    auto res = Solution{}.reverseList(&l_1);

    cout << "res: " << res->val << endl;

    return 0;
}