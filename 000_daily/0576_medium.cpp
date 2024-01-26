// https://leetcode.com/problems/out-of-boundary-paths/description/?envType=daily-question&envId=2024-01-26

/**
 * Решение посмотрел в чужом примере и разобрался
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int M = 1e9 + 7;
        vector<vector<int>> dp (m, vector<int> (n, 0));
        dp[startRow][startColumn] = 1;
        int count = 0;                
        
        for (int move = 0; move < maxMove; ++move) {
            vector<vector<int>> temp (m, vector<int> (n, 0));
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    if (x == 0) count = (count + dp[x][y]) % M;
                    if (y == 0) count = (count + dp[x][y]) % M;
                    if (x == m-1) count = (count + dp[x][y]) % M;
                    if (y == n-1) count = (count + dp[x][y]) % M;

                    temp[x][y] = (
                        ((x == 0 ? 0 : dp[x-1][y]) + (x == m-1 ? 0 : dp[x+1][y])) % M +
                        ((y == 0 ? 0 : dp[x][y-1]) + (y == n-1 ? 0 : dp[x][y+1])) % M
                    ) % M;
                }
            }
            dp = temp;
        }
        return count;
    }
};


int main() {
    // Solution sol;
    // auto res = Solution{}.findPaths(8,7,16,1,5);
    auto res = Solution{}.findPaths(2,2,2,0,0);

    cout << "res " << res << endl;

    return 0;
}