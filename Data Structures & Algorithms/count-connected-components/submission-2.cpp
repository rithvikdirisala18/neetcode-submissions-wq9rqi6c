class uf {
public:
    vector<int> rank;
    vector<int> par;

    uf(int n){
        rank.resize(n, 1);
        par.resize(n);

        for(int i = 0; i<n; i++)par[i] = i;
    }

    int find(int i){
        if(i!=par[i]){
            par[i] = find(par[i]);
        }
        return par[i];
    }

    bool uni(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px==py) return false;
        if(rank[py]>rank[px]) swap(px, py);
        par[py] = px;
        rank[px]+=rank[py];
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        uf u(n);
        int res = n;
        for(auto e: edges){
            if(u.uni(e[0], e[1])){
                res--;
            }
        }
        return res;
    }
};
