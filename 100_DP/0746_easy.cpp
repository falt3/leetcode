// https://leetcode.com/problems/min-cost-climbing-stairs/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[2] = {0, cost[0]};
        for (int i = 1; i < cost.size(); ++i) {
            int tmp = cost[i] + min(dp[0], dp[1]);
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return min(dp[0], dp[1]);
    }
};


int main() {
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    auto res = Solution{}.minCostClimbingStairs(cost);

    cout << "res: " << res << endl;
    return 0;
}