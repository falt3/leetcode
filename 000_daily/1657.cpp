// https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=daily-question&envId=2024-01-14

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        array<int, 26> s1 {0};
        array<int, 26> s2 {0};
        int n = word1.size();

        for (int i = 0; i < n; ++i) {
            s1[word1[i]-'a'] += 1;
            s2[word2[i]-'a'] += 1;
        }

        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i] && (s1[i] == 0 || s2[i] == 0))
                return false;
        }

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return s1 == s2;
    }
};

int main() {
    string word1 = "abc", word2 = "bca";

    auto res = Solution{}.closeStrings(word1, word2);
    cout << res << endl;
    return 0;
}