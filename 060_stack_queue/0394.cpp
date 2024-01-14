// https://leetcode.com/problems/decode-string/description/?envType=study-plan-v2&envId=leetcode-75
#include <iostream>
#include <string>
#include <stack>

using namespace std;

string aaa(const string& s, int& pos) {
    string ans;
    string str_number;
    for (; pos < s.size(); ++pos) {
        if (s[pos] == '[') {
            string s2 = aaa(s, ++pos);
            int n = stoi(str_number);
            for (int i = 0; i < n; ++i)
                ans += s2;
            str_number = "";
        }
        else {
            if (s[pos] >= '0' && s[pos] <= '9') {
                str_number += s[pos];
            }
            else if (s[pos] == ']') {
                return ans;
            }
            else {
                ans += s[pos];
            }
        }
    }
    return ans;
}

class Solution {
public:
    string decodeString(string s) {
        string ans;
        int i = 0;
        ans = aaa(s, i);        
        return ans;
    }
};


int main() {
    // string s = "3[a]2[bc]";
    string s = "3[a2[c]]";
    auto res = Solution{}.decodeString(s);
    cout << "res: " << res << endl;
    return 0;
}