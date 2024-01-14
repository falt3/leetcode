#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class vector_hasher {
public:
    std::size_t operator()(std::vector<int> const& vec) const {
        std::size_t seed = vec.size();
        for(auto& i : vec) {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};


class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        // map<vector<int>,int> mp;
        unordered_map<vector<int>, int, vector_hasher> mp;
        for(int i=0; i<n; i++){
            mp[grid[i]]++;
        }
        int count = 0;
        for(int c=0; c<n; c++){
            vector<int> temp;
            for(int r=0; r<n; r++){
                temp.push_back(grid[r][c]);
            }
            if(mp.find(temp) != mp.end()) count += mp[temp];
        }
        return count;  
    }
};



int main() {
    vector<vector<int>> grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    auto res = Solution{}.equalPairs(grid);

    cout << "res: " << res << endl;

    return 0;
}
