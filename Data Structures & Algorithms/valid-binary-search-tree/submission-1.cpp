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
    bool valid(TreeNode* nd, int l, int r){
        if(!nd) return true;
        if(!(l<nd->val && r>nd->val)) return false;
        return valid(nd->left, l, nd->val) && valid(nd->right, nd->val, r);
    }

    bool isValidBST(TreeNode* root) {
        return valid(root, INT_MIN, INT_MAX);
    }
};
