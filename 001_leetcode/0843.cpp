#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

class Master {
public:
    Master(string word) : word_{word} {};
    int guess(string word) {
        int count = 0;
        for (int i = 0; i < min(word.size(), word_.size()); ++i) {
            if (word[i] == word_[i])
                ++count;
        }
        return count > 0 ? count : -1;
    }
private:
    string word_;
};
 
int comp_strings(const string& s1, const string& s2) {
    int size = min(s1.size(), s2.size());
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (s1[i] == s2[i])
            ++count;
    }
    return count;
}

int aaa = 0;

class Solution {
public:
    void ccc(vector<string>::iterator begin, vector<string>::iterator end, Master& master) {
        ++aaa;
        srand(std::time(0));
        int number = rand() % (distance(begin, end));
        string& choose_string = *(begin + number);
        int res = master.guess(choose_string);
        // cout << "choose_string: " << choose_string << "   res: " << res << endl;
        if (res == 6) return;
        if (res == -1) res = 0;
        auto it = partition(begin, end, [choose_string, res](auto& el)
        {
            int res_temp = comp_strings(choose_string, el);
            return res_temp == res;
        });
        
        // cout << "->: ";
        // for_each (begin, it, [](auto& el){cout << el << " ";});
        // cout << endl;
        // cout << "->: ";
        // for_each (it, end, [](auto& el){cout << el << " ";});
        // cout << endl << endl;

        ccc(begin, it, master);
    }

    void findSecretWord(vector<string>& words, Master& master) {
        ccc(words.begin(), words.end(), master);
    }
};

int main() {
    vector<string> v1 = {"acckzz","ccbazz","eiowzz","abcczz"};
    vector<string> v2 = {"wichbx","oahwep","tpulot","eqznzs","vvmplb","eywinm","dqefpt","kmjmxr","ihkovg","trbzyb","xqulhc","bcsbfw","rwzslk","abpjhw","mpubps","viyzbc","kodlta","ckfzjh","phuepp","rokoro","nxcwmo","awvqlr","uooeon","hhfuzz","sajxgr","oxgaix","fnugyu","lkxwru","mhtrvb","xxonmg","tqxlbr","euxtzg","tjwvad","uslult","rtjosi","hsygda","vyuica","mbnagm","uinqur","pikenp","szgupv","qpxmsw","vunxdn","jahhfn","kmbeok","biywow","yvgwho","hwzodo","loffxk","xavzqd","vwzpfe","uairjw","itufkt","kaklud","jjinfa","kqbttl","zocgux","ucwjig","meesxb","uysfyc","kdfvtw","vizxrv","rpbdjh","wynohw","lhqxvx","kaadty","dxxwut","vjtskm","yrdswc","byzjxm","jeomdc","saevda","himevi","ydltnu","wrrpoc","khuopg","ooxarg","vcvfry","thaawc","bssybb","ccoyyo","ajcwbj","arwfnl","nafmtm","xoaumd","vbejda","kaefne","swcrkh","reeyhj","vmcwaf","chxitv","qkwjna","vklpkp","xfnayl","ktgmfn","xrmzzm","fgtuki","zcffuv","srxuus","pydgmq"};
    Master m("ccoyyo");
    // cout << m.guess("absdrr") << endl;
    Solution s;
    s.findSecretWord(v2, m);

    cout << "aaa: "  << aaa << endl;

    return 0;
}