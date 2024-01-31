// https://leetcode.com/problems/n-th-tribonacci-number/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>

using namespace std;


class Solution {
public:
    int tribonacci(int n) {
        int a[3] {0,1,1};
        if (n < 3)
            return a[n];
        for (int i = 3; i <= n; ++i) {
            int tmp = a[0] + a[1] + a[2];
            a[0] = a[1];
            a[1] = a[2];
            a[2] = tmp;
        }
        return a[2];
    }
};

int main() {

    auto res = Solution{}.tribonacci(4);

    cout << "res: " << res << endl;

    return 0;
}