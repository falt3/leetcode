// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>


using namespace std;


class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, const vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int shifts[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        priority_queue<pair<int, pair<int,int>>> q; // steps, <x,y>
        // unordered_set<long long> visited;
        vector<vector<uint8_t>> visited (m, vector<uint8_t>(n, 0));

        q.push({0, {entrance[0], entrance[1]}});

        while (!q.empty()) {
            auto [steps, aa] = q.top();
            auto [x,y] = aa;
            q.pop();
            if ((x == 0 || y == 0 || x == m-1 || y == n-1) && 
                !(x == entrance[0] && y == entrance[1]))
                return -steps;

            long long xy = ((x & 0xffff) << 16) + (y & 0xffff);
            // if (visited.count(xy)) continue;
            // visited.insert(xy);
            if (visited[x][y]) continue;
            visited[x][y] = 1;

            for (auto& shift : shifts) {
                int xx = x + shift[0];
                int yy = y + shift[1];
                if ((xx >= 0 && yy >= 0 && xx < m && yy < n) &&
                    (maze[xx][yy] == '.'))                    
                    q.push({steps-1, {xx,yy}});
            }
        }
        return -1;
    }
};


int main() {
    // vector<vector<char>> maze {
    //     {'+','+','.','+'},
    //     {'.','.','.','+'},
    //     {'+','+','+','.'}
    // };
    vector<vector<char>> maze {
        {'+','+','+'},
        {'.','.','.'},
        {'+','+','+'}
    };
    // vector<vector<char>> maze {
    //     {'.','+'},
    // };    

    auto res = Solution{}.nearestExit(maze, {1,0});
    cout << "res: " << res << endl;
    return 0;
}