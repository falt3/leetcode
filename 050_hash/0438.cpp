#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;


class Solution {
public:
    static vector<int> findAnagrams(string s, string p) {
        vector<int> v_res;
        if (p.size() > s.size()) return v_res;

        size_t sum_p = 0;
        size_t xor_p = 0;
        size_t sum_temp = 0;
        size_t xor_temp = 0;

        for (auto el: p) {
            sum_p += el;
            xor_p ^= el;
        }
        int len = p.size();

        for (int i = 0; i < len; ++i) {
            sum_temp += s[i];
            xor_temp ^= s[i];
        }

        int start = 0;
        while (true) {
            if (sum_p == sum_temp && xor_p == xor_temp)
                v_res.push_back(start);
            
            if (!(start + 1 <= s.size() - len)) break;

            sum_temp -= s[start];
            xor_temp ^= s[start];
            sum_temp += s[start + len];
            xor_temp ^= s[start + len];
            ++start;            
        }

        return v_res;
    }
};


class Solution2 {
public:
    static vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> freq(26); 
        for (auto& ch : p) ++freq[ch-'a']; 

        for (int i = 0; i < s.size(); ++i) {
            --freq[s[i]-'a']; 
            if (p.size() <= i) 
                ++freq[s[i-p.size()]-'a']; 
            if (p.size() <= i+1 && 
                all_of(freq.begin(), freq.end(), [](auto& x) {return x == 0;})) 
                ans.push_back(i-p.size()+1); 
        }
        return ans; 
    }
};


int main() {
    // string s = "cbaebabacd", p = "abc";
    // string 
    string s =  "abab", p = "ab";
    // string s = "af", p = "be";
    auto r = Solution2::findAnagrams(s, p);

    for(auto el: r)
        cout << el << " ";
    cout << endl;
    return 0;
}