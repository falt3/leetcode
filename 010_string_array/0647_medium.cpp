// https://leetcode.com/problems/palindromic-substrings/description/?envType=daily-question&envId=2024-02-10

#include <iostream>
#include <string>

using namespace std;


// class Solution {
//     bool isPolindrom(int left, int right, const string& s) {
//         bool ans = true;
//         while (left < right) {
//             if (s[left] != s[right])
//                 return false;
//             ++left;
//             --right;
//         }
//         return ans;
//     }
    
// public:
//     int countSubstrings(string s) {
//         int count = 0;
//         for (int i = 0; i < s.size(); ++i) {
//             ++count;
//             for (int k = i + 1; k < s.size(); ++k) {
//                 count += isPolindrom(i, k, s) ? 1 : 0;
//             }
//         }

//         return count;
//     }
// };

class Solution2 {
    int countPolindroms(int left, int right, const string& s) {
        int count = 0;
        while (left >= 0 && right < s.size() &&  s[left] == s[right]) {
           ++count; 
            --left;
            ++right;
        }
        return count;
    }
    
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            count += countPolindroms(i, i, s);
            count += countPolindroms(i, i+1, s);
        }
        return count;
    }
};


int main() {
    auto ans = Solution2{}.countSubstrings("abcba");

    cout << "answer: " << ans << endl;

    return 0;
}