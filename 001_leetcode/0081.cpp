#include <iostream>
#include <vector>

/**
 * @brief https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 */

using namespace std;


class Solution {
public:
    static int search(vector<int>& nums, int target) {

        auto rr = [&nums, target](int start, int end) 
        {
            int middle;
            if (start < end) {
                middle = (start + end) / 2;
                if (nums[middle] == target) return middle;
                if (nums[middle] >= nums[start]) {
                    if (target >= nums[start] && target < nums[middle]) end = middle;
                    else start = middle + 1;
                }
                else {
                    if (target > nums[middle] && target <= nums[end - 1] ) start = middle + 1;
                    else end = middle;
                }
                return rr(start, end);
            }
            return -1;
        };

        return rr(0, nums.size());
    }
};

int main() {
    // vector <int> v = {4,5,6,7,0,1,2};
    // vector <int> v = {4, 0, 1, 2};
    // vector <int> v = {2,5,6,0,0,1,2};
    vector<int> v = {1,2,1,1,1,1,1};
    // vector <int> v = {3,4,5,6,7,0,1,2};
    auto res = Solution::search(v, 2);

    // cout.setf(boolean);
    cout << res << endl;
}