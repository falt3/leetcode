// https://leetcode.com/problems/furthest-building-you-can-reach/description/?envType=daily-question&envId=2024-02-17

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> q;

        int i = 1;
        for (; i < heights.size(); ++i) {
            int delta = heights[i] - heights[i-1];
            if (delta > 0) {
                q.push(delta);
                bricks -= delta;
                if (bricks < 0) {
                    if (ladders > 0) {
                        bricks += q.top();
                        q.pop();
                        ladders -= 1;
                    }
                    else {
                        break;
                    }
                }
            }            
        }
        
        return i - 1;
    }
};

int main() {
    vector<int> heights = {4,2,7,6,9,14,12};
    int bricks = 500;
    int ladders = 1;

    auto res = Solution{}.furthestBuilding(heights, bricks, ladders);

    cout << "answer: " << res << endl;

    return 0;
}