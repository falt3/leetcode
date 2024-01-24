#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count_zeroes = 1;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (!flowerbed[i]) {
                count_zeroes++;
                if (count_zeroes == 3) {
                    --n;
                    count_zeroes -= 2;
                }
            }
            else count_zeroes = 0;
        }
        if (count_zeroes == 2) n--;
        return n <= 0;
    }
};


int main() {
    vector<int> flow {1,0,0,0,1};
    auto res = Solution{}.canPlaceFlowers(flow, 1);

    cout << "res: " << res << endl;

    return 0;
}