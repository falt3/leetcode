#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <tuple>

using  namespace std;


// class Solution {
//     vector<vector<int>> cnt;
//     int ans = 0, M, N, dirs[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//     int dfs(vector<vector<int>> &A, int x, int y) {
//         if (cnt[x][y]) return cnt[x][y];
//         cnt[x][y] = 1;
//         for (auto &dir : dirs) {
//             int a = x + dir[0], b = y + dir[1];
//             if (a < 0 || b < 0 || a >= M || b >= N || A[a][b] <= A[x][y]) continue;
//             cnt[x][y] = max(cnt[x][y], 1 + dfs(A, a, b));
//         }
//         return cnt[x][y];
//     }
// public:
//     int longestIncreasingPath(vector<vector<int>>& A) {
//         if (A.empty() || A[0].empty()) return 0;
//         M = A.size(), N = A[0].size();
//         cnt.assign(M, vector<int>(N));
//         for (int i = 0; i < M; ++i) 
//             for (int j = 0; j < N; ++j) 
//                 ans = max(ans, dfs(A, i, j));
//         return ans;
//     }
// };

// class Solution {
// public:
//     array<array<int, 2>, 4> ar = {{ {0,1}, {0,-1}, {1,0}, {-1,0} }};
    
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
//         if (matrix.size() < 1) return 0;
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int max = 1;

//         map<tuple<int, int, int>, int> mmm;
        
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 mmm.insert({make_tuple(matrix[i][j], i, j), 1});
//             }
//         }

//         for(auto& it: mmm) {
//             // cout << el.first << endl;
//             auto [val,x,y] = it.first;
//             int w = it.second;
//             for (auto add: ar) {
//                 int xx = x + add[0];
//                 int yy = y + add[1];
//                 if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
//                     if (matrix[xx][yy] > val) {
//                         int ww = w + 1;
//                         auto f = mmm.find({matrix[xx][yy], xx, yy});
//                         if (ww > f->second) {
//                             f->second = ww;
//                             if (max < ww)
//                                 max = ww;
//                         }
//                     }
//                 }
//             }
//         }

//         // for (auto& it: mmm) {
//         //     auto [val,x,y] = it.first;
//         //     cout << x << " " << y << " " << val << " " << it.second << endl;
//         // }


//         return max;
//     }
// };


class Solution {
    int M, N;
    int dirs[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    vector<vector<int>> weights;
    int dfs(vector<vector<int>>& matrix, int x, int y) {
        if (weights[x][y]) return weights[x][y];
        weights[x][y] = 1;
        for (auto& dir: dirs) {
            int xx = x + dir[0];
            int yy = y + dir[1];
            if (xx < 0 || yy < 0 || xx >= M || yy >= N || matrix[x][y] >= matrix[xx][yy])
                continue;
            weights[x][y] = max(weights[x][y], 1 + dfs(matrix, xx, yy));
        }
        return weights[x][y];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        M = matrix.size();
        N = matrix[0].size();
        int ans = 0;
        weights.assign(M, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                ans = max(ans, dfs(matrix, i , j));
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    // vector<vector<int>> matrix = {{3,4,5},{3,2,6},{2,2,1}};
    // vector<vector<int>> matrix = {{0}};

    Solution sol;
    auto res = sol.longestIncreasingPath(matrix);

    cout << res << endl;
}