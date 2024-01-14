#include <iostream>

using namespace std;

// Given an integer x, return true if x is a 
// palindrome, and false otherwise.

class Solution {
public:
    // static bool isPalindrome(int x) {
    //     long long rev = 0;
    //     int xx = x;
    //     if (x < 0)
    //         return false;
    //     while (x != 0) {
    //         rev = rev*10 + x%10;
    //         x = x/10;
    //     }
    //     cout << xx << endl;
    //     cout << rev << endl;
    //     if (xx != rev)
    //         return false;
    //     return true;        
    // }
    static bool isPalindrome(int x) {
        string s = to_string(x);
        int i = 0;
        int k = s.size() - 1;
        while (i < k) {
            if (s[i] != s[k]) return false;
            ++i;
            --k;
        }
        return true;
    }    
};

int main() {
    // auto res = Solution::isPalindrome(121);
    auto res = Solution::isPalindrome(1234567899);
    cout << res << endl;
    return 0;
}