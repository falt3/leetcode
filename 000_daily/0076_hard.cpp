// https://leetcode.com/problems/minimum-window-substring/description/?envType=daily-question&envId=2024-02-04

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;


// class Solution {
// public:
//     string minWindow(string s, string t) {
//         string ans;
//         unordered_map<char, int> chars;
//         for (auto it : t) {
//             if (auto el = chars.find(it); el == chars.end())
//                 chars.insert({it, chars.size()});
//         }
//         int count = chars.size();
        
//         vector<vector<int>> dp (s.size() + 1, vector<int> (chars.size(), 0));
//         int ans_i = -1;
//         int ans_count = s.size() + 1;

//         for (int i = 0; i < s.size(); ++i) {
//             if (auto el = chars.find(s[i]); el != chars.end()) { // есть элемент
//                 for (auto [ch, pos] : chars) {
//                     if (ch == s[i]) {
//                         dp[i][pos] = 0;
//                         dp[i+1][pos] = 1;
//                     }
//                     else {
//                         if (dp[i][pos] > 0) {
//                             dp[i+1][pos] = dp[i][pos] + 1;
//                         }
//                     }

//                     if (dp[i+1][pos] == count) {
//                         cout << "count: " << count << " " << i+1 << " " << ch << endl;
//                         int len = 0;
//                         for (int b = i+1; b >= 0; --b) {
//                             if (dp[b][pos] == 0) {
//                                 if (len < ans_count) {
//                                     ans_count = len;
//                                     ans_i = b;
//                                     cout << dp[b][pos] << " " << len << endl;
//                                     break;
//                                 }
//                             }
//                             len++;
//                         }
//                         dp[i+1][pos] = 0;
//                     }

//                 }
//             }
//             else { // нет элемента
//                 for (int k = 0; k < chars.size(); ++k)
//                     dp[i+1][k] = dp[i][k];
//             }
//         }

//         if (ans_i >= 0) {
//             for (int i = 0; i < ans_count; ++i, ++ans_i) 
//                 ans += s[ans_i];
//             return ans;
//         }
//         else 
//             return ans;
        
//     }
// };


class Solution2 {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        std::vector<int> map(128, 0);
        int count = t.length();
        int start = 0;
        int end = 0;
        int minLen = INT_MAX; 
        int startIndex = 0;

        for (char c : t) {
            map[c]++;
        }

        while (end < s.length()) {
            if (map[s[end++]]-- > 0) {
                count--;
            }

            while (count == 0) {
                if (end - start < minLen) {
                    startIndex = start;
                    minLen = end - start;
                }

                if (map[s[start++]]++ == 0) {
                    count++;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};

int main() {
    string s = "AADOBECODEBANC";
    string t = "ABC";
    // string s = "a";
    // string t = "a";

    auto res = Solution2{}.minWindow(s, t);

    cout << "res: " << res << endl;
    return 0;
}