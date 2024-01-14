#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int size = nums.size();
        mas.reserve(size + 1);
        mas[0] = 0;
        for (int i = 0; i <= size; ++i)
            mas[i+1] = mas[i] + nums[i];
    }
    
    int sumRange(int left, int right) {
        // int sum = 0;
        // for (int i = left; i <= right; ++i) {
        //     sum += mas[i];
        // }
        // sum = accumulate(mas.begin() + left, mas.begin() + right + 1, 0);
        return mas[right + 1] - mas[left];
    }

    vector<int> mas;
};


int main () {
    vector<int> v {-2, 0, 3, -5, 2, -1};
    NumArray a (v);
    int sum = a.sumRange(0, 5);
    cout << "res: " << sum << endl;

    return 0;
}