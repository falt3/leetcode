// https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::rotate(nums.rbegin(), nums.rbegin() + k / nums.size(), nums.rend());
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};

    Solution{}.rotate(nums, 3);

    for (auto el: nums)
        cout << el << " ";
    cout << endl;




    return 0;
}