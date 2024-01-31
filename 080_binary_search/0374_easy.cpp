// https://leetcode.com/problems/guess-number-higher-or-lower/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>

using namespace std;

const int pick = 1;

int guess(int num) {
    if (num == pick) return 0;
    else if (num > pick) return -1;
    else return 1;
};


class Solution {
public:
    int guessNumber(int n) {
        int h = n >> 1;
        int num = h;
        int res;
        while (true) {
            int res = guess(num);

            if (res == 0) return num;
            
            h = h > 1 ? h >> 1 : 1;
            
            if (res < 0) num -= h;
            else num += h;
        }
        return 0;
    }
};

int main () {
    Solution{}.guessNumber(1);

    return 0;
}