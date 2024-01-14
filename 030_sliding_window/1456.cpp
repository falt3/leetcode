#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> chars = {'a', 'e', 'i', 'o', 'u'};

        int sum = 0;
        for (int i = 0; i < k; ++i)
            if (chars.count(s[i])) ++sum;
        
        int max_sum = sum;
        for (int i = k; i < s.size(); ++i) {
            if (chars.count(s[i-k])) --sum;
            if (chars.count(s[i])) ++sum;
            max_sum = max(max_sum, sum);
        }

        return max_sum;
    }
};


int main() {
    string s = "abciiidef";

    auto res = Solution{}.maxVowels(s, 3);

    cout << "res: " << res << endl;

    return 0;
}