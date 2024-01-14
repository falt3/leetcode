#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i-1] * nums[i-1];
        }

        int right = nums[n-1];
        for (int i = n - 2; i >= 0; --i) {
            // right[n-i-1] = right[n-i] * nums[n-i];
            // left[i] *= right[i];
            // cout << i << " " << ans[i] << " " << right << " " << nums[i] << endl;
            ans[i] *= right;
            right = right * nums[i];
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {1,2,3};
    auto res = Solution{}.productExceptSelf(nums);

    for (auto el: res)
        cout << el << " ";
    cout << endl;
    
    return 0;
}

