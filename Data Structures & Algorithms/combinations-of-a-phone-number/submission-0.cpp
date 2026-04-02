class Solution {
public:
    unordered_map<char, vector<char>> mp = {{'2', {'A', 'B', 'C'}},
        {'3', {'D', 'E', 'F'}},
        {'4', {'G', 'H', 'I'}},
        {'5', {'J', 'K', 'L'}},
        {'6', {'M', 'N', 'O'}},
        {'7', {'P', 'Q', 'R', 's'}},
        {'8', {'T', 'U', 'V'}},
        {'9', {'W', 'X', 'Y', 'Z'}}
    };
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        vector<string> ans = {};
        dfs("", 0, digits, ans);
        return ans;
    }
    
    void dfs(string curr, int ind, string& dig, vector<string>& res){
        if(ind>=dig.size()){
            res.push_back(curr);
            return;
        }

        for(auto& c: mp[dig[ind]]){
            curr.push_back(tolower(c));
            dfs(curr, ind+1, dig, res);
            curr.pop_back();
        }
    }
};
