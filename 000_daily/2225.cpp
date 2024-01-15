// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=daily-question&envId=2024-01-15

#include <iostream> 
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> um;
        for (auto& el: matches) {
            um[el[0]] += 0;
            um[el[1]] += 1;
        }

        vector<vector<int>> res (2);
        // vector<pair<int, int>> vv;
        for (auto [player, lose]: um) {
            if (lose <= 1)
                res[lose].push_back(player);
        }
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());

        // sort(vv.begin(), vv.end());

        // for (auto& [lose, player]: vv) {
        //     if (lose <= 1) 
        //         res[lose].push_back(player);
        //     else
        //         break;
        // }

        return res;
    }
};

int main () {
    vector<vector<int>>  matches = {
        {1,3},{2,3},{3,6},{5,6},{5,7},
        {4,5},{4,8},{4,9},{10,4},{10,9}};
    
    vector<vector<int>> res = Solution{}.findWinners(matches);

    cout << "res: " << res[0].size() << " " << res[1].size() << endl;

    return 0;
}