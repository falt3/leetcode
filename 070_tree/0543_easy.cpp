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
    int fns(TreeNode* node, int& diametr) {
        if (node == nullptr) return 0;

        int left_length = fns(node->left, diametr);
        int right_length = fns(node->right, diametr);
        diametr = max(diametr, left_length + right_length);
        return max(left_length, right_length) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diametr = 0;
        fns(root, diametr);
        return diametr;
    }
};

int main() {
    TreeNode node_4(4);
    TreeNode node_5(5);
    TreeNode node_2(2); node_2.left = &node_4; node_2.right = &node_5;
    TreeNode node_3(3);
    TreeNode node_1(1); node_1.left = &node_2; node_1.right = &node_3;

    auto res = Solution{}.diameterOfBinaryTree(&node_1);

    cout << "answer: " << res << endl;

    return 0;
}