// https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=daily-question&envId=2024-01-16

#include <iostream> 
#include <unordered_map>
#include <vector>

using namespace std;


class RandomizedSet {
    unordered_map<int, int> map;    // val, index_vector
    vector<int> v;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (auto it = map.find(val); it != map.end()) 
            return false;
        
        v.push_back(val);
        map[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        auto it = map.find(val);
        if (it == map.end())
            return false;

        v[it->second] = v.back();
        map[v.back()] = it->second;
        map.erase(it);
        v.pop_back();

        return true;        
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};


int main() {
    RandomizedSet set;

    cout << set.insert(12) << endl;
    cout << set.insert(12) << endl;
    // cout << set.remove(12) << endl;
    cout << set.insert(14) << endl;
    cout << set.insert(15) << endl;
    cout << set.remove(14) << endl;
    cout << set.remove(14) << endl;
    cout << set.getRandom() << endl;
    cout << set.getRandom() << endl;

    return 0;
}