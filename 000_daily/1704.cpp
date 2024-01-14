#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size() / 2;
        int n1 = 0;
        int n2 = 0;
        for (int i = 0; i < n; ++i) {
            set<char> letters {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
            
            if (letters.find(s[i]) != letters.end()) ++n1;
            if (letters.find(s[n+i]) != letters.end()) ++n2;

        }
        return n1 == n2;
    }
};


int main() {
    string s = "book";
    auto res = Solution{}.halvesAreAlike(s);
    cout << res << endl;
    return 0;
}