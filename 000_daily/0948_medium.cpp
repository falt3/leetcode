// https://leetcode.com/problems/bag-of-tokens/description/?envType=daily-question&envId=2024-03-04

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int ans = 0;
        int score = 0;
        int lht = 0;
        int rht = tokens.size() - 1;
        while (lht <= rht) {
            if (power >= tokens[lht]) {
                power -= tokens[lht];
                lht++;
                score++;
                ans = max(ans, score);
            }
            else if (score > 0) {
                power += tokens[rht];
                rht--;
                score--;
            }
            else 
                break;
        }
        return ans;
    }
};

int main() {
    vector<int> tokens = {100,200,300,400}; 
    int power = 200;
    auto res = Solution{}.bagOfTokensScore(tokens, power);

    cout << "answer: " << res << endl;
    return 0;
}