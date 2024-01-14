#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> uzels(n+1);
        
        for (auto& el: times) 
            uzels[el[0]].push_back({el[1], el[2]});
        
        vector<int> distance(n+1, 100001);
        vector<int> procesed(n+1, 0);
        priority_queue<pair<int,int>> q;

        distance[k] = 0;
        q.push({0,k});
        int mmm = 0;
        int count = 0;

        while (!q.empty()) {
            auto [w, i] = q.top();
            w = -w;
            q.pop();
            
            if (procesed[i]) continue;
            procesed[i] = 1;
            ++count;

            for (auto [kk, ww]: uzels[i]) {
                int w1 = ww + w;
                if (w1 < distance[kk]) {
                    distance[kk] = w1;
                    // mmm = max(w1, mmm);
                    q.push({-w1, kk});
                }
            }
        }
        // int mmm = max(distance.begin(), distance.end());
        for_each(distance.begin() + 1, distance.end(), [&mmm](auto el){
            if (el > mmm) 
                mmm = el;
        });

        cout << "count: "<< count << " " << n << " " << mmm << endl;
        if (count == n)
            return mmm;
        else 
            return -1;
    }
};


int main() {
    // vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    // vector<vector<int>> times = {{1,2,1},{2,1,3}};
    vector<vector<int>> times = {
        {3,5,78},{2,1,1}, {1,3,0}, {4,3,59},{5,3,85},
        {5,2,22},{2,4,23},{1,4,43},{4,5,75},{5,1,15},
        {1,5,91},{4,1,16},{3,2,98},{3,4,22},{5,4,31},
        {1,2,0}, {2,5,4}, {4,2,51},{3,1,36},{2,3,59}
    };
    auto res = Solution{}.networkDelayTime(times, 5, 5);

    cout << "res: " << res << endl;

    return 0;
}