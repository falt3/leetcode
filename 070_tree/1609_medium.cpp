// https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-29

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
    bool dfs(TreeNode* node, int level, vector<int>& v) {
        if (node == nullptr) return true;

        if ((level % 2) == (node->val %2)) 
            return false;
        
        if (level >= v.size()) {
            v.push_back(node->val);
        }
        else {
            if (level % 2 == 1 && v[level] <= node->val) return false;
            if (level % 2 == 0 && v[level] >= node->val) return false;
            v[level] = node->val;
        }
        
        return dfs(node->left, level+1, v) && dfs(node->right, level+1, v);
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        vector<int> v;
        return dfs(root, 0, v);
    }
};


int main() {
    TreeNode node_3(3);
    TreeNode node_33(3);
    TreeNode node_7(7);
    TreeNode node_4(4); node_4.left = &node_3; node_4.right = &node_33;
    TreeNode node_2(2); node_2.left = &node_7; 
    TreeNode node_5(5); node_5.left = &node_4; node_5.right = &node_2;

    auto res = Solution{}.isEvenOddTree(&node_5);

    cout << "answer: " << res << endl;
}