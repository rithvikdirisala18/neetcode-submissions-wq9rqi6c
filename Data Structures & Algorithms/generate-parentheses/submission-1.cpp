class Solution {
public:
    vector<string> ans; 
    void helper(int l, int r, string curr, int n){
        if(l==n && r==n ){
            ans.push_back(curr);
            return;
        }
        if(l<n){
            curr.push_back('(');
            helper(l+1, r, curr, n);
            curr.pop_back();
        }
        if(l>r){
            curr.push_back(')');
            helper(l, r+1, curr, n);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
       helper(0, 0, "", n);
       return ans;
    }
};
