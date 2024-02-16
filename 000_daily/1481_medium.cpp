// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/?envType=daily-question&envId=2024-02-16

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (auto el: arr)
            m[el]++;
        
        priority_queue<int> q;
        for (auto el: m)
            q.push(-el.second);
        
        while (-q.top() <= k) {
            k += q.top();
            q.pop();            
        }
        return q.size();
    }
};

int main() {
    vector<int> arr = {4,3,1,1,3,3,2};
    int k = 3;

    auto res = Solution{}.findLeastNumOfUniqueInts(arr, k);

    cout << "answer: " << res << endl;

    return 0;
}