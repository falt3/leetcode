#include <unordered_set>
#include <string>
#include <iostream>
#include <algorithm>
#include <array>


using namespace std;

// class Solution {
// public:
//     static int lengthOfLongestSubstring(string s) {
//         unordered_set<char> uset;
//         int max_count = 0;
//         int count = 0;
//         for (int i = 0; i < s.size(); ++i) {
//             cout << s[i] << endl;
//             if (auto res = uset.find(s[i]); res == uset.end()) {
//                 uset.insert(s[i]);
//                 ++count;
//             }
//             else {
//                 max_count = max(max_count, count);
//                 int j = i - count;
//                 while (s[i] != s[j]) {
//                     if (auto res2 = uset.find(s[j]); res2 != uset.end()) {
//                         cout << "erase: " << s[j] << endl;
//                         uset.erase(s[j]);
//                         --count;
//                         j++;
//                     }
//                     else 
//                         break;
//                 }
//             }
//         }
//         max_count = max(max_count, count);
//         return max_count;  
//     }
// };

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        array<int, 255> ar {0};
        int max_count = 0;
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            cout << s[i] << endl;
            if (!ar[s[i]]) {
                ar[s[i]] = 1;
                ++count;
            }
            else {
                max_count = max(max_count, count);
                int j = i - count;
                while (s[i] != s[j]) {
                    if (ar[s[j]]) {
                        cout << "erase: " << s[j] << endl;
                        ar[s[j]] = 0;
                        --count;
                        j++;
                    }
                    else 
                        break;
                }
            }
        }
        max_count = max(max_count, count);
        return max_count;  
    }
};


int main() {
    // int res = Solution::lengthOfLongestSubstring("jkshfk hwekhw");
    // int res = Solution::lengthOfLongestSubstring("bbbbbbb");
    // int res = Solution::lengthOfLongestSubstring("abcabcbb");
    // int res = Solution::lengthOfLongestSubstring("qrsvbspk");
    cout << "res: " << res << endl;

    return 0;
}