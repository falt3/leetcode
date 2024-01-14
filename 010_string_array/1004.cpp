#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int n = 0;
        int max_n = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) ++n;
            if (n > k) {
                while (n > k) {
                    if (nums[left] == 0) --n;
                    ++left;
                }
            }
            else 
                max_n = max(max_n, right-left+1);
            ++right;
        }
        return max_n;
    }
};


int main() {
    // vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};

    auto res = Solution{}.longestOnes(nums, 3);

    cout << "res: " << res << endl;

    return 0;
}