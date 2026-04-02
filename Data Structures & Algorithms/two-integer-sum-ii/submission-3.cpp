class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n-1;
        while(numbers[left]+numbers[right]!=target){
            if(numbers[left]+numbers[right]<target){
                left++;
            }
            else{
                right--;
            }
        }
        return {left+1, right+1};
    }
};
