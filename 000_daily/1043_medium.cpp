// https://leetcode.com/problems/partition-array-for-maximum-sum/description/?envType=daily-question&envId=2024-02-03

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
    }
};


int main() {
    vector<int> arr = {1,15,7,9,2,5,10};
    auto res = Solution{}.maxSumAfterPartitioning(arr, 3);

    cout << "res: " << res << endl;
    return 0;
}