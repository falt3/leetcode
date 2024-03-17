// https://leetcode.com/problems/insert-interval/?envType=daily-question&envId=2024-03-17

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        int start = newInterval[0];
        int finish = newInterval[1];
        for (; i < intervals.size(); ++i) {
            if (intervals[i][1] < start)
                ans.push_back(intervals[i]);
            else {
                if (intervals[i][0] < start) {
                    start = intervals[i][0];
                }
                break;
            }                
        }

        for (; i < intervals.size(); ++i) {
            if (finish < intervals[i][0]) {
                ans.push_back({start, finish});
                finish = 0;
                break;
            }
            else {
                finish = max(finish, intervals[i][1]);
            }
        }

        if (finish != 0)
            ans.push_back({start, finish});
        
        for (; i < intervals.size(); ++i) {
            if (intervals[i][0] > finish)
                ans.push_back(intervals[i]);
        }

        return ans;
    }
};


int main() {
    // vector<vector<int>> intervals {{1,2},{3,5},{6,7},{8,10},{12,16}};
    // vector<int> newInterval {4,8};
    vector<vector<int>> intervals {{1,5}};
    vector<int> newInterval {0,3};
    auto res = Solution{}.insert(intervals, newInterval);

    for (auto& el : res)
        cout << "[" << el[0] << "," << el[1] << "]  ";
    cout << endl;
    
    return 0;
}