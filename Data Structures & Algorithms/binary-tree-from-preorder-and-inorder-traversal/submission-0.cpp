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
    unordered_map<int, int> ind;
    int pre_ind;
    TreeNode* dfs(vector<int>& preorder, int l, int r){
        if(l>r) return nullptr;
        int root_val = preorder[pre_ind];
        pre_ind++;
        TreeNode* rt = new TreeNode(root_val);
        int mid = ind[root_val];
        rt->left = dfs(preorder, l, mid-1);
        rt->right = dfs(preorder, mid+1, r);
        return rt;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        pre_ind = 0;
        for(int i = 0; i<n; i++){
            ind[inorder[i]] = i;
        }
        return dfs(preorder, 0, n-1);
    }
};
