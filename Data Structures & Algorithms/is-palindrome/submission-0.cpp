class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()<=1){
            return true;
        }
        int start = 0;
        int end = s.size()-1;
        while(start<end){
            while(!isalnum(s[start]) &&  start<end){
                start++;
            }
            while(!isalnum(s[end]) &&  start<end){
                end--;
            }
            if(tolower(s[start])!=tolower(s[end])){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
