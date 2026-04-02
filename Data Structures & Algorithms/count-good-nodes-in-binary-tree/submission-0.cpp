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
    void helper(int& ans, TreeNode* root, int greatest){
        if(!root) return;
        if(root->val>= greatest) ans++;
        helper(ans, root->right, max(greatest, root->val));
        helper(ans, root->left, max(greatest, root->val));
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        helper(ans, root, root->val);
        return ans;
    }
};
