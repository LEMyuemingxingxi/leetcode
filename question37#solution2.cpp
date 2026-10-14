int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    
    while (!q.empty()) {
        int size = q.size();          // 锁定当前层节点数
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        depth++;                      // 这一层处理完
    }
    return depth;
}