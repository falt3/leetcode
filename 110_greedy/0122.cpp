#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i = 1;

        int max = 0;
        // int buy = 100000;

        // while (right < n) {
        //     if (prices[left] < prices[right])
        //         buy = min(buy, prices[left]);
        //     else {
        //         if (buy != 100000) {
        //             max += prices[left] - buy;
        //             buy = 100000;
        //         }
        //     }
        //     ++right;
        //     ++left;
        // }
        // if (buy != 100000)
        //     max += prices[n-1] - buy;

        while (i < n) {
            if (prices[i-1] < prices[i])
                max += prices[i] - prices[i-1];
            ++i;
        }

        return max;
    }
};


int main() {
    vector<int>  prices = {7,1,5,3,6,4};
    // vector<int> prices = {1,2,3,4,5};
    // vector<int>  prices = {7,6,4,3,1};
    int res = Solution{}.maxProfit(prices);
    cout << "res: " << res << endl;
    return 0;
}