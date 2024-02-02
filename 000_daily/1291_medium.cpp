// https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2024-02-02

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // vector<int> ans;

        // int count_grade_low = 1;
        // int temp_low = low;
        // int temp_high = high;
        // while (temp_low/10 > 0) {
        //     ++count_grade_low;
        //     temp_low /= 10;
        //     temp_high /= 10;
        // }
        

        // for (int aaa = temp_low; temp_low < temp_high; ++temp_low, ++aaa) {
        //     int digit = 0;
        //     if (aaa + count_grade_low - 1 < 10) {
        //         for (int i = 0; i < count_grade_low; ++i) {
        //             digit += (aaa + i) * pow(10, count_grade_low-i-1);
        //         }
        //         ans.push_back(digit);
        //     }
        //     else {
        //         aaa /= 10;
        //         temp_low += (10 - temp_low%10);
        //         count_grade_low++;
        //     }
        // }

        // return ans;


        vector<int> a;

        for (int i = 1; i <= 9; ++i) {
            int num = i;
            int nextDigit = i + 1;

            while (num <= high && nextDigit <= 9) {
                num = num * 10 + nextDigit;
                if (low <= num && num <= high) a.push_back(num);
                ++nextDigit;
            }
        }

        sort(a.begin(), a.end());
        return a;
    }
};

int main() {
    auto res = Solution{}.sequentialDigits(300, 1400);

    for (auto el : res)
        cout << el << " ";
    cout << endl;

    return 0;
}