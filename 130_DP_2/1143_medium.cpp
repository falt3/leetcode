// https://leetcode.com/problems/longest-common-subsequence/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n2+1, vector<int> (n1+1,0));

        for (int i2 = 1; i2 <= n2; ++i2) {       // text2
            for (int i1 = 1; i1 <= n1; ++i1) {   // text1
                int tmp1 = max(dp[i2][i1-1], dp[i2-1][i1]);
                int tmp2 = dp[i2-1][i1-1] + (text1[i1-1] == text2[i2-1] ? 1 : 0);
                dp[i2][i1] =  max(tmp1, tmp2);
            }
        }
        
        return dp[n2][n1];
    }
};

int main() {
    // string text1 = "bsbininm";
    // string text2 = "jmjkbkjkv";
    string text1 = "abc";
    string text2 = "def";

    auto res = Solution{}.longestCommonSubsequence(text1, text2);

    cout << "res: " << res << endl;

    return 0;
}