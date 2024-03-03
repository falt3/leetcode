// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto node1 = head;
        auto node2 = head;
        int i1 = 0;
        int i2 = 0;
        while (node1->next != nullptr) {
            node1 = node1->next;
            ++i1;
            if (i1 >= n)
                ++i2;
            if (i1 > n) 
                node2 = node2->next;
        }

        cout << i1 << " " << i2 << " " << node1->val << " " << node2->val << endl;

        if (i2 == 0) {
            return head->next;
        }
        else {
            node2->next = node2->next->next;
            return head;
        }
    }
};


int main() {
    // ListNode node_5(5);
    // ListNode node_4(4, &node_5);
    ListNode node_3(3);
    ListNode node_2(2, &node_3);
    ListNode node_1(1, &node_2);

    auto node = Solution{}.removeNthFromEnd(&node_1, 2);

    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;



    return 0;
}
