#include <iostream>
#include <vector>
#include <array>

using namespace std;


class Solution {
public:
    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size(); 
        array<int, 2> mas;
        int i = 0;
        int j = 0;
        int k = 0;
        while (k < size/2 + 1 ) {
            if (i < nums1.size() && j < nums2.size()) {
                if (nums1[k] < nums2[j]) {
                    mas[k % 2] = nums1[i];
                    ++i;
                }
                else {
                    mas[k % 2] = nums2[j];
                    ++j;
                }
            }
            else if (i < nums1.size()) {
                mas[k % 2] = nums1[i];
                ++i;
            }
            else if (j < nums2.size()) {
                mas[k % 2] = nums2[j];
                ++j;
            }
            else {
                break;
            }
            ++k;
        }

        if (size % 2 == 1) 
            return mas[(size/2) % 2];
        else 
            return double(mas[0] + mas[1]) / 2;
    }
};



int main() {
    vector<int> v1 = {1, 3};
    vector<int> v2 = {2, 7};

    auto res = Solution::findMedianSortedArrays(v1, v2);

    cout << "median: " << res << endl;

    return 0;
}