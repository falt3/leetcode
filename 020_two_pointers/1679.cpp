// https://leetcode.com/problems/max-number-of-k-sum-pairs/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int res = 0;
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == k) {
                res++;
                ++left;
                --right;
            }
            else if (sum < k) {
                ++left;
            }
            else {
                --right;
            }
        }
        return res;
    }
};


int main() {
    vector<int> nums = {3,1,3,4,3};
    auto res = Solution{}.maxOperations(nums, 6);

    cout << "res: " << res << endl;

    return 0;
}