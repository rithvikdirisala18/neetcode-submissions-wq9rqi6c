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
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* curr, int& res){
        if(!curr) return 0;

        int left = max(dfs(curr->left, res), 0);
        int right = max(dfs(curr->right, res), 0);
        res = max(res, left+right+curr->val);
        return curr->val+max(left, right);
    }
};
