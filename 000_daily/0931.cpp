// https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> w(n, vector<int>(n, INT_MAX));
        int dirs[3][2] = { {-1,-1},{-1,0},{-1,1} };

        w[0] = matrix[0];
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {   
                for (auto dir: dirs) {
                    int ii = i + dir[0];
                    int jj = j + dir[1];
                    if (ii < 0 || jj < 0 || ii >=n || jj >= n)
                        continue;
                    
                    w[i][j] = min(w[i][j], w[ii][jj] + matrix[i][j]);

                }
            }
        }
        auto it = min_element(w.back().begin(), w.back().end());
        return *it;
    }
};


int main() {
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    auto res = Solution{}.minFallingPathSum(matrix);

    cout << "res: " << res << endl;

    return 0;
}