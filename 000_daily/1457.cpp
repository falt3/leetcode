#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Definition for a binary tree node.
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
    void dfs(TreeNode* node, int mask, int count, int& res) {
        if (mask & (1 << node->val)) --count;
        else ++count;
        mask ^= (1 << node->val);

        if (node->left == nullptr && node->right == nullptr) {
            // проверка на палиндромик
            if (count <= 1) ++res;
            return;
        }

        if (node->left) 
            dfs(node->left, mask, count, res);
        if (node->right) 
            dfs(node->right, mask, count, res);
    }


    int pseudoPalindromicPaths (TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return 1;

        int res = 0;
        dfs(root, 0, 0, res);

        return res;
    }
};

int main() {
    TreeNode node3 {3, nullptr, nullptr};
    TreeNode node4 {1, nullptr, nullptr};
    TreeNode node5 {1, nullptr, nullptr};

    TreeNode node1 {3, &node3, &node4};
    TreeNode node2 {1, nullptr, &node5};
    TreeNode node0 {2, &node1, &node2};

    auto res = Solution{}.pseudoPalindromicPaths(&node0);

// root = [2,3,1,3,1,null,1]
    cout << "res: " << res << endl;

    return 0;
}