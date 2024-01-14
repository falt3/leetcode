#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;

        for (auto el: nums) 
            umap[el] += 1;

        vector<pair<int, int>> v (umap.size());
        int i = 0;
        for (auto el: umap) {
            v[i].first = el.second;
            v[i].second = el.first;
            ++i;
        }

        for (auto el: v)
            cout << "[" << el.first << ", " << el.second << "] ";
        cout << endl;

        // partial_sort(v.begin(), v.begin() + k, v.end(), [](auto a, auto b){
        //     return a > b;
        // });
        make_heap(v.begin(), v.end());

        for (auto el: v)
            cout << "[" << el.first << ", " << el.second << "] ";
        cout << endl;

        cout << endl;
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            // res.push_back(v[i].second);
            res.push_back(v.front().second);
            pop_heap(v.begin(), v.end() - i);

        for (auto el: v)
            cout << "[" << el.first << ", " << el.second << "] ";
        cout << endl;

        }
        return res;
    }
};


int main() {
    // vector<int> v = {2,2,3,1,1,1,1,4,3,2};
    // vector<int> v = {1,1,1,2,2,2,3,3,3};
    vector<int> v = {1, 2};
    auto res = Solution{}.topKFrequent(v, 2);

    for (auto el: res)
        cout << el << " ";
    cout << endl;
    return 0;
}