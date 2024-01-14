#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;


class Solution {
public:
    static vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> v_res;
        unordered_map<string, int> um;
        for (const auto& el: words) {
            if (auto it = um.find(el); it != um.end())
                it->second += 1;
            else 
                um.insert({move(el), 1});
        }

        auto cmp = [](const auto& a, const auto& b) -> bool {
            if (a.first != b.first) return a.first > b.first;
            else {
                return a.second < b.second;
            }            
        };
        set<pair<int, string>, decltype(cmp)> ss(cmp);

        // move(um.begin(), um.end(), insert_iterator((ss));
        for (const auto& el: um)
            ss.insert({el.second, move(el.first)});
        
        // for (const auto& el: ss)
        //     cout << el.first << "  " << el.second << endl;
        int i = 0;
        for (auto it = ss.begin(); i < k; ++it, ++i)
            v_res.push_back(it->second);

        return v_res;
    }
};



int main() {
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    auto res = Solution::topKFrequent(words, 2);

    for (auto el : res) {
        cout << el << ", ";
    }
    cout << endl;

    return 0;
}
