class Solution {
public:
    bool isValid(string s) {
        stack<char> tracker;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' ||s[i]=='['){
                tracker.push(s[i]);
            }
            else{
                if(tracker.size()==0){
                    return false;
                }
                if(s[i]==')'){
                    if(tracker.top()!='('){
                        return false;
                    }
                    else{
                        tracker.pop();
                    }
                }
                if(s[i]=='}'){
                    if(tracker.top()!='{'){
                        return false;
                    }
                    else{
                        tracker.pop();
                    }
                }
                if(s[i]==']'){
                    if(tracker.top()!='['){
                        return false;
                    }
                    else{
                        tracker.pop();
                    }
                }
            }
        }
        return tracker.size()==0;
    }
};
