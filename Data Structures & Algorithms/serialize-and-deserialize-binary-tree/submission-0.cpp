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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N";
        string res = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            if(!curr) {
                res+="N,";
            } else {
                res+= to_string(curr->val)+",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        if(val=="N") return nullptr;
        TreeNode* rt = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(rt);
        while(getline(ss, val, ',')){
            TreeNode* nd = q.front();
            q.pop();
            if(val!="N"){
                nd->left = new TreeNode(stoi(val));
                q.push(nd->left);
            }
            getline(ss, val, ',');
            if(val!="N"){
                nd->right = new TreeNode(stoi(val));
                q.push(nd->right);
            }
        }
        return rt;

    }
};
