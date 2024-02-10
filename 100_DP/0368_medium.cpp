// https://leetcode.com/problems/largest-divisible-subset/description/?envType=daily-question&envId=2024-02-09

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 1) return {nums[0]};

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> ans;
        vector<int> dp(nums.size(), 1);

        int maxi = 1;
        int maxi_i = 0;
        for (int i = 1; i < n; ++i) {
            for (int k = i-1; k >= 0; --k) {
                if ((nums[i] % nums[k] == 0) && dp[k]+1 > dp[i]) {
                    dp[i] = dp[k] + 1;
                    if (dp[i] > maxi) {
                        maxi = dp[i];
                        maxi_i = i;
                        break;                        
                    }
                }
            }
        }

        for (int i = 0; i < nums.size(); ++i) 
            cout << nums[i] << " " << dp[i] << endl;
        
        int num = nums[maxi_i];
        for (int i = maxi_i; i >= 0; i--) {
            if (maxi == dp[i] && !(num % nums[i])) {
                ans.push_back(nums[i]);
                maxi--;
                num = nums[i];
            }
        }
        return ans;
    }
};


int main() {
    // vector<int> nums = {1, 2, 3, 4, 6, 8, 12, 16, 30};
    vector<int> nums = {4,8,10,240};


    auto res = Solution{}.largestDivisibleSubset(nums);

    for (auto el: res)
        cout << el << " ";
    cout << endl;

    return 0;
}