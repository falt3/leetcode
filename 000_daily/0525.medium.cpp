// https://leetcode.com/problems/contiguous-array/description/?envType=daily-question&envId=2024-03-16

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> map;
        map[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] == 1 ? 1 : -1);
            if (auto it = map.find(sum); it == map.end()) 
                map[sum] = i;
            else {
                ans = max(ans, i - it->second);
            }
        }        
        return ans;
    }
};

int main() {
    // vector<int> nums {0,0,1,0,0,0,1,1};
    // vector<int> nums {0,1,0,1};
    vector<int> nums {0,1};
    auto res = Solution{}.findMaxLength(nums);
    cout << "answer: " << res << endl;
    return 0;
}