// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (auto el: nums) {
            if (i <= 1 || el != nums[i-2]) {
                nums[i] = el;
                i++;
            }
        }
        return i;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,2,3,3};

    auto res = Solution{}.removeDuplicates(nums);

    cout << "answer: " << res << endl;
    for (auto el: nums)
        cout << el << " ";
    cout << endl;
    return 0;
}
