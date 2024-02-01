// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto& a, auto& b)
        {
            return a[1] < b[1];
        });

        int res = 1;
        int last = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > last) {
                res++;
                last = points[i][1];
            }
        }

        return res;
    }

};

int main() {
    vector<vector<int>> points = {{1,2},{3,4},{5,6},{7,8}};
    auto res = Solution{}.findMinArrowShots(points);

    cout << "res: " << res << endl;

    return 0;
}

