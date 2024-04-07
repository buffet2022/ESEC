class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        maxPathSum(root, maxPathSum);
        return maxPathSum;
    }

private:
    int maxPathSum(TreeNode* root, int& maxPathSum) {
        if (root == nullptr) {
            return 0;
        }

        int leftMaxPathSum = maxPathSum(root->left, maxPathSum);
        int rightMaxPathSum = maxPathSum(root->right, maxPathSum);

        // 1. 以 root 为路径终点的最大路径和
        int maxPathSumEndingAtRoot = max(root->val, root->val + leftMaxPathSum, root->val + rightMaxPathSum);

        // 2. 以 root 为路径中间节点的最大路径和
        int maxPathSumThroughRoot = max(maxPathSumEndingAtRoot, leftMaxPathSum + root->val + rightMaxPathSum);

        // 更新最大路径和
        maxPathSum = max(maxPathSum, maxPathSumThroughRoot);

        return maxPathSumEndingAtRoot;
    }
};