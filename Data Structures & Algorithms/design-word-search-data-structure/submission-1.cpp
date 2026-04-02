class TrieNode {
public:
    TrieNode* children[26];
    bool last;

    TrieNode(){
        for(int i = 0; i<26; i++){
            children[i] = nullptr;
        }
        last = false;
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(auto& c: word){
            int ind = c-'a';
            if (curr->children[ind]==nullptr){
                curr->children[ind] = new TrieNode();
            }
            curr = curr->children[ind];
        }
        curr->last = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        return helper(word, 0, curr);
    }

    bool helper(string word, int ind, TrieNode* curr) {
        if(ind>=word.size()){
            return curr->last;
        }
        if(word[ind]=='.'){
            for(int i = 0; i<26; i++){
                if(curr->children[i] && helper(word, ind+1, curr->children[i])){
                    return true;
                }
            }
            return false;
        }
        if(curr->children[word[ind]-'a']==nullptr){
            return false;
        }
        return helper(word, ind+1, curr->children[word[ind]-'a']);
    }
};
