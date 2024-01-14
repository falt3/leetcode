// https://leetcode.com/problems/house-robber/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+3, 0);
        // v[0] = nums[0];
        // v[1] = nums[1];
        // v[2] = v[0] + nums[2];
        for (int i = 0; i < n; ++i) {
            v[i+3] = max(v[i], v[i+1]) + nums[i]; 
        }
        return max(v[n+1], v[n+2]);
    }
};


int main() {
    // vector<int> nums = {2,7,9,3,1};
    vector<int> nums = {1,2,3,1};
    auto res = Solution{}.rob(nums);

    cout << "res: " << res << endl;
    return 0;
}