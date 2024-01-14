// https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=leetcode-75
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        vector<string> v;
        // string line;
        while (!ss.eof()) {
            // if (getline(ss, line) && !line.empty()) {
                string s2;
                ss >> s2;
                if (!s2.empty())
                    v.push_back(s2);
        }

        ostringstream sout;
        for (int i = v.size() -1; i > 0; --i)
            sout << v[i] << " ";
        sout << v[0];
        return sout.str();
    }
};


int main() {
    string s = "  hello world  ";
    auto res = Solution{}.reverseWords(s);
    cout << res << endl;
    return 0;
}
