// https://leetcode.com/problems/asteroid-collision/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        ans.reserve(asteroids.size() >> 1);
        for (auto el: asteroids) {
            if (ans.empty() || ans.back() < 0 || el > 0) {
                ans.push_back(el);
            }
            else {
                bool fl_destroy = false;
                while (!ans.empty() && ans.back() > 0 && !fl_destroy) {
                    if (-el >= ans.back()) {
                        if (-el == ans.back()) fl_destroy = true;
                        ans.pop_back();
                    }
                    else 
                        fl_destroy = true;
                }                    
                if (!fl_destroy) 
                    ans.push_back(el);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> asteroids = {1,-1,-2,-2};

    auto res = Solution{}.asteroidCollision(asteroids);

    for (auto it: res)
        cout << it << " ";
    cout << endl;

    return 0;
}