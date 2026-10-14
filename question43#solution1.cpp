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
bool check(TreeNode* root,long long lower,long long upper){
    if(!root) return true;
    if(lower < root->val && root->val < upper){
        return check(root->left,lower,root->val)&&check(root->right,root->val,upper);
    }else{
        return false;
    }
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return check(root->left,LONG_MIN,root->val)&&check(root->right,root->val,LONG_MAX);
    }
};