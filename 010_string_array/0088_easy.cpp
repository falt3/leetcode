// https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m - 1;
        int i2 = n - 1;
        int k = m + n - 1;

        while (k >= 0) {
            if (i1 < 0) {
                nums1[k] = nums2[i2];
                --i2;
            }
            else if (i2 < 0) {
                nums1[k] = nums1[i1];
                --i1;
            }
            else if (nums1[i1] >= nums2[i2]) {
                nums1[k] = nums1[i1];
                --i1;
            }
            else {
                nums1[k] = nums2[i2];
                --i2;
            }
            --k;
        }
    }
};

int main() {
    vector<int> nums1 {1,2,3,0,0,0};
    vector<int> nums2 {2,5,6};

    Solution{}.merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());

    for (auto it : nums1)
        cout << it << " ";
    cout << endl;

    return 0;    
}