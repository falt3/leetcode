// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <algorithm>

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
    void dfs(TreeNode* node, int maxVal, int &count) {
        if (node->val >= maxVal) {
            ++count;
            maxVal = node->val;
        }

        if (node->left != nullptr) dfs(node->left, maxVal, count);
        if (node->right != nullptr) dfs(node->right, maxVal, count);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, root->val, count);

        return count;
    }
};


int main() {
    // root = [3,1,4,3,null,1,5]
    TreeNode node_3_1(3);
    TreeNode node_3_2(1);
    TreeNode node_3_3(5);
    TreeNode node_2_1(1); node_2_1.left = &node_3_1;
    TreeNode node_2_2(4); node_2_2.left = &node_3_2; node_2_2.right = &node_3_3;
    TreeNode node_1_1(3); node_1_1.left = &node_2_1; node_1_1.right = &node_2_2;

    auto res = Solution{}.goodNodes(&node_1_1);
    
    cout << "res: " << res << endl;
}