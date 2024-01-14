#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        // подготовка
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }

        int max_sum = sum;

        for (int i = k; i < nums.size(); ++i) {
            sum = sum - nums[i-k] + nums[i];
            if (sum > max_sum) max_sum = sum;
        }

        return static_cast<double>(max_sum) / k;
    }
};


int main() {
    vector<int> nums ={1,12,-5,-6,50,3};
    auto res = Solution{}.findMaxAverage(nums, 4);

    cout << "res: " << res << endl;
    return 0;
}