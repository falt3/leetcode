// https://leetcode.com/problems/odd-even-linked-list/?envType=study-plan-v2&envId=leetcode-75

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* node_odd = head;
        ListNode* node_even = head->next;
        while (node_even != nullptr) {
            if (node_even->next == nullptr) break;
            
            ListNode* node_copy = node_even->next;
            node_even->next = node_even->next->next;
            node_copy->next = node_odd->next;
            node_odd->next = node_copy;

            node_odd = node_odd->next;
            node_even = node_even->next;
        }
        return head;
    }
};

int main() {
    ListNode node6(6);
    ListNode node5(5, &node6);
    ListNode node4(4, &node5);
    ListNode node3(3, &node4);
    ListNode node2(2, &node3);
    ListNode node1(1, &node2);

    ListNode* node = &node1;
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
    


    node = Solution{}.oddEvenList(&node1);
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    return 0;
}