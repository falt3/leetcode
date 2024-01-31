// https://leetcode.com/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=leetcode-75

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
    void dfs(TreeNode* node, int level, vector<int>& res) {
        if (node == nullptr) return ;
        
        if (level >= res.size())
            res.push_back(node->val);
        else 
            res[level] = node->val;

        dfs(node->left, level + 1, res);
        dfs(node->right, level + 1, res);
        
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};

int main() {
    TreeNode n_4(4);
    TreeNode n_3(5);
    TreeNode n_2(3); n_2.right = &n_4;
    TreeNode n_1(2); n_1.right = &n_3;
    TreeNode n_0(1); n_0.left = &n_1; n_0.right = &n_2;

    vector<int>  res = Solution{}.rightSideView(&n_0);


    for (auto el: res)
        cout << el << " ";
    cout << endl;


    return 0;
}