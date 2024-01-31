// https://leetcode.com/problems/search-in-a-binary-search-tree/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>

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
    TreeNode* dfs(TreeNode* node, int val) {
        if (node == nullptr) return nullptr;
        if (node->val == val) return node;

        TreeNode* left = dfs(node->left, val);
        TreeNode* right = dfs(node->right, val);
        return (left != nullptr ? left : (right != nullptr ? right : nullptr));
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return dfs(root, val);
    }
};

int main() {

}