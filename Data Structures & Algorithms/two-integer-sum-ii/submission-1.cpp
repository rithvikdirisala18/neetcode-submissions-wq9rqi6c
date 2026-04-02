class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        sort(numbers.begin(), numbers.end());
        for(int i = 0; i<numbers.size(); i++){
            for(int j = 0; j<i; j++){
                if(i==j){
                    break;
                }
                if(numbers[i]+numbers[j]==target){
                    return {j+1, i+1};
                }
            }
        }
        return {};
    }
};
