// https://leetcode.com/problems/keys-and-rooms/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> q;

        q.push(0);

        while (!q.empty()) {
            int room = q.front();
            q.pop();
            visited.insert(room);


            for (auto key: rooms[room]) {
                if (visited.count(key)) continue;
                q.push(key);
            }
        }
        return visited.size() == rooms.size();
    }
};


int main() {
    vector<vector<int>> rooms {{1},{2},{3},{}};
    auto res = Solution{}.canVisitAllRooms(rooms);

    cout << "res: " << res << endl;
}