// https://leetcode.com/problems/removing-stars-from-a-string/description/?envType=study-plan-v2&envId=leetcode-75
#include <deque>
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string removeStars(string s) {
        // deque<char> d;
        string s2;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                s2.pop_back();
            }
            else  
                s2.push_back(s[i]);
        }
        return s2;
    }
};


int main() {
    string s = "leet**cod*e";
    auto res = Solution{}.removeStars(s);
    cout << "res: " << res << endl;
    return 0;
}