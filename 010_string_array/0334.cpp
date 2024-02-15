// https://leetcode.com/problems/increasing-triplet-subsequence/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> tmp;
        tmp.push_back(nums[0]);
        tmp.push_back(INT_MAX);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > tmp[1]) {
                return true;
            }
            else {
                if (tmp[0] >= nums[i]) tmp[0] = nums[i];
                else if (tmp[1] > nums[i]) tmp[1] = nums[i];
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1,1,-2,6};

    auto res = Solution{}.increasingTriplet(nums);

    cout << "answer: " << res << endl;
}