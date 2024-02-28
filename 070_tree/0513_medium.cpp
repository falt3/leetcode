#include <iostream>
// #include <

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
    void dfs(TreeNode* node, int current_length, int& length, int& value) {
        if (node == nullptr) return;

        if (current_length > length) {
            value = node->val;
            length = current_length;
        }
        dfs(node->left, current_length + 1, length, value);
        dfs(node->right, current_length + 1, length, value);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int length = 0;
        int value = 0;
        dfs(root, 1, length, value);
        return value;
    }
};

int main() {
    TreeNode node_7(7);
    TreeNode node_5(5); node_5.left = &node_7;
    TreeNode node_6(6);
    TreeNode node_3(3); node_3.left = &node_5; node_3.right = &node_6;
    TreeNode node_4(4);
    TreeNode node_2(2); node_2.left = &node_4;
    TreeNode node_1(1); node_1.left = &node_2; node_1.right = &node_3;

    auto res = Solution{}.findBottomLeftValue(&node_1);

    cout << "answer: " << res << endl;
    
    return 0;
}