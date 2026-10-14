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
void inorder(TreeNode* node, vector<int> &result){
    if (node==nullptr)
    {
        return;
    }
    inorder(node->left,result);
    result.push_back(node->val);
    inorder(node->right,result); 
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> result;
        inorder(root,result);
        for(int i = 1; i < result.size(); i++){
            if(result[i-1] >= result[i]) return false;
        }
        return true;
    }
};


