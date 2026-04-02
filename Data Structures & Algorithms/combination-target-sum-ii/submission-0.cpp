class Solution {
public:
    vector<vector<int>> res;

    void dfs(int ind, vector<int> path, int curr, vector<int>& cand, int t){
        if (curr==t){
            res.push_back(path);
            return;
        }
        for(int i = ind; i<cand.size(); i++){
            if(i > ind && cand[i]==cand[i-1]) continue;
            if(curr + cand[i]>t) break;

            path.push_back(cand[i]);
            dfs(i+1, path, curr+cand[i], cand, t);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        dfs(0, {}, 0, candidates, target);
        return res;
    }
};
