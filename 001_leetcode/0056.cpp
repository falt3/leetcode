#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[0] < b[0];
        });

        for (auto it = intervals.begin(); it < intervals.end(); ++it) {
            auto it2 = ans.begin();
            for (; it2 < ans.end(); ++it2) {
                if ((*it)[0] <= (*it2)[1]) {
                    (*it2)[1] = max((*it2)[1], (*it)[1]);
                    break;
                }
            }
            if (it2 == ans.end())
                ans.push_back(*it);
        }

        for (auto& el: ans)
            cout << el[0] << " " << el[1] << endl;
       
    }
};


class Solution2 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[0] < b[0];
        });

        int N = intervals.size();

        ans.push_back(intervals[0]);

        for (int i = 1; i < N; ++i) {
            
            if (intervals[i][0] <= ans[ans.size()-1][1]) {
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1], intervals[i][1]);
            }
            else 
                ans.push_back(intervals[i]);

            // for (; it2 >= ans.begin(); --it2) {
            //     if (intervals[i][0] <= (*it2)[1]) {
            //         (*it2)[1] = max((*it2)[1], intervals[i][1]);
            //         break;
            //     }
            // }
            // if (it2 < ans.begin())
            //     ans.push_back(intervals[i]);
        }
        

        for (auto& el: ans)
            cout << el[0] << " " << el[1] << endl;

        return ans;
       
    }
};


int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    // vector<vector<int>> intervals = {{1,4},{2,3}};
    Solution sol;
    auto res = Solution2{}.merge(intervals);
    

    return 0;
}