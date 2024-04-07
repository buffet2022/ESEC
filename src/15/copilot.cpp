class Solution {
public:
    // 递归函数，计算以 root 为根节点的子树的最大深度
    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0; // 空节点的深度为 0
        }
        int leftDepth = helper(root->left); // 左子树的深度
        int rightDepth = helper(root->right); // 右子树的深度
        return std::max(leftDepth, rightDepth) + 1; // 返回左右子树中较大的深度加 1
    }

    // 计算二叉树的最大深度
    int maxDepth(TreeNode* root) {
        return helper(root);
    }
};