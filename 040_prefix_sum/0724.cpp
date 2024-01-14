#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n+1);
        // vector<int> right(n+1);
        
        left[0] = 0;
        for (int i = 0; i < n; ++i)
            left[i+1] = left[i] + nums[i];

        // right[n] = 0;
        // for (int i = n-1; i >= 0; --i)
        //     right[i] = right[i+1] + nums[i];

        for (int i = 0; i < n; ++i) {
            cout << "i: " << i << " " << left[i] << " " << left[n] - left[i+1] << endl;
            if (left[i] == (left[n] - left[i+1]))
                return i;
        }

        return -1;
    }
};


int main() {
    vector<int> nums = {1,7,3,6,5,6};
    auto res = Solution{}.pivotIndex(nums);

    cout << "res: " << res << endl;

    return 0;
}