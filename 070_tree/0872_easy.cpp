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
public:
    void dfs_tree(TreeNode* node, vector<int>& v) {
        if (node->left == nullptr && node->right == nullptr) {
            v.push_back(node->val);
            return;
        }

        if (node->left != nullptr)
            dfs_tree(node->left, v);
        if (node->right != nullptr)
            dfs_tree(node->right, v);
    }


    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;    

        dfs_tree(root1, v1);
        dfs_tree(root2, v2);

        return v1 == v2;
    }
};

// root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]

int main() {

    
    return 0;
}