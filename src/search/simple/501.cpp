// 501. 二叉搜索树中的众数
// 简单
// 相关标签
// 相关企业
// 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。

// 如果树中有不止一个众数，可以按 任意顺序 返回。

// 假定 BST 满足如下定义：

// 结点左子树中所含节点的值 小于等于 当前节点的值
// 结点右子树中所含节点的值 大于等于 当前节点的值
// 左子树和右子树都是二叉搜索树
 

// 示例 1：


// 输入：root = [1,null,2,2]
// 输出：[2]
// 示例 2：

// 输入：root = [0]
// 输出：[0]
 

// 提示：

// 树中节点的数目在范围 [1, 104] 内
// -105 <= Node.val <= 105
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
    void inorder(TreeNode* root, int& base, int& count, int& maxCount, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, base, count, maxCount, res);
        if (root->val == base) {
            count++;
        } else {
            base = root->val;
            count = 1;
        }
        if (count == maxCount) {
            res.push_back(base);
        } else if (count > maxCount) {
            maxCount = count;
            res = {base};
        }
        inorder(root->right, base, count, maxCount, res);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int base, count, maxCount;
        base = count = maxCount = 0;
        inorder(root, base, count, maxCount, res);
        return res;
    }
};