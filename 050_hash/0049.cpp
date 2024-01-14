#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    static vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        vector<vector<string>> answer;
        for (int i = 0; i < strs.size(); ++i) {
            string el = strs[i];
            sort(el.begin(), el.end());
            umap[el].push_back(strs[i]);
        }
        for (auto& el : umap) {
            // if (el.second.size() > 1) {
            answer.push_back(std::move(el.second));
            // }
        }
        return answer;
    }
};

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res = Solution::groupAnagrams(strs);

    cout << "res: " << res.size() << endl;

    return 0;
}