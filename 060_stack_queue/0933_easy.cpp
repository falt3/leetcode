// https://leetcode.com/problems/number-of-recent-calls/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <queue>

using namespace std;


class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while (t - q.front() > 3000) {
            q.pop();
        }
        return q.size();
    }
};


int main() {
    RecentCounter r;
    cout << r.ping(1) << endl;
    cout << r.ping(100) << endl;
    cout << r.ping(3001) << endl;
    cout << r.ping(3002) << endl;
    cout << r.ping(3004) << endl;
    cout << r.ping(3202) << endl;
    cout << r.ping(8002) << endl;
}