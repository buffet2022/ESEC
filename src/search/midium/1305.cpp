// 1305. 两棵二叉搜索树中的所有元素
// 中等
// 相关标签
// 相关企业
// 提示
// 给你 root1 和 root2 这两棵二叉搜索树。请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.

 

// 示例 1：



// 输入：root1 = [2,1,4], root2 = [1,0,3]
// 输出：[0,1,1,2,3,4]
// 示例 2：



// 输入：root1 = [1,null,8], root2 = [8,1]
// 输出：[1,1,8,8]
 

// 提示：

// 每棵树的节点数在 [0, 5000] 范围内
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> stk1, stk2;
        while (root1 != nullptr || root2 != nullptr || !stk1.empty() || !stk2.empty()) {
            while (root1 != nullptr) {
                stk1.push(root1);
                root1 = root1->left;
            }
            while (root2 != nullptr) {
                stk2.push(root2);
                root2 = root2->left;
            }
            if (stk2.empty() || (!stk1.empty() && stk1.top()->val <= stk2.top()->val)) {
                root1 = stk1.top();
                stk1.pop();
                res.push_back(root1->val);
                root1 = root1->right;
            } else {
                root2 = stk2.top();
                stk2.pop();
                res.push_back(root2->val);
                root2 = root2->right;
            }
        }
        return res;
    }
};