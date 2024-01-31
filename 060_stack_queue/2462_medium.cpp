// https://leetcode.com/problems/total-cost-to-hire-k-workers/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int> q;
        for (auto el : costs)
            q.push(-el);
        int res = 0;
        for (int i = 0; i < k; ++i) {
            res += -q.top();
            q.pop();
        }
        return res;
    }
};

int main() {
    // vector<int> costs {17,12,10,2,7,2,11,20,8};
    vector<int> costs {31,25,72,79,74,65,84,91,18,59,27,9,81,33,17,58};
    auto res = Solution{}.totalCost(costs, 11, 2);

    cout << "res: " << res << endl;
    return 0;
}