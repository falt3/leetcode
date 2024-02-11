// https://leetcode.com/problems/cherry-pickup-ii/?envType=daily-question&envId=2024-02-11

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;


// class Solution {
//     bool isValidXY(int x, int y, int m, int n) {
//         return y >= 0 && y < n && x < m;
//     }
    
// public:
//     union XY{
//         int data;
//         struct {
//             char x;
//             char y1;
//             char y2;
//             char z;
//         };
//     };
//     int cherryPickup(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int steps[3] = {-1, 0, 1};

//         unordered_map<int, int> uset;
//         queue<pair<int, int>> q;      // x1, x2, y, sum
        
//         int count = 0;

//         XY xy;
//         xy.x = 0; xy.y1 = 0; xy.y2 = n-1; xy.z = 0;
        
//         q.push({xy.data, grid[0][0] + grid[0][n-1]});

//         while (!q.empty()) {
//             auto [aa, w] = q.front();
//             XY xy;
//             xy.data = aa;
//             q.pop();
            
//             if (auto it = uset.find(aa); it != uset.end()) {
//                 if (w < (*it).second) continue;
//             }
//             else 
//                 uset.insert({aa, w});
            
//             int xx = xy.x + 1;
//             for (auto step: steps) {                
//                 int yy1 = xy.y1 + step;
//                 if (isValidXY(xx, yy1, m, n)) {
//                     const int w1 = w + grid[xx][yy1];
//                     for (auto step2: steps) {
//                         int yy2 = xy.y2 + step2;
//                         if (isValidXY(xx, yy2, m, n)) {
//                             int w2 = w1 + (yy1 != yy2 ? grid[xx][yy2] : 0);
//                             XY e;
//                             if (yy1 <= yy2) {
//                                 e.x = xx; e.y1 = yy1; e.y2 = yy2;
//                             }
//                             else {
//                                 e.x = xx; e.y1 = yy2; e.y2 = yy1;
//                             }
//                             q.push({e.data, w2});
//                             count = max(count, w2);
//                         }
//                     }
//                 }
//             }
//         }

//         return count;        
//     }
// };


class Solution {
    int cell[71][71][71];
    int steps[3] = {-1,0,1};
    int bfs(const vector<vector<int>>& grid, int x, int y1, int y2, int m, int n) {
        if (x == m) return 0;
        if (y1 < 0 || y2 < 0 || y1 >= n || y2 >= n) return 0;
        if (cell[x][y1][y2] != -1) return cell[x][y1][y2];

        int ans = 0;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                ans = max(ans, bfs(grid, x+1, y1+steps[i], y2+steps[j], m, n));
            }
        }

        ans += (y1 == y2) ? grid[x][y1] : grid[x][y1] + grid[x][y2];
        return cell[x][y1][y2] = ans;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(cell, -1, sizeof(cell));
        int count = bfs(grid, 0, 0, n-1, m, n);
        return count;
    }
};


int main() {
    vector<vector<int>> grid0 = {
        {3,1,1},
        {2,5,1},
        {1,5,5},
        {2,1,1}
    };
    vector<vector<int>> grid = {
        {1,0,0,0,0,0,1},
        {2,0,0,0,0,3,0},
        {2,0,9,0,0,0,0},
        {0,3,0,5,4,0,0},
        {1,0,2,3,0,0,6}
    };
    // vector<vector<int>> grid = {
    //     {6,2,7,2,6},
    //     {5,10,2,7,9},
    //     {4,7,9,9,4},
    //     {4,9,5,10,0},
    //     {9,3,9,0,8},
    //     {2,1,7,0,3},
    //     {9,6,3,8,4},
    //     {0,10,10,0,7}
    // };
    
    // vector<vector<int>> grid = {
    //     {4,7,5,0,10,8,6},
    //     {7,8,1,4,3,8,8},
    //     {3,2,9,3,4,8,10},
    //     {5,4,1,9,9,8,8},
    //     {3,6,8,0,10,4,5},
    //     {1,9,1,9,5,7,5},
    //     {1,4,9,2,5,4,3},
    //     {8,9,6,9,10,2,7},
    //     {3,2,1,0,3,1,6},
    //     {4,2,2,3,8,0,1}
    // };

    auto res = Solution{}.cherryPickup(grid);

    cout << "answer: " << res << endl;
    return 0;
}