// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int i1 = 1;
        int i2 = 1;
        int last = nums[0];

        while (i2 < n) {
            if (last >= nums[i1]) {
                while (i2 < n && last >= nums[i2]) 
                    i2++;
                if (i2 < n)
                    swap(nums[i1], nums[i2]);
                else break;
            }
            last = nums[i1];
            ++i1;
            ++i2;
        }
        return i1;
    }
};


int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    vector<int> nums = {1,1};
    auto res = Solution{}.removeDuplicates(nums);

    cout << "res: " << res << endl;

    return 0;
}