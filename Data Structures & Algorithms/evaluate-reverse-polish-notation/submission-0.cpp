class Solution {
public:
    int eval(int first, int second, string op){
        if(op=="+"){
            return first+second;
        }
        else if(op=="-"){
            return first-second;
        }
        else if(op=="*"){
            return first*second;
        }
        else{
            return first/second;
        }
    }
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> st = {"+", "-", "*", "/"};
        stack<int> hold;
        for(const string& c: tokens){
            if(st.count(c)){
                int second = hold.top(); hold.pop();
                int first = hold.top(); hold.pop();
                hold.push(eval(first, second, c));
            }
            else{
                hold.push(stoi(c));
            }
        }
        return hold.top();
    }
};
