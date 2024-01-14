// https://leetcode.com/problems/string-compression/description/?envType=study-plan-v2&envId=leetcode-75
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        char last_char = chars[0];
        int count_char = 1;
        int k = 1;
        for (int i = 1; i < chars.size(); ++i) {
            if (last_char == chars[i]) 
                ++count_char;
            else {
                if (count_char > 1) {
                    string sd = to_string(count_char);
                    for (auto el : sd) {
                        chars[k] = el;
                        ++k;
                    }
                }
                last_char = chars[i];
                count_char = 1;
                chars[k] = chars[i];
                ++k;
            }
        }
        if (count_char > 1) {
            string sd = to_string(count_char);
            for (auto el : sd) {
                chars[k] = el;
                ++k;
            }
        }
        return k;
    }
};


int main() {
    vector<char> chars = {'a','a','b','b','c','c','c'};
    // vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    auto res = Solution{}.compress(chars);

    for (int i = 0; i < res; ++i)
        cout << chars[i] << " ";
    return 0;
}