#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(vector<string>& arr, int i, int mask, int &res) {
        for (char ch: arr[i]) {
            if (1 << (ch - 'a') & mask) return;
            else 
                mask |= 1 << (ch - 'a');
        }
        res = max(res, __builtin_popcount(mask));
        for (int k = i+1; k < arr.size(); ++k)
            dfs(arr, k, mask, res);
    }

    int maxLength(vector<string>& arr) {
        int res;
        for (int i = 0; i < arr.size(); ++i)
            dfs(arr, i, 0, res);
        return res;
    }
};


int main() {
    vector<string> arr = {"a", "abc", "d", "de", "def"};
    
    auto res = Solution{}.maxLength(arr);

    cout << "res: " << res << endl;
    
}