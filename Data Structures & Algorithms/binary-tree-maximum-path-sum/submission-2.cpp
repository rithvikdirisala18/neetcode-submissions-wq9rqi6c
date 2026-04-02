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
        int ans = root->val;
        dfs(root, ans);
        return ans;
    }
    
    int dfs(TreeNode* t, int& a){
        if(!t) return 0;
        int l = max(0, dfs(t->left, a));
        int r = max(0, dfs(t->right, a));
        a = max(a, t->val+l+r);
        return t->val+max(l, r);
    }
};
