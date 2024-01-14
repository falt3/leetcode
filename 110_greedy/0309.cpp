// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy = 100;
        int sell = 0;
        int rest = 0;
        int sum = 0;
        
        for (auto price: prices) {
            sell = max(buy, sell);
            rest = 
            buy = min(buy, price);
            
        }
        
    }
};


int main() {
    vector<int> v = {1,2,3,0,2};
    auto res = Solution{}.maxProfit(v);

    cout << "res: " << res << endl;
    return 0;
}
