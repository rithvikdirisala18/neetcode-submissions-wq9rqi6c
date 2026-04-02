class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size()-1]!=9){
            digits[digits.size()-1]+=1;
            return digits;
        }
        int index = digits.size()-1;
        while(index>=0 && digits[index]==9){
            digits[index] = 0;
            index--;
        }
        if(index==-1){
            vector<int>res (digits.size()+1, 0);
            res[0]++;
            return res;
        }
        else{
            digits[index]++;
            return digits;
        }
    }
};
