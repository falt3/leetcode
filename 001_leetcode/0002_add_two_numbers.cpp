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
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* dummyHead = new ListNode(0);
        // ListNode* curr = dummyHead;
        // int carry = 0;
        // while (l1 != NULL || l2 != NULL || carry != 0) {
        //     int x = l1 ? l1->val : 0;
        //     int y = l2 ? l2->val : 0;
        //     int sum = carry + x + y;
        //     carry = sum / 10;
        //     curr->next = new ListNode(sum % 10);
        //     curr = curr->next;
        //     l1 = l1 ? l1->next : nullptr;
        //     l2 = l2 ? l2->next : nullptr;
        // }
        // return dummyHead->next;

        ListNode* l3 = nullptr;        
        ListNode** node = &l3;
        
        int s = 0;
        while (l1 || l2 || s != 0) {
            if (l1) {
                s += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                s += l2->val;
                l2 = l2->next;
            }

            *node = new ListNode(s % 10);
            // else { 
            //     res = new ListNode(s % 10);
            // }
            node = &(*node)->next;
            s /= 10;
        }
        return l3;
    }
};

int main () {
    ListNode* l1 = new ListNode(0);;
    ListNode* pl1 = l1;
    for (int i = 1; i < 4; ++i) {
        pl1->next = new ListNode(i + 1);
        pl1 = pl1->next;
    }

    ListNode* l2 = new ListNode(0);;
    ListNode* pl2 = l2;
    for (int i = 1; i < 6; ++i) {
        pl2->next = new ListNode(9 - i);
        pl2 = pl2->next;
    }


    cout << "Result: ";
    ListNode* l3 = Solution::addTwoNumbers(l1, l2);
    do {
        cout << l3->val << " ";
        l3 = l3->next;
    } while (l3 != nullptr);
    cout << endl;    

    return 0;
}