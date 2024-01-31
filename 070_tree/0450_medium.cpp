// https://leetcode.com/problems/delete-node-in-a-bst/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>

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
    TreeNode* dfs(TreeNode* node, int val, int lr, TreeNode* parent_node) {
        if (node == nullptr) return nullptr;
        
        if (node->val == val) {
            TreeNode* new_node = nullptr;
            if (node->right != nullptr) {
                new_node = node->right;
                new_node->left = node.left;
            }
            else if (node->left != nullptr) new_node = node->left;


            if (lr = 1) {
                parent_node->left = new_node;
                return parent_node;
            }
            else if (lr = 2) {
                parent_node->right = new_node;
                return parent_node;
            }
            else {
                return nullptr;
            }
        }

        if (auto left = dfs(node->left, val, 1, node); left != nullptr) return node;
        if (auto right = dfs(node->right, val, 2, node); right != nullptr) return node;
        return nullptr;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return dfs(root, key, 0, nullptr);
    }
};

int main() {

    TreeNode n_5(7);
    TreeNode n_4(4);
    TreeNode n_3(2);
    TreeNode n_2(6); n_2.right = &n_5;
    TreeNode n_1(3); n_1.left = &n_3; n_1.right = &n_4;
    TreeNode n_0(5); n_0.left = &n_1; n_0.right = &n_2;

    auto res = Solution{}.deleteNode(&n_0, 4);

    cout << res->val << endl;



    return 0;
}
