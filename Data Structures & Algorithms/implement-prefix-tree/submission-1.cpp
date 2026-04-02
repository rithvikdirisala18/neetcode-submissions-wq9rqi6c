class PrefixTree {
public:
    map<string, bool> prefixTr;
    map<string, bool> Full;
    PrefixTree() {

    }
    
    void insert(string word) {
        if(word.size()==0){
            prefixTr[""] = true;
        }
        for(int i = 1; i<=word.size(); i++){
            prefixTr[word.substr(0, i)] = true;
        }
        Full[word] = true;
    }
    
    bool search(string word) {
        return Full[word]==true;
    }
    
    bool startsWith(string prefix) {
        return prefixTr[prefix];
    }
};
