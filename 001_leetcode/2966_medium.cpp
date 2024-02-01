// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-question&envId=2024-02-01

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int left = 0;
        int right = 2;

        while (right < nums.size()) {
            if (nums[right] - nums[left] <= k) {
                res.push_back({nums[left], nums[left+1], nums[left+2]});
                right += 3;
                left += 3;
            }
            else {
                return {};
            }
        }
        return res;
    }
};


int main() {
    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    auto res = Solution{}.divideArray(nums, 2);

    cout << "res: " << res.size() << endl;
    return 0;
}
