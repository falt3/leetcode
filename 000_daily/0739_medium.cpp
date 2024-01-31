// https://leetcode.com/problems/daily-temperatures/description/?envType=daily-question&envId=2024-01-31

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        priority_queue<pair<int,int>> q;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            while (!q.empty()) {
                if (-q.top().first >= temperatures[i]) break;
                
                ans[q.top().second] = i - q.top().second;
                q.pop();                
            }
            q.push({-temperatures[i], i});
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> q;
        q.push(n-1);
        for (int i = n-2; i >= 0; --i) {
            while (!q.empty()) {
                if (temperatures[i] < temperatures[q.top()]) {
                    ans[i] = q.top() - i;
                    break;
                }
                else 
                    q.pop();
            }
            q.push(i);
        }
        return ans;
    }
};

int main() {
    // vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> temperatures = {30,40,50,60};
    auto res = Solution2{}.dailyTemperatures(temperatures);

    for (auto el : res)
        cout << el << " ";
    cout << endl;
    return 0;    
}