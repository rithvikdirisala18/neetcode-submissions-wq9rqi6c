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
    void helper(TreeNode* n, vector<int>&t){
        if(!n) return;
        helper(n->left, t);
        t[0]--;
        if(t[0]==0){
            t[1] = n->val;
            return;
        }
        helper(n->right, t);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> t(2);
        t[0] = k;
        helper(root, t);
        return t[1];
    }
};
