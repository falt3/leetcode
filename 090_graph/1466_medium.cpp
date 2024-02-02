// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>

using namespace std;


class Solution {
    vector<vector<pair<int, int>>> paths;  
    vector<int> visited;  
public:
    void dfs(int city, int& reverse) {
        visited[city] = 1;

        for (auto& el: paths[city]) {
            auto [city2, duration] = el;
            if (visited[city2]) continue;
            reverse += duration;
            dfs(city2, reverse);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
         // city1, city2, duration
        paths.resize(n);
        visited.resize(n, 0);
        for (auto& it: connections) {
            paths[it[0]].push_back({it[1], 1});
            paths[it[1]].push_back({it[0], 0});
        }
        int reverse = 0;
        dfs(0, reverse);

        return reverse;
    }
    
};


int main() {
    vector<vector<int>> connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    auto res = Solution{}.minReorder(6, connections);

    cout << "res: " << res << endl;

    return 0;
}