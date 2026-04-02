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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        unordered_set<int> lev;
        queue<pair<TreeNode*, int>> q;
        vector<int> ans;

        q.push({root, 0});
        
        while(!q.empty()){
            auto [nd, level] = q.front(); q.pop();
            if(!lev.count(level)){
                ans.push_back(nd->val);
                lev.insert(level);
            }
            if(nd->right) q.push({nd->right, level+1});
            if(nd->left) q.push({nd->left, level+1});
        }
        return ans;
    }
};
