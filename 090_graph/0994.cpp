#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int steps[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<pair<int,pair<int,int>>> q;   // step, x, y

        int oranges = 0;
        for (int i = 0; i < m; ++i)
            for (int k = 0; k < n; ++k)
                if (grid[i][k] == 2) {
                    q.push({0, {i,k}});
                    grid[i][k] = 1;
                    ++oranges;
                }
                else if (grid[i][k] == 1)
                    ++oranges;

        int max_w = 0;
        
        while (!q.empty()) {
            auto [w, koord] = q.top();
            auto [x, y] = koord;
            q.pop();
            if (grid[x][y] == 2) continue;
            grid[x][y] = 2;
            --oranges;

            for (auto& step: steps) {
                int xx = x + step[0];
                int yy = y + step[1];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n || grid[xx][yy] != 1) continue;
                q.push({w-1,{xx,yy}});
            }
            max_w = max(max_w, -w);
        }   

        // for (int i = 0; i < m; ++i)
        //     for (int k = 0; k < n; ++k)
        //         if (grid[i][k] == 1) 
        //             return -1;
        if (oranges == 0)
            return max_w;            
        else 
            return -1;
    }
};

int main() {
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    // vector<vector<int>> grid = {{0,2}};

    auto res = Solution{}.orangesRotting(grid);

    cout << "res: " << res << endl;

    return 0;
}