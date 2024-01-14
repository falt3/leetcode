#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <stack>

using namespace std;



class Solution {
public:
    static int numIslands(vector<vector<char>>& grid) {
        int move[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        std::function<void(int,int)> search_island;
        search_island = [&](int i, int j) {
            for (auto el : move) {
                int x = i + el[0];
                int y = j + el[1];
                if (x >= 0 && x < grid.size() && y >= 0  && y < grid[0].size()) {
                    if (grid[x][y] == '1') {
                        grid[x][y] = '0';
                        search_island(x, y);
                    }
                }
            }
        };

        int count_islands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    search_island(i, j);

                    ++count_islands;
                    cout << "x:y:" << i << " " << j << endl;
                }
            }               
        }
        return count_islands;
    }
};

class Solution2 {
public:
    static int numIslands(vector<vector<char>>& grid) {
        int steps[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        stack<pair<int,int>> st;
        int count_islands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    st.push({i, j});
                    while (!st.empty()) {
                        auto cell = st.top();
                        st.pop();
                        for (auto el : steps) {
                            int x = cell.first + el[0];
                            int y = cell.second + el[1];
                            if (x >= 0 && x < grid.size() && y >= 0  && y < grid[0].size()) {
                                if (grid[x][y] == '1') {
                                    grid[x][y] = '0';
                                    st.push({x, y});
                                }
                            }
                        }        
                    }

                    ++count_islands;
                    cout << "x:y:" << i << " " << j << endl;
                }
            }               
        }
        return count_islands;
    }
};


int main() {
    vector<vector<char>> v1 = {
                    {'1','1','1','1','0'},
                    {'1','1','0','1','0'},
                    {'1','1','1','0','1'},
                    {'0','0','0','1','0'}
    };

    auto res = Solution::numIslands(v1);
    cout << "res: " << res << endl;
    return 0;
}
