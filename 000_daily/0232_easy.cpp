// https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=daily-question&envId=2024-01-29

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> s[2];
    void revert() {
        while (!s[0].empty()) {
            s[1].push(s[0].top());
            s[0].pop();
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s[0].push(x);
    }
    
    int pop() {
        if (s[1].size() == 0)
            revert();
        int res = s[1].top();
        s[1].pop();
        return res;
    }
    
    int peek() {
        if (s[1].size() == 0)
            revert();
        return s[1].top();
    }
    
    bool empty() {
        if (s[1].size() == 0)
            revert();
        return s[1].empty();
    }
};


int main() {
    MyQueue m;

    m.push(1);
    m.push(2);
    cout << m.peek() << endl;
    cout << m.pop() << endl;
    cout << m.empty() << endl;

}