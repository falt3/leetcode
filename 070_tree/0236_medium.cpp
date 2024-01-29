// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    bool dfs(TreeNode* node, TreeNode* find, vector<TreeNode*>& path) {
        if (node == nullptr) return false;
        path.push_back(node);
        if (find == node) return true;

        if (dfs(node->left, find, path)) return true;
        if (dfs(node->right, find, path)) return true;
        path.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p;
        vector<TreeNode*> path_q;
        dfs(root, p, path_p);
        dfs(root, q, path_q);
        auto min_length = min(path_p.size(), path_q.size());
        for (int i = min_length-1; i >= 0; --i) {
            if (path_p[i] == path_q[i])
                return path_p[i];
        }

        return nullptr;
    }
};

//  Best
// TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//     if (!root || root == p || root == q) return root;
//     TreeNode* left = lowestCommonAncestor(root->left, p, q);
//     TreeNode* right = lowestCommonAncestor(root->right, p, q);
//     return !left ? right : !right ? left : root;
// }


int main() {
    TreeNode node_8(4);
    TreeNode node_7(7);
    TreeNode node_6(8);
    TreeNode node_5(0);
    TreeNode node_4(2); node_4.left = &node_7; node_4.right = &node_8;
    TreeNode node_3(6);
    TreeNode node_2(1); node_2.left = &node_5; node_2.right = &node_6;
    TreeNode node_1(5); node_1.left = &node_3; node_1.right = &node_4;
    TreeNode node_0(3); node_0.left = &node_1; node_0.right = &node_2;

    auto res = Solution{}.lowestCommonAncestor(&node_0, &node_1, &node_0);

    if (res == nullptr)
        cout << "res: nullptr\n";
    else 
        cout << "res: " << res->val << endl;
    
}