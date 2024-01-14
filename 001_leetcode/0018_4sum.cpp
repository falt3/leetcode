#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    static vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // set<tuple<size_t, size_t, size_t>> uset;
        // unordered_set<tuple<size_t, size_t, size_t>> uset;

        vector<array<int, 3>> uv;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                int s = j + 1;
                int k = nums.size() - 1;
                long int delta;
                while (s < k) {
                    delta = nums[i] + nums[j] + nums[s] + nums[k];
                    if (delta == target) {
                        cout << nums[i] << " " << nums[j] << " " << nums[s] << " " << nums[k] << "   ";
                        array<int, 3> ar {nums[i], nums[j], nums[s]};
                        auto it = lower_bound(uv.begin(), uv.end(), ar,
                            [](auto& el1, auto& el2){
                                if (el1[0] < el2[0]) return true;
                                else if (el1[1] < el2[1]) return true;
                                else if (el1[2] < el2[2]) return true;
                                return false;
                        });
                        if (it == uv.end()) {
                            result.push_back({nums[i], nums[j], nums[s], nums[k]});
                        }
                        else if ((*it)[0] != ar[0] || (*it)[1] != ar[1] || (*it)[2] != ar[2])
                            result.push_back({nums[i], nums[j], nums[s], nums[k]});
                        // if (auto it = uset.find(tuple(nums[i], nums[j], nums[s])); it == uset.end()) {
                        //     uset.insert(tuple(nums[i], nums[j], nums[s]));
                        //     result.push_back({nums[i], nums[j], nums[s], nums[k]});
                        // }
                        ++s;
                        while (s < k && nums[s] == nums[s-1]) {++s;};
                        --k;
                        while (s < k && nums[k] == nums[k+1]) {--k;};
                    }
                    else if (delta > target) { 
                        --k; 
                        while (s < k && nums[k] == nums[k+1]) {--k;};
                    }
                    else { 
                        ++s; 
                        while (s < k && nums[s] == nums[s-1]) {++s;};
                    }
                }
            }
        }
        return result;
    }
};


int main () {
    vector<int> v1 {1,0,-1,0,-2,2};
    vector<int> v2 = {2,2,2,2,2};
    vector<int> v3 = {-3,-2,-1,0,0,1,2,3};
    vector<int> v4 = {1000000000,1000000000,1000000000,1000000000};
    vector<vector<int>> res = Solution::fourSum(v1, 0);
    // vector<vector<int>> res = Solution::fourSum(v2, 0);
    // vector<vector<int>> res = Solution::fourSum(v3, 0);
    // vector<vector<int>> res = Solution::fourSum(v4, 0);

    cout << "sizeof: " << sizeof(long int) << endl;

    cout << "count: " << res.size() << endl;

    auto fh1 = hash<int>{};
    // size_t h2 = hash<int>{};
    size_t h1 = fh1(1);
    size_t h2 = fh1(2);
    cout << "hash: " << h1 << "  " << h2 << endl;

    return 0;
}