#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>


using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> edges(n);     // {city2, price}
        for (auto& el: flights)
            edges[el[0]].push_back({el[1], el[2]});
        
        // vector<priority_queue<pair<int, int>>> distance(n);
        // vector<int> distance(n, 0);
        // vector<int> parent(n, -1);
        vector<pair<int,pair<int, int>>> visited(n);    // {visited, {price, steps}}
        priority_queue<pair<int, pair<int,int>>> q; // {price, {city, steps}}
        stack<pair<int,int>> path;
        
        // distance[src] = 0;
        q.push({0,{src,0}});

        while (!q.empty()) {
            auto [w, aa] = q.top();
            w = -w;
            auto [city, steps] = aa;
            q.pop();

            if (city == dst) return w;
            if (steps == k+1) continue;

            auto [vis, bb] = visited[city];
            auto [w2, st2] = bb;
            if (vis == 0) {
                visited[city] = {1, {w, steps}};
            }
            else {
                if (steps > st2) continue;
            }

            for (auto [city_to, price_to]: edges[city]) {
                q.push({-(w+price_to), {city_to, steps+1}});
            }
        }
        return -1;
    }
};

class Solution2 {
    vector<vector<pair<int, int>>> edges;
    vector<int> processed;
    void dfs(int cur, int dst, int k, int kk, int dist, int& min_dist) {
        if (dist > min_dist) return;
        if (cur == dst) {
            min_dist = min(min_dist, dist);
            return;
        }
        if (kk > k) return;

        for (auto [vv, ww] : edges[cur]) {
            if (processed[vv]) continue;
            processed[vv] = 1;

            dfs(vv, dst, k, kk+1, dist+ww, min_dist);
            processed[vv] = 0;
        }
    };
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // vector<vector<pair<int, int>>> edges;

        edges.resize(n);
        for (auto& el: flights)
            edges[el[0]].push_back({el[1], el[2]});

        processed.resize(n, 0);
        
        int dist = 10000000;
        dfs(src, dst, k, 0, 0, dist);
        if (dist == 10000000) 
            return -1;
        else 
            return dist;
    }
};

int main() {
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    auto res = Solution{}.findCheapestPrice(4, flights, 0, 3, 1);
    // vector<vector<int>> flights = {
        // {0,1,100},{1,2,100},{0,2,300},{1,3,600},{2,3,200}};
    // vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    
    // vector<vector<int>> flights = {
    //     {0,1,100},{0,2,100},{0,3,10},{1,2,100},{1,4,10},
    //     {2,1,10},{2,3,100},{2,4,100},{3,2,10},{3,4,100}};
    // auto res = Solution{}.findCheapestPrice(5, flights, 0, 4, 3);

    cout << "res: " << res << endl;

    return 0;
}