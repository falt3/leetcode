// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75

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
    // status: 0 - none, 1 - left, 2 - right
    void dfs(TreeNode* node, int status, int path, int& maxPath) {
        if (node == nullptr)
            return;
        
        maxPath = max(maxPath, path);
        

        dfs(node->left, 1, (status != 1 ? path + 1 : 1), maxPath);
        dfs(node->right, 2, (status != 2 ? path + 1 : 1), maxPath);
        
    }

    int longestZigZag(TreeNode* root) {
        int maxPath = 0;
        dfs(root, 0, 0, maxPath);

        return maxPath;
    }
};


int main() {
    TreeNode node_7(1); 
    TreeNode node_6(1); node_6.right = &node_7;
    TreeNode node_5(1); 
    TreeNode node_4(1); node_4.right = &node_6;
    TreeNode node_3(1); node_3.left = &node_4; node_3.right = &node_5;
    TreeNode node_2(1); 
    TreeNode node_1(1); node_1.left = &node_2; node_1.right = &node_3;
    TreeNode node_0(1); node_0.right = &node_1;

    auto res = Solution{}.longestZigZag(&node_0);
// root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]

    cout << "res: " << res << endl;

    return 0;
}

