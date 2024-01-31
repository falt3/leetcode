// https://leetcode.com/problems/evaluate-reverse-polish-notation/?envType=daily-question&envId=2024-01-30

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res;
        stack<int> q;
        for (auto el : tokens) {
            if (el == "+") {
                int b = q.top();
                q.pop();
                int a = q.top();
                q.pop();
                q.push(a+b);
            }
            else if (el == "-") {
                int b = q.top();
                q.pop();
                int a = q.top();
                q.pop();
                q.push(a-b);
            }
            else if (el == "*") {
                int b = q.top();
                q.pop();
                int a = q.top();
                q.pop();
                q.push(a*b);
            }
            else if (el == "/") {
                int b = q.top();
                q.pop();
                int a = q.top();
                q.pop();
                q.push(a/b);
            }
            else {
                q.push(stoi(el));
            }
        }
        return q.top();
    }
};

int main() {
    vector<string> tokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    auto res = Solution{}.evalRPN(tokens);

    cout << "res: " << res << endl;    

    return 0;
}