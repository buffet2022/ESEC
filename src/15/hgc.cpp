
class Solution {//递归
public:
    int helper(TreeNode*root){
        if(root==nullptr){
            return 0;
        }
        int leftdepth=helper(root->left);
        int rightdepth=helper(root->right);
        if(leftdepth>rightdepth){
            return leftdepth+1;
        }else{
            return rightdepth+1;
        }
    }
    int maxDepth(TreeNode* root) {
        return helper(root);
    }
};
