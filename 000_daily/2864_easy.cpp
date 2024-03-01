// https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        auto it = partition(s.begin(), s.end(), [](auto a) {return a == '1';});
        swap(*(it-1), *(s.end()-1));
        return s;
    }
};


int main() {
    string s = "01010100";

    auto res = Solution{}.maximumOddBinaryNumber(s);

    cout << "answer: " << res << endl;

    return 0;
}