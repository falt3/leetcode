// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_units = 0;

        int count_units = 0;
        int count_units_prev = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                max_units = max(max_units, count_units + count_units_prev);
                count_units_prev = count_units;
                count_units = 0;
            }
            else {
                ++count_units;
            }
        }
        max_units = max(max_units, count_units + count_units_prev);

        // if (count_units_prev)
        //     return max_units;
        if (max_units == 0)
            return 0;
        else if (max_units < nums.size())
            return max_units;
        else 
            return max_units - 1;
    }
};

int main() {
    vector<int> nums {1,0,0,0,0};
    auto res = Solution{}.longestSubarray(nums);

    cout << "res: " << res << endl;
    
    return 0;
}