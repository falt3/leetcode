#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // int n = prices.size();
        // int price = 1000000;
        // int sum = 0;
        // int sell = 0;
        // for (int i = 0; i < n; ++i) {
            
        //     if (sell == 0) {
        //         price = min(price, prices[i]);
        //         if (prices[i] > price + fee) {
        //             sell = max(sell, prices[i] - price - fee);
        //         }                
        //     }
        //     else {
        //         if (prices[i] - price < sell) {
        //             sum += sell;
        //             sell = 0;
        //             price = prices[i];
        //         }
        //         else {
        //             sell = max(sell, prices[i] - price - fee);
        //         }
        //     }
        // }
        // sum += sell;
        // return sum;
        int buy = INT_MIN;
        int sell = 0;

        for (int price : prices) {
            buy = max(buy, sell - price);
            sell = max(sell, buy + price - fee);
            cout << price << " " << buy << " " << sell << endl;
        }

        return sell;
    }
};


int main() {
    // vector<int> prices = {1,3,8,5,10,3};
    vector<int> prices = {1,3,2,8,4,9};
    int res = Solution{}.maxProfit(prices, 2);
    cout << "res: " << res << endl;
    return 0;
}