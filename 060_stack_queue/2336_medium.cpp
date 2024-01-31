// https://leetcode.com/problems/smallest-number-in-infinite-set/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;


class SmallestInfiniteSet {
    priority_queue<int> q;
    unordered_set<int> s;
public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; ++i) {
            s.insert(i);
            q.push(-i);
        }
    }
    
    int popSmallest() {
        int res = -q.top();
        q.pop();
        s.erase(res);
        return res;
    }
    
    void addBack(int num) {
        if (!s.count(num)) {
            q.push(-num);
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

int main() {
    SmallestInfiniteSet s;
    s.addBack(2);
    cout << s.popSmallest() << endl;
    cout << s.popSmallest() << endl;
    cout << s.popSmallest() << endl;
    s.addBack(1);
    cout << s.popSmallest() << endl;
    cout << s.popSmallest() << endl;
    cout << s.popSmallest() << endl;

    return 0;
}