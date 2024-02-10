// https://leetcode.com/problems/greatest-common-divisor-of-strings/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;


class Solution {
    bool isCheck(const string& sub, const string& s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != sub[i % sub.size()]) return false;
        }
        return true;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int n = gcd(str1.size(), str2.size());
        string ans = str1.substr(0, n);
        if (isCheck(ans, str1) && isCheck(ans, str2))
            return ans;
        else return "";
    }
};

int main() {
    string str1 = "ABCABC"; 
    string str2 = "ABC";

    auto res = Solution{}.gcdOfStrings(str1, str2);
    cout << "answer: " << res << endl;
    return 0;
}