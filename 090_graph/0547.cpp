#include <iostream>
#include <vector>


using namespace std;


class Solution {
    vector<int> city;
    void dfs(vector<vector<int>>& isConnected, int i, int province) {
        city[i] = province;
        for (int k = 0; k < isConnected[i].size(); ++k) {
            if (isConnected[i][k]) {
                if (k == i) continue;
                if (city[k] == 0) {
                    city[k] = province;
                    dfs(isConnected, k, province);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty()) return 0;
        
        city.resize(isConnected.size(), 0);

        int province = 0;

        for (int i = 0; i < city.size(); ++i) {
            if (city[i] == 0) {
                ++province;
                dfs(isConnected, i, province);
            }
        }
        return province;
    }
};


int main() {
    vector<vector<int>> v = {{1,1,0},{1,1,0},{0,0,1}};
    auto res = Solution{}.findCircleNum(v);
    cout << "res: " << res << endl;
    return 0;
}