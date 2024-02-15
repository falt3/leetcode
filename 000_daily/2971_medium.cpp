// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = accumulate(nums.begin(), nums.end()-1, (long long)0);
        
        for (int i = nums.size() - 1; i > 1; --i) {
            if (sum > nums[i]) {
                return sum + nums[i];
            }
            else {
                sum -= nums[i-1];
            }
        }     
        return -1;   
    }
};

int main() {
    vector<int> nums = {1,12,1,2,5,50,3};

    auto res = Solution{}.largestPerimeter(nums);
    


    cout << "answer: " << res << endl;
    return 0;
}