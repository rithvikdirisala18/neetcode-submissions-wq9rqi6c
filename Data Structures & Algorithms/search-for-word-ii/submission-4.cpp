class TrieNode {
public:
    TrieNode* children[26];
    bool end;
    string word;

    TrieNode() {
        end = false;
        word = "";
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

    void insert(const string& s) {
        TrieNode* curr = root;
        for (char c : s) {
            int ind = c - 'a';
            if (!curr->children[ind]) {
                curr->children[ind] = new TrieNode();
            }
            curr = curr->children[ind];
        }
        curr->end = true;
        curr->word = s;
    }

    void dfs(int x, int y, TrieNode* curr, vector<vector<char>>& board, vector<string>& res) {
        char c = board[x][y];
        if (c == '#') return;
        int ind = c - 'a';
        if (!curr->children[ind]) return;

        curr = curr->children[ind];
        if (curr->end) {
            res.push_back(curr->word);
            curr->end = false;
        }

        board[x][y] = '#';

        for (auto [dx, dy] : dir) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || ny < 0 || nx >= (int)board.size() || ny >= (int)board[0].size()) continue;
            if (board[nx][ny] == '#') continue;
            dfs(nx, ny, curr, board, res);
        }

        board[x][y] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto& w : words) {
            insert(w);
        }

        vector<string> res;
        int m = board.size();
        if (m == 0) return res;
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, root, board, res);
            }
        }

        return res;
    }
};

