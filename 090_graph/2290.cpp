#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;

        int M = grid.size();
        int N = grid[0].size();

        int steps[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};


        vector<queue<pair<int,int>>> vvv (M + N);
        vector<vector<int>> visited;
        vector<vector<int>> prices;
        visited.assign(M, vector<int>(N));
        prices.assign(M, vector<int>(N, 100000 + 1));

        prices[0][0] = 0;
        vvv[0].push({0,0});

        for (int price = 0; price < vvv.size(); ++price) {
            while (!vvv[price].empty()) {
                auto [x,y] = vvv[price].front();
                vvv[price].pop();
                if (x == M-1 && y == N-1) return price;
                
                if (visited[x][y]) continue;
                visited[x][y] = 1;

                for (auto& step: steps) {
                    int xx = x + step[0];
                    int yy = y + step[1];
                    if (xx < 0 || yy < 0 || xx >= M || yy >= N) continue;
                    if (prices[xx][yy] > price + grid[xx][yy]) {
                        prices[xx][yy] = price + grid[xx][yy];
                        cout << xx << " " << yy << " " << prices[xx][yy] << endl;
                        vvv[prices[xx][yy]].push({xx,yy});
                    }
                }
            }
        }      
        return -1;
    }
};


class Solution1 {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;

        int M = grid.size();
        int N = grid[0].size();

        int steps[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        vector<vector<int>> processed;
        processed.assign(M, vector<int>(N));

        vector<vector<int>> distance;
        distance.assign(M, vector<int>(N, 100000 + 1));

        priority_queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});

        while (!q.empty()) {
            auto w = -q.top().first;
            auto [x,y] = q.top().second;
            cout << x << " " << y << " " << distance[x][y] << endl;
            q.pop();
            if (x == M-1 && y == N-1) return w;

            if (processed[x][y]) continue;
            processed[x][y] = 1;
            
            for (auto& step: steps) {
                int xx = x + step[0];
                int yy = y + step[1];
                if (xx < 0 || yy < 0 || xx >= M || yy >= N) continue;
                if (distance[xx][yy] > w + grid[xx][yy]) {
                    distance[xx][yy] = w + grid[xx][yy];
                    q.push({-distance[xx][yy], {xx,yy}});
                    cout << "add: " << xx << " " << yy << " " << distance[xx][yy] << endl;
                }
            }
        }
        return -1;
    }
};


int main() {
    // vector<vector<int>> v {{0,1,1},{1,1,0},{1,1,0}};
    vector<vector<int>> v2 = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};

    Solution1 sol;
    auto res = sol.minimumObstacles(v2);
    cout << "res: " << res << endl;
}