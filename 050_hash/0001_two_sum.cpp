#include <iostream>
#include <vector>
#include <unordered_map>

// #include <algorithm>
using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            auto res = target - nums[i];
            if (auto find = umap.find(res); find != umap.end()) {
                return {find->second, i};
            }
            umap[nums[i]] = i;
        }
        return {};      
    }
};

int main() {
    vector<int> v = {1, 3, 4, 5, 6, 7, 8, 2, 4};
    vector<int> v2 = Solution::twoSum(v, 9);
    for (auto el : v2) 
        cout << el << " ";

    return 0;
}