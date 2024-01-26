#include <iostream>
#include <vector>
#include <unordered_map>

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
    void dfs(TreeNode* node, int sum, unordered_map<int,int>& sums, int &count, int targetSum) {
        if (node == nullptr) return;

        sum = sum + node->val;
        
        if (sums.count(sum - targetSum)) {
            count += sums[sum - targetSum];
        }       

        sums[sum] += 1;
        
        dfs(node->left, sum, sums, count, targetSum);
        dfs(node->right, sum, sums, count, targetSum);

        sums[sum] -= 1;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;

        int count = 0;
        unordered_map<int, int> sums;
        sums[0] = 1;
        dfs(root, 0, sums, count, targetSum);

        return count;    
    }
};


int main() {
    TreeNode node_4_1(3);
    TreeNode node_4_2(-2);
    TreeNode node_4_3(1);

    TreeNode node_3_1(3); node_3_1.left = &node_4_1; node_3_1.right = &node_4_2;
    TreeNode node_3_2(2); node_3_2.right = &node_4_3;
    TreeNode node_3_3(11);

    TreeNode node_2_1(5); node_2_1.left = &node_3_1; node_2_1.right = &node_3_2;
    TreeNode node_2_2(-3); node_2_2.right = &node_3_3;

    TreeNode node_1_1(10); node_1_1.left = &node_2_1; node_1_1.right = &node_2_2;

    auto res = Solution{}.pathSum(&node_1_1, 8);

    cout << "res: " << res << endl;
}