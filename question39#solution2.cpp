/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return check(root->left, root->right);
    }
    
    // 判断 a 和 b 两棵子树是否镜像对称
    bool check(TreeNode* a, TreeNode* b) {
        // 1. 两个都空 → 对称
        if (a == nullptr && b == nullptr) return true;
        // 2. 一个空一个非空 → 不对称
        if (a == nullptr || b == nullptr) return false;
        // 3. 值不同 → 不对称
        if (a->val != b->val) return false;
        // 4. 交叉比较
        return check(a->left, b->right) && check(a->right, b->left);
    }
};