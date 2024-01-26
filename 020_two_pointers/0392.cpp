// https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool res = false;

        int i_s = 0;
        int i_t = 0;

        while (i_s < s.length()) {
            while (i_t < t.length()) {
                if (s[i_s] == t[i_t]) {
                    ++i_s;
                    ++i_t;
                    break;
                }
                ++i_t;
            }
            if (i_t == t.length() && i_s != s.length())
                return false;
        }

        return true;
    }
};


int main() {
    auto res = Solution{}.isSubsequence("abc", "ahbgdc");

    cout << "res: " << res << endl;

    return 0;
}