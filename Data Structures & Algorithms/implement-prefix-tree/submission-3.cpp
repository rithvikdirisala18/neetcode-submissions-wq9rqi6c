class TrieNode {
public:
    TrieNode* children[26];
    bool last;

    TrieNode(){
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
        last = false;
    }
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c: word){
            int ind = c-'a';
            if(curr->children[ind]==nullptr){
                curr->children[ind] = new TrieNode();
            }
            curr = curr->children[ind];
        }
        curr->last = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c: word){
            int ind = c-'a';
            if(curr->children[ind]==nullptr){
                return false;
            }
            curr = curr->children[ind];
        }
        return curr->last;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c: prefix){
            int ind = c-'a';
            if(curr->children[ind]==nullptr){
                return false;
            }
            curr = curr->children[ind];
        }
        return true;
    }
};
