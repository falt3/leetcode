// https://leetcode.com/problems/find-all-people-with-secret/description/?envType=daily-question&envId=2024-02-24

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
    void search(vector<vector<int>>& meetings, int i1, int i2, vector<int>& persons_secret) {
        bool n = true;
        while (n) {
            n = false;
            for (int i = i1; i < i2; ++i) {
                if (persons_secret[meetings[i][0]] != persons_secret[meetings[i][1]]) {
                    persons_secret[meetings[i][0]] = 1;
                    persons_secret[meetings[i][1]] = 1;
                    n = true;
                }
            }
        }
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> persons_secret (n, 0);
        persons_secret[0] = 1;
        persons_secret[firstPerson] = 1;

        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        int time = 0;
        int i_start = 0;
        for (int i = 0; i < meetings.size(); ++i) {
            if (time != meetings[i][2]) {
                search(meetings, i_start, i, persons_secret);
                i_start = i;
                time = meetings[i][2];
            }
        }
        search(meetings, i_start, meetings.size(), persons_secret);

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (persons_secret[i] > 0)
                ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    // vector<vector<int>> meetings = {{1,4,3},{0,4,3}};
    vector<vector<int>> meetings = {{3,1,3},{1,2,2},{0,3,3}};
    auto res = Solution{}.findAllPeople(4, meetings, 3);

    for (auto el: res)    
        cout << el << " ";
    cout << endl;

    return 0;
}