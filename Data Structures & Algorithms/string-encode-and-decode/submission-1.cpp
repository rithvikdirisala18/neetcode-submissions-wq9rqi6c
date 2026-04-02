class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto& s: strs){
            encoded+=to_string(s.size()) + "/" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i<s.size()){
            int j = i;
            while(s[i]!='/'){
                i++;
            }
            int len = stoi(s.substr(j, i-j));
            j = i+1;
            ans.push_back(s.substr(j, len));
            i = j+len;
        }
        return ans;
    }
};
