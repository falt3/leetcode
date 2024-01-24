#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int res = 0;
        int n = arr.size();
        const int modulo = 1e9+7;
        
        for (int i = 0; i < n; ++i)
            res = (res + arr[i]) % modulo;

        for (int size = 1; size < n; ++size) {
            for (int i = 0; i < n - size; ++i) {
                arr[i] = min(arr[i], arr[i+1]);
                res = (res + arr[i]) % modulo;    
            }
        }
        return res;
    }
};

int main() {
    // vector<int> arr = {3,1,2,4};
    vector<int> arr = {11,81,94,43,3};
    auto res = Solution{}.sumSubarrayMins(arr);

    cout << "res: " << res << endl;
    return 0;
}