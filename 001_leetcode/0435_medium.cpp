// https://leetcode.com/problems/non-overlapping-intervals/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });

        int last = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (last <= intervals[i][0]) {
                last = intervals[i][1];
            }                    
            else 
                ++res;
        }
        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {
        {-52,31},{-73,-26},{82,97},{-65,-11},
        {-62,-49},{95,99},{58,95},{-31,49},
        {66,98},{-63,2},{30,47},{-40,-26}};

    auto res = Solution{}.eraseOverlapIntervals(intervals);

    cout << "res: " << res << endl;

    return 0;
}