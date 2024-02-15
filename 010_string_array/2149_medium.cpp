// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/?envType=daily-question&envId=2024-02-14

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        res.reserve(n);
        int i1 = 0;
        int i2 = 0;
        bool flNegative = false;
        for (int i = 0; i < n; ++i) {
            if (!flNegative) { // > 0
                while (i1 < n) {
                    if (nums[i1] > 0) {
                        res.push_back(nums[i1]);
                        ++i1;
                        break;
                    }
                    ++i1;
                }
            }
            else { // < 0
                while (i2 < n) {
                    if (nums[i2] < 0) {
                        res.push_back(nums[i2]);
                        ++i2;
                        break;
                    }
                    ++i2;
                }
            }
            flNegative = !flNegative;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {3,1,-2,-5,2,-4};

    auto res = Solution{}.rearrangeArray(nums);

    for (auto el: res)
        cout << el << " ";
    cout << endl;
    return 0;
}