// https://leetcode.com/problems/dota2-senate/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <queue>
#include <string>

using namespace std;


class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q[2];    
        int n = senate.size();
        int i = 0;
        for (auto el : senate) {
            el == 'R' ? q[0].push(i) : q[1].push(i);
            ++i;
        }

        while (!q[0].empty() && !q[1].empty()) {
            int i_R = q[0].front();
            int i_D = q[1].front();
            q[0].pop(); q[1].pop();

            i_R < i_D ? q[0].push(i_R + n) : q[1].push(i_D + n);
        }

        return !q[0].empty() ? "Radiant" : "Dire";
    }
};


int main() {
    auto res = Solution{}.predictPartyVictory("RDDR");
    cout << res << endl;
    return 0;
}
