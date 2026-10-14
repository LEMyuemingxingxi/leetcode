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
void preorder(TreeNode* node, vector<int>& res){
    if (node == nullptr){
        res.push_back(INT_MIN);   // 空标记
        return;
    }
    res.push_back(node->val);
    preorder(node->left, res);
    preorder(node->right, res);
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        queue<TreeNode*> q;
        if (r) q.push(r);
        while (!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                TreeNode* temp = node->left;
                node->left = node->right;
                node->right = temp;
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        int equal = 0;
        vector<int> l_result,r_result;
        preorder(l,l_result);
        preorder(r,r_result);
        if(l_result==r_result){
            return true;
        }else
        {
            return false;
        }
        
    }
};  