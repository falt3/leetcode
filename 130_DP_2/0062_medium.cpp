// https://leetcode.com/problems/unique-paths/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[j] = (i-1 >= 0 ? dp[j] : 0) +
                    (j-1 >= 0 ? dp[j-1] : 0);
                // dp[j] = max(tmp, 1);
            }
        }
        return dp[n-1];    
    }
};


int main() {
    auto res = Solution{}.uniquePaths(3,7);
    cout << "res: " << res << endl;

}