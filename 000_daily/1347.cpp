// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/?envType=daily-question&envId=2024-01-13
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> um;
        for (auto el: s) 
            um[el] += 1;
        
        // for (auto el: t)
        //     um[el] -= 1;
        for (auto el: t) {
            if (auto it = um.find(el); it != um.end()) 
                if (it->second > 1)
                    it->second -= 1;
                else 
                    um.erase(it);

        }
        
        int ans = 0;
        for (auto [k, v]: um)
            // if (v > 0)
                ans += v;

        return ans;
    }
};


int main() {
    string s1 = "bab";
    string s2 = "aba";

    auto res = Solution{}.minSteps(s1, s2);

    cout << "res: " << res << endl;
    return 0;
}