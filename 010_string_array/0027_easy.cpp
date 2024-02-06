// https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0] == val ? 0 : 1;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            if (nums[left] == val) {
                while (left < right) {
                    if (nums[right] != val) {
                        swap(nums[left], nums[right]);
                        break;
                    }
                    --right;
                }
                if (left >= right) break;
            }
            ++left;
        }
        return left;
    }
};

int main() {
    // vector<int> nums = {3,2,2,3};
    vector<int> nums = {0,1,2,2,3,0,4,2};
    // vector<int> nums {3,3};

    auto res = Solution{}.removeElement(nums, 2);
    
    for (int i = 0; i < res; ++i)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}