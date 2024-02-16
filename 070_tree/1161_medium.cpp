// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 0;
        queue<pair<int, TreeNode*>> q;
        q.push({-1, root});
        int i = 0;
        int sum_i = INT_MIN;
        int sum_max = INT_MIN;
        while (!q.empty()) {
            auto [ii, node] = q.front();
            q.pop();
            if (ii != i) {
                if (sum_i > sum_max) {
                    ans = -i;
                    sum_max = sum_i;
                }
                sum_i = 0;
                i = ii;
            }
            sum_i += node->val;
            if (node->left != nullptr) q.push({ii-1, node->left});
            if (node->right != nullptr) q.push({ii-1, node->right});
        }
        if (sum_i > sum_max) {
            ans = -i;
            sum_max = sum_i;
        }

        return sum_max;
    }
};


int main() {
    TreeNode node_5(-10);
    TreeNode node_3(-20);
    TreeNode node_4(-5);
    TreeNode node_1(-200); node_1.left = &node_3; node_1.right = &node_4;
    TreeNode node_2(-300); node_2.left = &node_5;
    TreeNode node_0(-100); node_0.left = &node_1; node_0.right = &node_2;
    
    auto res = Solution{}.maxLevelSum(&node_0);
    cout << "answer: " << res << endl;
    return 0;
}