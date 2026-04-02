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
    pair<bool, int> help(TreeNode* rt){
        if(!rt) return {true, 0};

        pair<bool, int> l = help(rt->left);
        pair<bool, int> r = help(rt->right);

        bool accept = true;
        if(!l.first || !r.first || abs(l.second-r.second)>1){
            accept = false;
        }
        return {accept, max(l.second, r.second)+1};
    }
    bool isBalanced(TreeNode* root) {
        return help(root).first;
    }
};
