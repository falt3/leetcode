// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int k = 0;
        for (int i = 0; i < spells.size(); ++i) {
            int aa = spells[i];
            auto it = lower_bound(potions.begin(), potions.end(), success,         
                [aa](auto el, auto success) {
                    return static_cast<long long>(aa) * el < success;
                }
            );
            ans.push_back(distance(it, potions.end()));
        }
        return ans;
    }
};

int main() {
    vector<int> spells = {3,1,2};
    vector<int> potions = {8,5,8};
    int success = 16;

    auto res = Solution{}.successfulPairs(spells, potions, success);

    cout << "res: " << res.size() << endl;

    for (auto el: res)
        cout << el << " ";
    cout << endl;

    return 0;
}