// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/?envType=study-plan-v2&envId=leetcode-75

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
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode* h = head;
        if (head->next == nullptr) return head;
        if (head->next->next == nullptr) {
            head->next = nullptr;
            return head;
        }
        h = head->next;
        ListNode* h2 = head;

        while (true) {
            if (h->next == nullptr) {
                h2->next = h2->next->next;
                break;
            }
            
            h = h->next;
            if (h->next == nullptr) {
                h2->next = h2->next->next;
                break;
            }
            h = h->next;
            h2 = h2->next;
        }
        

        return head;
    }
};

int main() {
    ListNode l_6(6);
    ListNode l_5(5, &l_6);
    ListNode l_4(4, &l_5);
    ListNode l_3(3, &l_4);
    ListNode l_2(2, &l_3);
    ListNode l_1(1, &l_2);

    auto h = &l_5;
    while (h != nullptr) {
        cout << h->val << " ";
        h = h->next;
    }
    cout << endl;


    auto res = Solution{}.deleteMiddle(&l_5);

    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}