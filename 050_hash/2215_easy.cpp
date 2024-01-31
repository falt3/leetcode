// https://leetcode.com/problems/find-the-difference-of-two-arrays/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;


class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        ans.resize(2);
        unordered_set<int> s1;
        unordered_set<int> s2;
        for (auto el : nums1) 
            s1.insert(el);
        for (auto el : nums2) 
            s2.insert(el);
        
        for (auto el: s1) {
            if (!s2.count(el))
                ans[0].push_back(el);
        }
        for (auto el: s2) {
            if (!s1.count(el))
                ans[1].push_back(el);
        }


        return ans;
    }
};


int main() {

    return 0;
}