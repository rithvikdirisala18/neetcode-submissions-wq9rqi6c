class Solution {
public:
    void helper(string& curr, int o, int c, int n, vector<string>& res){
        if(o==c && o==n){
            res.push_back(curr);
            return;
        }
        if(o<n){
            curr+="(";
            helper(curr, o+1, c, n, res);
            curr.pop_back();
        }
        if(c<o){
            curr+=")";
            helper(curr, o, c+1, n, res);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        helper(curr, 0, 0, n, res);
        return res;
    }
};
