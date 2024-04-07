class Solution {
public:
    //  int left = maxPathSum(root->left)
    //  int right = maxPathSum(root->right)
    // 路径是什么意思
    // 注意左右子树的正负值分析
    int res = INT_MIN;
    int maxPathSum(TreeNode * root){
        // res = root->val;
        // if(root->left == nullptr && root->right == nullptr) return root->val;
        maxPathSumHelper(root);
        return res;
    }
    int maxPathSumHelper(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = maxPathSumHelper(root->left);
        int right = maxPathSumHelper(root->right);
        if(left > 0 && right > 0){
            res = max(res,
                      max(left + root->val,
                          max(right + root->val,
                              max(left,
                                  max(right,left + right + root->val )))));
            // 比较 当前res 
            // 左树最大路径和加上当前节点值
            // 右树最大路径和加上当前节点值
            // 左树最大路径和
            // 右树最大路径和
            // 左树最大路径和加上左树最大路径加上当前节点值

            return max(left + root->val, right + root->val);

        }
        else if(left <= 0 && right > 0){
            res = max(res,
                      max(right,
                          max(right + root->val, root->val)));
            // 比较 当前res  
            // 右树最大路径和
            // 右树最大路径和加上当前节点值
            // 当前节点值
            return max(root->val, right + root->val);
        }
        else if(left > 0 && right <= 0){
            res = max(res,
                      max(left,
                          max(left + root->val, root->val)));
            // 比较 当前res  
            // 左树最大路径和
            // 左树最大路径和加上当前节点值
            // 当前节点值
            return max(left + root->val, root->val);
        }
        else{
            res = max(res, root->val);
            // 比较 当前res  
            // 当前节点值
            return  root->val;
        };
    }
};