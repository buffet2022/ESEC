class Solution {
public:
    int maxDepth(TreeNode* root) {
        // 如果当前节点为空，则返回0
        if (root == nullptr) {
            return 0;
        }

        // 递归计算左子树和右子树的最大深度
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // 当前节点的最大深度是左右子树的最大深度加1
        return std::max(leftDepth, rightDepth) + 1;
    }
};